/**
	@brief Implementation of PAFIExecutionEnvironment to work over diferents PROOF environments.
	@file PAFPROOFEnvironment.h
	@class PAFPROOFEnvironment
	@author I. Gonzalez Caballero, J. Delgado Fernandez
	@version 1.0
	@date 2014-12-04
*/

#pragma once

#include "PAFIExecutionEnvironment.h"

#include "TProof.h"
#include "proof_library_upload/PAFPROOFIUploadLibrary.h"

class PAFPROOFEnvironment : public PAFIExecutionEnvironment 
{
	public:
		PAFPROOFEnvironment();
		virtual ~PAFPROOFEnvironment();

		void Initialise();
		void Dispose();
		
		void AddInput(TObject* obj);
		void AddFeedback(const char* name);
		TDrawFeedback* CreateDrawFeedback();
		
		bool UploadPackage(PAFPackage* package);
		bool EnablePackage(PAFPackage* package);

		bool LoadLibrary(PAFLibrary* library);
		
		void Process(TFileCollection* dataFiles, PAFBaseSelector* selector);
		void Process(TFileCollection* dataFiles, PAFBaseSelector* selector, TString& outputFile);
		
		void SetPROOFUpload(PAFPROOFIUploadLibrary* proofUploadLibrary);
		PAFPROOFIUploadLibrary* GetPROOFUpload();

	protected:
		void InitMembers();
		virtual TProof* doCreateTProof() = 0;
		virtual void LoadPAF();
		void Process(TFileCollection* dataFiles, PAFBaseSelector* selector, const char* options);
		
	protected:
		TProof*			fSession;
		PAFPROOFIUploadLibrary*	fPROOFUploadLibrary;
};

