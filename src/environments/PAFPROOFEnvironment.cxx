/**
	@brief Implementation of PAFIExecutionEnvironment to work over diferents PROOF environments.
	@file PAFPROOFEnvironment.cxx
	@class PAFPROOFEnvironment
	@author I. Gonzalez Caballero, J. Delgado Fernandez
	@version 1.0
	@date 2014-12-04
*/

#include "PAFPROOFEnvironment.h"
#include "TString.h"

PAFPROOFEnvironment::~PAFPROOFEnvironment()
{
	delete fSession;
}

void PAFPROOFEnvironment::AddInput(TObject* obj)
{
	fSession->AddInputData(obj);
}

void PAFPROOFEnvironment::AddFeedback(const char* name)
{
	fSession->AddFeedback(name);
}

TDrawFeedback* PAFPROOFEnvironment::CreateDrawFeedback()
{
	return fSession->CreateDrawFeedback();
}

void PAFPROOFEnvironment::Process(TFileCollection* dataFiles, PAFBaseSelector* selector, TString& outputFile)
{		
	Process(dataFiles, selector, TString::Format("of=%s;stf", outputFile.Data()).Data());
}

void PAFPROOFEnvironment::Process(TFileCollection* dataFiles, PAFBaseSelector* selector)
{		
	fSession->Process(dataFiles, selector);
}

void PAFPROOFEnvironment::Process(TFileCollection* dataFiles, PAFBaseSelector* selector, const char* options)
{
	//FIXME Why is this throwing a "DataSet name is empty"?.
	fSession->Process(dataFiles, selector, options);
}

bool PAFPROOFEnvironment::UploadPackage(PAFPackage* package)
{
	return fSession->UploadPackage(package->GetParFileName(), TProof::kRemoveOld) == 0;
}

bool PAFPROOFEnvironment::EnablePackage(PAFPackage* package)
{
	return fSession->EnablePackage(package->GetName().Data()) == 0;
}

bool PAFPROOFEnvironment::LoadLibrary(PAFLibrary* library)
{
	TString loader = TString::Format("gSystem->Load(\"%s\");", library->GetFileName().Data()); //TODO Improve with a correct way to load libraries.
	gSystem->Load(library->GetFileName().Data());
	fSession->Exec(loader.Data());	

	return true;
}

void PAFPROOFEnvironment::LoadPAF()
{
	PAFLibrary* paf = new PAFLibrary("$PAFPATH/build/libPAF.so");
	LoadLibrary(paf);
	delete paf;
}

