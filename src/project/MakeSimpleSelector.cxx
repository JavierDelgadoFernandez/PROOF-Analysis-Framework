#include "MakeSimpleSelector.h"
#include <string>


/************************
 *
 * Inherited from MakeSelector
 *
 ************************/
TString R__GetBranchPointerName(TLeaf *leaf)
{
   // Return the name of the branch pointer needed by MakeClass/MakeSelector

   TLeaf *leafcount = leaf->GetLeafCount();
   TBranch *branch = leaf->GetBranch();

   TString branchname( branch->GetName() );

   if ( branch->GetNleaves() <= 1 ) {
       if (branch->IsA() != TBranchObject::Class()) {
         if (!leafcount) {
            TBranch *mother = branch->GetMother();
            const char* ltitle = leaf->GetTitle();
            if (mother && mother!=branch) {
               branchname = mother->GetName();
               if (branchname[branchname.Length()-1]!='.') {
                  branchname += ".";
               }
               if (strncmp(branchname.Data(),ltitle,branchname.Length())==0) {
                  branchname = "";
               }
            } else {
               branchname = "";
            }
            branchname += ltitle;
         }
      }
   }
   char *bname = (char*)branchname.Data();
   char *twodim = (char*)strstr(bname,"[");
   if (twodim) *twodim = 0;
   while (*bname) {
      if (*bname == '.') *bname='_';
      if (*bname == ',') *bname='_';
      if (*bname == ':') *bname='_';
      if (*bname == '<') *bname='_';
      if (*bname == '>') *bname='_';
      bname++;
   }
#if (DEBUG >= 2 )
   cerr << PAFDEBUG << "branchname = " << branchname << endl;
#endif
   return branchname;
}

/************************
 *
 * Almost completely copied from MakeSelector
 *
 ************************/
