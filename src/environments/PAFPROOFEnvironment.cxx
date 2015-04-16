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

#include "proof_library_upload/PAFPROOFUploadLibraryTProofUpload.h"

#include "../settings/PAFEnvironmentVariableSettings.h"

PAFPROOFIUploadLibrary*	DEFAULT_PROOFUPLOADLIBRARY = new PAFPROOFUploadLibraryTProofUpload();

PAFPROOFEnvironment::PAFPROOFEnvironment()
{
	InitMembers();
}

PAFPROOFEnvironment::~PAFPROOFEnvironment()
{
	delete fSession;
}

void PAFPROOFEnvironment::InitMembers()
{
	fPROOFUploadLibrary = DEFAULT_PROOFUPLOADLIBRARY;
}

void PAFPROOFEnvironment::Initialise()
{
	fSession = doCreateTProof();
	fPROOFUploadLibrary->SetSession(fSession);
	LoadPAF();
}

void PAFPROOFEnvironment::Dispose()
{
	fSession->Close();
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
	fSession->Process(dataFiles, selector, options);
}

void PAFPROOFEnvironment::SetPROOFUpload(PAFPROOFIUploadLibrary* proofUploadLibrary)
{
	delete fPROOFUploadLibrary;
	fPROOFUploadLibrary = proofUploadLibrary;
}

PAFPROOFIUploadLibrary* PAFPROOFEnvironment::GetPROOFUpload()
{
	return fPROOFUploadLibrary;
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
	return fPROOFUploadLibrary->UploadLibrary(library);
}

void PAFPROOFEnvironment::LoadPAF()
{
	//FIXME This smells too bad.
	PAFISettings* settings = new PAFEnvironmentVariableSettings();
	
	fSession->Exec("TH1* th1 = 0"); //TODO Remove this trick. Needed in Ubuntu.
	PAFLibrary paf(settings, "$PAFPATH/lib/libPAF.so");
	LoadLibrary(&paf);
}


