/**
	@brief PAF tool executable that holds all paf tools.
	@file PAFTools.cxx
	@class PAFTools
	@author I. Gonzalez Caballero, J. Delgado Fernandez
	@version 1.0
	@date 2015-04-30
 */

#include "PAFTools.h"

#include "TObjString.h"

#include "PAFToolInspectTree.h"
#include "PAFToolReset.h"
#include "PAFToolCreateSelector.h"

#include "PAFExceptionCommandExpression.h"

#include <iostream>

int main(int argc, const char* argv[])
{
	PAFTools tools;

	tools.ExecuteTool(argc, argv);
}

const char* PAFTools::TOOL_NAME = "paf";

const char* PAFTools::HELP_MESSAGE = "paf tools launcher";

const char* PAFTools::COMMAND_EXPRESSION = "paf tool_name [tool_parameters]";


PAFTools::PAFTools()
	: PAFAbstractTool(TOOL_NAME, HELP_MESSAGE, COMMAND_EXPRESSION)
{
	InitMembers();
}

PAFTools::~PAFTools()
{
	
}

void PAFTools::InitMembers()
{
	InitTools();
}

void PAFTools::InitTools()
{
	PAFITool* inspectree = new PAFToolInspectTree();
	fTools[inspectree->GetToolName()] = inspectree;
	
	PAFITool* pafreset = new PAFToolReset();
	fTools[pafreset->GetToolName()] = pafreset;
	
	PAFITool* createselector = new PAFToolCreateSelector();
	fTools[createselector->GetToolName()] = createselector;
}

TString PAFTools::GetHelpMessage()
{
	TString result = "PAF tools currently available:\n";
	for (std::map<TString, PAFITool*>::iterator it = fTools.begin();
                it != fTools.end(); it++)
        {
                result.Append(TString::Format("\t%s\n", it->first.Data()));
        }
	return result;
}

void PAFTools::ExecuteTool(int argc, const char* argv[])
{
	TList params;
	for(int i = 1; i < argc; i++)
	{
		params.Add(new TObjString(argv[i]));
	}
	ExecuteTool(&params);
}

void PAFTools::ExecuteTool(TList* params)
{
	if(params->IsEmpty())
	{
		PrintMessage(GetCommandExpression());
		PrintMessage(GetHelpMessage());
		return;
	}

	TString* param0 = GetParam(params, 0);
	if(param0->EqualTo("-h") || param0->EqualTo("--help"))
	{
		PrintMessage(GetCommandExpression());
		PrintMessage(GetHelpMessage());
		return;
	}

	if(fTools.find(*param0) == fTools.end())
	{
		PrintMessage(TString::Format("Tool \"%s\" not found.\n", param0->Data()));
		return;
	}

	PAFITool* tool = fTools[*param0];
	if(params->GetSize() == 2)
	{
		TString* param1 = GetParam(params, 1);
		if (param1->EqualTo("-h") || param1->EqualTo("--help"))
		{
			PrintMessage(tool->GetHelpMessage());
			return;
		}
	}

	try
	{
		tool->ExecuteTool(params);
	}
	catch (PAFExceptionCommandExpression& ex)
	{
		PrintMessage(ex.GetMessage());
		PrintMessage("Command expression:");
		PrintMessage(tool->GetCommandExpression());
	}
}