int MakeSimpleSelector(TTree* fTree, 
		       FILE *fp,
		       const char *classname) {
  // Generate skeleton analysis class for this Tree.
  //
  // The following files are produced: classname.h and classname.C
  // If classname is 0, classname will be called "nameoftree.
  //
  // The generated code in classname.h includes the following:
  //    - Identification of the original Tree and Input file name
  //    - Definition of analysis class (data and functions)
  //    - the following class functions:
  //       - constructor (connecting by default the Tree file)
  //       - GetEntry(Long64_t entry)
  //       - Init(TTree *tree) to initialize a new TTree
  //       - Show(Long64_t entry) to read and Dump entry
  //
  // The generated code in classname.C includes only the main
  // analysis function Loop.
  //
  // To use this function:
  //    - connect your Tree file (eg: TFile f("myfile.root");)
  //    - T->MakeClass("MyClass");
  // where T is the name of the Tree in file myfile.root
  // and MyClass.h, MyClass.C the name of the files created by this function.
  // In a ROOT session, you can do:
  //    root > .L MyClass.C
  //    root > MyClass t
  //    root > t.GetEntry(12); // Fill t data members with entry number 12
  //    root > t.Show();       // Show values of entry 12
  //    root > t.Show(16);     // Read and show values of entry 16
  //    root > t.Loop();       // Loop on all entries
  //
  //  NOTE: Do not use the code generated for one Tree in case of a TChain.
  //        Maximum dimensions calculated on the basis of one TTree only
  //        might be too small when processing all the TTrees in one TChain.
  //        Instead of myTree.MakeClass(..,  use myChain.MakeClass(..

  //TString thead;
  // thead.Form("%s/%s.h", path, classname);
   //FILE *fp = fopen(thead, "w");
   if (!fp) {
      return 3;
   }
   TString treefile;
   if (fTree->GetDirectory() && fTree->GetDirectory()->GetFile()) {
      treefile = fTree->GetDirectory()->GetFile()->GetName();
   } else {
      treefile = "Memory Directory";
   }
   // In the case of a chain, the GetDirectory information usually does
   // pertain to the Chain itself but to the currently loaded tree.
   // So we can not rely on it.
   Bool_t ischain = fTree->InheritsFrom("TChain");
   Bool_t isHbook = fTree->InheritsFrom("THbookTree");
   if (isHbook)
      treefile = fTree->GetTitle();

//======================Generate classname.h=====================
   // Print header
   TObjArray *leaves = fTree->GetListOfLeaves();
   Int_t nleaves = leaves ? leaves->GetEntriesFast() : 0;
   fprintf(fp,"//////////////////////////////////////////////////////////\n");
   fprintf(fp,"// This class has been automatically generated\n");
   fprintf(fp,"// by ROOT version %s\n",gROOT->GetVersion());
   fprintf(fp,"// using a modified version of MakeSelector\n");
   if (!ischain) {
      fprintf(fp,"// from TTree %s/%s\n",fTree->GetName(),fTree->GetTitle());
      fprintf(fp,"// found on file: %s\n",treefile.Data());
   } else {
      fprintf(fp,"// from TChain %s/%s\n",fTree->GetName(),fTree->GetTitle());
   }
   fprintf(fp,"//////////////////////////////////////////////////////////\n");
   fprintf(fp,"\n");
   fprintf(fp,"#ifndef %s_h\n",classname);
   fprintf(fp,"#define %s_h\n",classname);
   fprintf(fp,"\n");
   fprintf(fp,"#include <TROOT.h>\n");
   fprintf(fp,"#include <TChain.h>\n");

   if (isHbook) fprintf(fp,"#include <THbookFile.h>\n");
   fprintf(fp,"#include \"../PAF/computing/PAFBaseSelector.h\"\n"); //TODO This should be solved

// First loop on all leaves to generate dimension declarations
   Int_t len, lenb,l;
   char blen[1024];
   char *bname;
   Int_t *leaflen = new Int_t[nleaves];
   TObjArray *leafs = new TObjArray(nleaves);
   for (l=0;l<nleaves;l++) {
      TLeaf *leaf = (TLeaf*)leaves->UncheckedAt(l);
      leafs->AddAt(new TObjString(leaf->GetName()),l);
      leaflen[l] = leaf->GetMaximum();
   }
   if (ischain) {
      // In case of a chain, one must find the maximum dimension of each leaf
      // One must be careful and not assume that all Trees in the chain
      // have the same leaves and in the same order!
      TChain *chain = (TChain*)fTree;
      Int_t ntrees = chain->GetNtrees();
      for (Int_t file=0;file<ntrees;file++) {
         Long64_t first = chain->GetTreeOffset()[file];
         chain->LoadTree(first);
         for (l=0;l<nleaves;l++) {
            TObjString *obj = (TObjString*)leafs->At(l);
            TLeaf *leaf = chain->GetLeaf(obj->GetName());
            if (leaf) {
               leaflen[l] = TMath::Max(leaflen[l],leaf->GetMaximum());
            }
         }
      }
      chain->LoadTree(0);
   }

   leaves = fTree->GetListOfLeaves();
   for (l=0;l<nleaves;l++) {
      TLeaf *leaf = (TLeaf*)leaves->UncheckedAt(l);
      strcpy(blen,leaf->GetName());
      bname = &blen[0];
      while (*bname) {
         if (*bname == '.') *bname='_';
         if (*bname == ',') *bname='_';
         if (*bname == ':') *bname='_';
         if (*bname == '<') *bname='_';
         if (*bname == '>') *bname='_';
         bname++;
      }
      lenb = strlen(blen);
      if (blen[lenb-1] == '_') {
         blen[lenb-1] = 0;
         len = leaflen[l];
         if (len <= 0) len = 1;
         fprintf(fp,"   const Int_t kMax%s = %d;\n",blen,len);
      }
   }
   delete [] leaflen;
   leafs->Delete();
   delete leafs;

// second loop on all leaves to generate type declarations
   fprintf(fp,"\n");
   fprintf(fp,"using namespace std;");
   fprintf(fp,"\n");
   fprintf(fp,"class %s : public PAFBaseSelector {\n",classname);
   fprintf(fp,"public :\n");
   fprintf(fp,"\n   // Declaration of leaf types\n");
   TLeaf *leafcount;
   TLeafObject *leafobj;
   TBranchElement *bre=0;
   const char *headOK  = "   ";
   const char *headcom = " //";
   const char *head;
   char branchname[1024];
   char aprefix[1024];
   TObjArray branches(100);
   TObjArray mustInit(100);
   TObjArray mustInitArr(100);
   mustInitArr.SetOwner(kFALSE);
   Int_t *leafStatus = new Int_t[nleaves];
   for (l=0;l<nleaves;l++) {
      Int_t kmax = 0;
      head = headOK;
      leafStatus[l] = 0;
      TLeaf *leaf = (TLeaf*)leaves->UncheckedAt(l);
      len = leaf->GetLen(); if (len<=0) len = 1;
      leafcount =leaf->GetLeafCount();
      TBranch *branch = leaf->GetBranch();
      branchname[0] = 0;
      strcpy(branchname,branch->GetName());
      strcpy(aprefix,branch->GetName());
      if (!branches.FindObject(branch)) branches.Add(branch);
      else leafStatus[l] = 1;
      if ( branch->GetNleaves() > 1) {
         // More than one leaf for the branch we need to distinguish them
         strcat(branchname,".");
         strcat(branchname,leaf->GetTitle());
         if (leafcount) {
            // remove any dimension in title
            char *dim =  (char*)strstr(branchname,"["); if (dim) dim[0] = 0;
         }
      } else {
         strcpy(branchname,branch->GetName());
      }
      char *twodim = (char*)strstr(leaf->GetTitle(),"][");
      bname = branchname;
      while (*bname) {
         if (*bname == '.') *bname='_';
         if (*bname == ',') *bname='_';
         if (*bname == ':') *bname='_';
         if (*bname == '<') *bname='_';
         if (*bname == '>') *bname='_';
         bname++;
      }
      if (branch->IsA() == TBranchObject::Class()) {
         if (branch->GetListOfBranches()->GetEntriesFast()) {leafStatus[l] = 1; continue;}
         leafobj = (TLeafObject*)leaf;
         if (!leafobj->GetClass()) {leafStatus[l] = 1; head = headcom;}
         fprintf(fp,"%s%-15s *%s;\n",head,leafobj->GetTypeName(), leafobj->GetName());
         if (leafStatus[l] == 0) mustInit.Add(leafobj);
         continue;
      }
      if (leafcount) {
         len = leafcount->GetMaximum();
         if (len<=0) len = 1;
         strcpy(blen,leafcount->GetName());
         bname = &blen[0];
         while (*bname) {
            if (*bname == '.') *bname='_';
            if (*bname == ',') *bname='_';
            if (*bname == ':') *bname='_';
            if (*bname == '<') *bname='_';
            if (*bname == '>') *bname='_';
            bname++;
         }
         lenb = strlen(blen);
         if (blen[lenb-1] == '_') {blen[lenb-1] = 0; kmax = 1;}
         else                     sprintf(blen,"%d",len);
      }
      if (branch->IsA() == TBranchElement::Class()) {
         bre = (TBranchElement*)branch;
         if (bre->GetType() != 3 && bre->GetType() != 4
             && bre->GetStreamerType() <= 0 && bre->GetListOfBranches()->GetEntriesFast()) {
            leafStatus[l] = 0;
         }
         if (bre->GetType() == 3 || bre->GetType() == 4) {
            fprintf(fp,"   %-15s %s_;\n","Int_t", branchname);
            continue;
         }
         if (bre->IsBranchFolder()) {
            fprintf(fp,"   %-15s *%s;\n",bre->GetClassName(), branchname);
            mustInit.Add(bre);
            continue;
         } else {
            if (branch->GetListOfBranches()->GetEntriesFast()) {leafStatus[l] = 1;}
         }
         if (bre->GetStreamerType() < 0) {
	   ///////////////////////////////////////////////////////////////////
	   // FIX: Added by I.G. to fix a problem with branches having invalid
	   // symbols in their names
	   char strbrenamec[256];
	   strcpy(strbrenamec, bre->GetName());
	   char* strbrename = &strbrenamec[0];
	   while (*strbrename) {
	     if (*strbrename == '.') *strbrename='_';
	     if (*strbrename == ',') *strbrename='_';
	     if (*strbrename == ':') *strbrename='_';
	     if (*strbrename == '<') *strbrename='_';
	     if (*strbrename == '>') *strbrename='_';
	     strbrename++;
	   }
	   //
	   //////////////////////////////////////////////////////////////////

	   if (branch->GetListOfBranches()->GetEntriesFast()) {
	     fprintf(fp,"%s%-15s *%s;\n",headcom,bre->GetClassName(), strbrenamec);
	   } else {
	     fprintf(fp,"%s%-15s *%s;\n",head,bre->GetClassName(), strbrenamec);
	     mustInit.Add(bre);
	   }
	   continue;
         }
         if (bre->GetStreamerType() == 0) {
            if (!TClass::GetClass(bre->GetClassName())->GetClassInfo()) {leafStatus[l] = 1; head = headcom;}
            fprintf(fp,"%s%-15s *%s;\n",head,bre->GetClassName(), bre->GetName());
            if (leafStatus[l] == 0) mustInit.Add(bre);
            continue;
         }
         if (bre->GetStreamerType() > 60) {
            TClass *cle = TClass::GetClass(bre->GetClassName());
            if (!cle) {leafStatus[l] = 1; continue;}
            if (bre->GetStreamerType() == 66) leafStatus[l] = 0;
            char brename[256];
            strcpy(brename,bre->GetName());
            char *bren = brename;
            char *adot = strrchr(bren,'.');
            if (adot) bren = adot+1;
            char *brack = strchr(bren,'[');
            if (brack) *brack = 0;
            TStreamerElement *elem = (TStreamerElement*)cle->GetStreamerInfo()->GetElements()->FindObject(bren);
            if (elem) {
               if (elem->IsA() == TStreamerBase::Class()) {leafStatus[l] = 1; continue;}
               if (!TClass::GetClass(elem->GetTypeName())) {leafStatus[l] = 1; continue;}
               if (!TClass::GetClass(elem->GetTypeName())->GetClassInfo()) {leafStatus[l] = 1; head = headcom;}
               if (leafcount) fprintf(fp,"%s%-15s %s[kMax%s];\n",head,elem->GetTypeName(), branchname,blen);
               else           fprintf(fp,"%s%-15s %s;\n",head,elem->GetTypeName(), branchname);
            } else {
               if (!TClass::GetClass(bre->GetClassName())->GetClassInfo()) {leafStatus[l] = 1; head = headcom;}
               fprintf(fp,"%s%-15s %s;\n",head,bre->GetClassName(), branchname);
            }
            continue;
         }
      }
      if (strlen(leaf->GetTypeName()) == 0) {leafStatus[l] = 1; continue;}
      if (leafcount) {
         //len = leafcount->GetMaximum();
         //strcpy(blen,leafcount->GetName());
         //bname = &blen[0];
         //while (*bname) {if (*bname == '.') *bname='_'; bname++;}
         //lenb = strlen(blen);
         //Int_t kmax = 0;
         //if (blen[lenb-1] == '_') {blen[lenb-1] = 0; kmax = 1;}
         //else                     sprintf(blen,"%d",len);

         const char *stars = " ";
         if (bre && bre->GetBranchCount2()) {
            stars = "*";
         }
         // Dimensions can be in the branchname for a split Object with a fix length C array.
         // Theses dimensions HAVE TO be placed after the dimension explicited by leafcount
         char *dimensions = 0;
         char *dimInName = (char*) strstr(branchname,"[");
         if ( twodim || dimInName ) {
            int dimlen = 0;
            if (dimInName) dimlen += strlen(dimInName) + 1;
            if (twodim)    dimlen += strlen(twodim) + 1;
            dimensions = new char[dimlen];
            if (dimInName) {
               strcpy(dimensions,dimInName);
               dimInName[0] = 0; // terminate branchname before the array dimensions.
            } else dimensions[0] = 0;
            if (twodim) strcat(dimensions,(char*)(twodim+1));
         }
         const char* leafcountName = leafcount->GetName();
         char b2len[1024];
         if (bre && bre->GetBranchCount2()) {
            TLeaf * l2 = (TLeaf*)bre->GetBranchCount2()->GetListOfLeaves()->At(0);
            strcpy(b2len,l2->GetName());
            bname = &b2len[0];
            while (*bname) {
               if (*bname == '.') *bname='_';
               if (*bname == ',') *bname='_';
               if (*bname == ':') *bname='_';
               if (*bname == '<') *bname='_';
               if (*bname == '>') *bname='_';
               bname++;
            }
            leafcountName = b2len;
         }
         if (dimensions) {
            if (kmax) fprintf(fp,"   %-14s %s%s[kMax%s]%s;   //[%s]\n",leaf->GetTypeName(), stars,
                              branchname,blen,dimensions,leafcountName);
            else      fprintf(fp,"   %-14s %s%s[%d]%s;   //[%s]\n",leaf->GetTypeName(), stars,
                              branchname,len,dimensions,leafcountName);
            delete [] dimensions;
         } else {
            if (kmax) fprintf(fp,"   %-14s %s%s[kMax%s];   //[%s]\n",leaf->GetTypeName(), stars, branchname,blen,leafcountName);
            else      fprintf(fp,"   %-14s %s%s[%d];   //[%s]\n",leaf->GetTypeName(), stars, branchname,len,leafcountName);
         }
         if (stars[0]=='*') {
            TNamed *n;
            if (kmax) n = new TNamed(branchname, Form("kMax%s",blen));
            else n = new TNamed(branchname, Form("%d",len));
            mustInitArr.Add(n);
         }
      } else {
         if (strstr(branchname,"[")) len = 1;
         if (len < 2) fprintf(fp,"   %-15s %s;\n",leaf->GetTypeName(), branchname);
         else {
            if (twodim) fprintf(fp,"   %-15s %s%s;\n",leaf->GetTypeName(), branchname,(char*)strstr(leaf->GetTitle(),"["));
            else        fprintf(fp,"   %-15s %s[%d];\n",leaf->GetTypeName(), branchname,len);
         }
      }
   }

// generate list of branches
   fprintf(fp,"\n");
   fprintf(fp,"   // List of branches\n");
   for (l=0;l<nleaves;l++) {
      if (leafStatus[l]) continue;
      TLeaf *leaf = (TLeaf*)leaves->UncheckedAt(l);
      fprintf(fp,"   TBranch        *b_%s;   //!\n",R__GetBranchPointerName(leaf).Data());
   }

// generate class member functions prototypes
   fprintf(fp,"\n");
   fprintf(fp,"   %s(TTree * /*tree*/ =0) { }\n",classname) ;
   fprintf(fp,"   virtual ~%s() { }\n",classname);
   fprintf(fp,"   virtual void    Init(TTree *tree);\n");
   fprintf(fp,"   ClassDef(%s,0);\n",classname);
   fprintf(fp,"};\n");
   fprintf(fp,"\n");
   fprintf(fp,"#endif\n");
   fprintf(fp,"\n");

// generate code for class constructor
   fprintf(fp,"#ifdef %s_cxx\n",classname);

// generate code for class destructor()
// generate code for class member function GetEntry()
// generate code for class member function LoadTree()
// generate code for class member function Init(), first pass = get branch pointer
   fprintf(fp,"void %s::Init(TTree *tree)\n",classname);
   fprintf(fp,"{\n");
   fprintf(fp,"   // The Init() function is called when the selector needs to initialize\n"
              "   // a new tree or chain. Typically here the branch addresses and branch\n"
              "   // pointers of the tree will be set.\n"
              "   // It is normally not necessary to make changes to the generated\n"
              "   // code, but the routine can be extended by the user if needed.\n"
              "   // Init() will be called many times when running on PROOF\n"
              "   // (once per file to be processed).\n\n");
   if (mustInit.Last()) {
      TIter next(&mustInit);
      TObject *obj;
      fprintf(fp,"   // Set object pointer\n");
      while( (obj = next()) ) {
         if (obj->InheritsFrom(TBranch::Class())) {
            strcpy(branchname,((TBranch*)obj)->GetName() );
         } else if (obj->InheritsFrom(TLeaf::Class())) {
            strcpy(branchname,((TLeaf*)obj)->GetName() );
         }
         bname = branchname;
         while (*bname) {
            if (*bname == '.') *bname='_';
            if (*bname == ',') *bname='_';
            if (*bname == ':') *bname='_';
            if (*bname == '<') *bname='_';
            if (*bname == '>') *bname='_';
            bname++;
         }
         fprintf(fp,"   %s = 0;\n",branchname );
      }
   }
   if (mustInitArr.Last()) {
      TIter next(&mustInitArr);
      TNamed *info;
      fprintf(fp,"   // Set array pointer\n");
      while( (info = (TNamed*)next()) ) {
         fprintf(fp,"   for(int i=0; i<%s; ++i) %s[i] = 0;\n",info->GetTitle(),info->GetName());
      }
      fprintf(fp,"\n");
   }
   fprintf(fp,"   // Set branch addresses and branch pointers\n");
   fprintf(fp,"   if (!tree) return;\n");
   fprintf(fp,"   fChain = tree;\n");
   fprintf(fp,"   fChain->SetMakeClass(1);\n");
   fprintf(fp,"\n");
   for (l=0;l<nleaves;l++) {
      if (leafStatus[l]) continue;
      //cerr << PAFDEBUG << "1" << endl;
      TLeaf *leaf = (TLeaf*)leaves->UncheckedAt(l);
      //cerr << PAFDEBUG << "2" << endl;
      len = leaf->GetLen();
      //cerr << PAFDEBUG << "3" << endl;
      leafcount =leaf->GetLeafCount();
      //cerr << PAFDEBUG << "4" << endl;
      TBranch *branch = leaf->GetBranch();
      //cerr << PAFDEBUG << "5" << endl;
      strcpy(aprefix,branch->GetName());

      if ( branch->GetNleaves() > 1) {
         // More than one leaf for the branch we need to distinguish them
         strcpy(branchname,branch->GetName());
         strcat(branchname,".");
         strcat(branchname,leaf->GetTitle());
         if (leafcount) {
            // remove any dimension in title
            char *dim =  (char*)strstr(branchname,"["); if (dim) dim[0] = 0;
         }
      } else {
         strcpy(branchname,branch->GetName());
         if (branch->IsA() == TBranchElement::Class()) {
            bre = (TBranchElement*)branch;
            if (bre->GetType() == 3 || bre->GetType()==4) 
	      strcat(branchname,"_");
         }
      }
      bname = branchname;
      char *brak = strstr(branchname,"[");     
      if (brak) 
	*brak = 0;
      char *twodim = (char*)strstr(bname,"["); 
      if (twodim) 
	*twodim = 0;
      while (*bname) {
         if (*bname == '.') *bname='_';
         if (*bname == ',') *bname='_';
         if (*bname == ':') *bname='_';
         if (*bname == '<') *bname='_';
         if (*bname == '>') *bname='_';
         bname++;
      }
      if (branch->IsA() == TBranchObject::Class()) {
	if (branch->GetListOfBranches()->GetEntriesFast()) {
	  fprintf(fp,"   fChain->SetBranchAddress(\"%s\",(void*)-1,&b_%s);\n",branch->GetName(),R__GetBranchPointerName(leaf).Data());
	  continue;
	}
	strcpy(branchname,branch->GetName());
      }

      if (branch->IsA() == TBranchElement::Class()) {
	if (((TBranchElement*)branch)->GetType() == 3) 
	  len =1;
	if (((TBranchElement*)branch)->GetType() == 4) 
	  len =1;
      }

      
      if (leafcount) 
	len = leafcount->GetMaximum()+1;

      
      if (len > 1) {
	fprintf(fp,"   fChain->SetBranchAddress(\"%s\", %s, &b_%s);\n",
		branch->GetName(), branchname, R__GetBranchPointerName(leaf).Data());
      }
      else {
	fprintf(fp,"   fChain->SetBranchAddress(\"%s\", &%s, &b_%s);\n",
		branch->GetName(), branchname, R__GetBranchPointerName(leaf).Data());
      }
      // XXX really?
      // This does nothing... but if I don't add this, the interpreter goes 
      // nuts
      // cerr << "";
   }

   fprintf(fp,"}\n");
   fprintf(fp,"\n");

// generate code for class member function Notify()

// generate code for class member function Show()
// generate code for class member function Cut()
   fprintf(fp,"#endif // #ifdef %s_cxx\n",classname);



   delete [] leafStatus;
   fclose(fp);

   return 0;
}

void MakeSimpleSelectorC(FILE* file)
{
  fprintf(file,"/////////////////////////////////////////////////////////////////////\n"
             "//\n"
             "//    FILE: PAFAnalysis.C\n"
             "//   CLASS: PAFAnalysis\n"
             "// AUTHORS: I. Gonzalez Caballero, A.Y. Rodriguez Marrero\n"
             "//    DATE: 2012\n"
             "//\n"
             "// Note: This file is automatically generated by PAF\n"
             "/////////////////////////////////////////////////////////////////////\n"
             "\n"
             "#define PAFAnalysis_cxx\n"
             "\n"
             "#include \"PAFAnalysis.h\"\n"
			 "ClassImp(PAFAnalysis);\n");
  fclose(file);
}

int MakeSimpleSelector(TTree* fTree, const char* fileName)
{
	std::string sFileName = fileName;
	
	FILE* resultC = fopen((sFileName + "PAFAnalysis.C").c_str(), "w");
	MakeSimpleSelectorC(resultC);

	FILE* result = fopen((sFileName + "PAFAnalysis.h").c_str(),  "w");
	return MakeSimpleSelector(fTree, result, "PAFAnalysis");
}