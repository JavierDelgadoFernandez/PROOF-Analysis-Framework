#include "PAFPROOFUploadLibraryAbstract.h"

PAFPROOFUploadLibraryAbstract::PAFPROOFUploadLibraryAbstract()
	: fSession(0)
{

}

PAFPROOFUploadLibraryAbstract::~PAFPROOFUploadLibraryAbstract()
{

}

TProof* PAFPROOFUploadLibraryAbstract::GetSession()
{
	return fSession;
}

void PAFPROOFUploadLibraryAbstract::SetSession(TProof* session)
{
	fSession = session;
}
