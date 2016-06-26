/**
 * @brief PAF tool class to show information about ROOT files.
 * @file PAFToolInspectTree.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2015-04-30
 */

#pragma once

#include "PAFAbstractTool.h"

#include "TFile.h"
#include "TTree.h"

/**
 * @class PAFToolInspectTree
 * @brief PAF tool class to show information about ROOT files.
 */
class PAFToolInspectTree : public PAFAbstractTool
{
	public:
		/**
		 * Create a PAFToolInspectTree.
		 */
		PAFToolInspectTree();
		
		/**
		 * Delete a PAFToolInspectTree.
		 */
		virtual ~PAFToolInspectTree();

		/**
		 * Execute the concrete tool.
		 * 
		 * @param params The list of input parameters.
		 */
		virtual void ExecuteTool(TList* params);

	protected:
		/**
		 * Print the description of a variable.
		 * 
		 * @param desc Description of the variable.
		 */
		void PrintDescription(const char* desc);
		
		/**
		 * Print a variable using its name and its type.
		 * 
		 * @param type Type of the variable.
		 * @param name Name of the variable.
		 */
		void PrintVariable(const char* type, const char* name);

		/**
		 * Print the snippet of code needed in order to use that variable in a selector.
		 */
		void PrintSnippet(const char* type, const char* name);
		
		/**
		 * Print all the variables contained in a given branchName of a Tree.
		 * 
		 * @param tree Tree to analyse.
		 * @param branchName Name of the branch to analyse.
		 * @param snippet Specify if the output should show a snippet.
		 */
		void PrintVariables(TTree* tree, TString* branchName, bool snippet);

		
		/**
		 * Open a ROOT file and return the tree with the given name.
		 * 
		 * @param rootFile ROOT file where the search should look for the Tree.
		 * @param treeName Name of the tree that the tool should look for.
		 * @return Tree object if found, otherwise NULL.
		 */
		TTree* GetTree(TFile* rootFile, TString* treeName);
		
		/**
		 * Open a ROOT file an return the default Tree which could be:
		 * If there is only one, it will return that one.
		 * If there is more than one, it will return the one with the name "Tree"
		 * Otherwise, it will print the name of all trees.
		 * 
		 * @param rootFile ROOT file where the search should look for the Tree.
		 * @return Default Tree or NULL.
		 */
		TTree* GetAutoTree(TFile* rootFile);
		
		/**
		 * Open a directory and look for all the posible trees recursively.
		 * 
		 * @param directory TDirectory where the search should be performed.
		 * @param resultTrees List of all the trees already found.
		 * @param path Current path where the method is looking for.
		 */
		void GetListOfTrees(TDirectory* directory, TList* resultTrees, const char* path);

		/**
		 * Name of the tool.
		 */
		static const char* TOOL_NAME;
		
		/**
		 * Message to be used as help.
		 */
		static const char* HELP_MESSAGE;
		
		/**
		 * Example of expression to use the tool.
		 */
		static const char* COMMAND_EXPRESSION;

};
