/**
 * @brief Class to create a PAFProject which should be configured (although it has default values) and launched to get results. 
 * @file PAFProject.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2014-12-04
 */

#pragma once

#include "PAFAbstractProject.h"

#include "TDSet.h"
#include "TFileInfo.h"
#include "TFile.h"

/**
 * @class PAFProject
 * @brief Class to create a PAFProject which should be configured (although it has default values) and launched to get results. 
 */
class PAFProject : public PAFAbstractProject
{
	public:
		/**
		 * Create a PAFProject.
		 */
		PAFProject();
		
		/**
		 * Create a PAFProject.
		 * 
		 * @param executionEnvironment Execution environment to be used.
		 */
		PAFProject(PAFIExecutionEnvironment* executionEnvironment);
		
		/**
		 * Delete a PAFProject.
		 */
		virtual ~PAFProject();

		/**
		 * Set the default Tree name to analyse.
		 * 
		 * @param defaultTreeName Name of the default Tree name.
		 */
		void SetDefaultTreeName(TString& defaultTreeName);
		
		/**
		 * Set the default Tree name to analyse.
		 * 
		 * @param defaultTreeName Name of the default Tree name.
		 */
		void SetDefaultTreeName(const char* defaultTreeName);
		
		/**
		 * Return the default Tree name to analyse.
		 * 
		 * @return Name of the default Tree name.
		 */
		TString GetDefaultTreeName();

		/**
		 * Set the data files set to use during the analysis.
		 * 
		 * @param dataFiles TDSet object.
		 */
		void SetDataFiles(TDSet* dataFiles);
		
		/**
		 * Return the data files set.
		 * 
		 * @return The data set of files.
		 */
		TDSet* GetDataFiles();

		/**
		 * Add a file to the dataset of files that is going to be used in the analysis.
		 * 
		 * @param fileName Filaname of the file in the file system.
		 * @param objname Name of the Tree that is going to be processed.
		 */
		void AddDataFile(TString& fileName, TString& objname);
		
		/**
		 * Add a file to the dataset of files that is going to be used in the analysis.
		 * 
		 * @param fileName Filaname of the file in the file system.
		 * @param objname Name of the Tree that is going to be processed.
		 */
		void AddDataFile(const char* fileName, const char* objname = 0);
		
		
		/**
		 * Add a file to the dataset of files that is going to be used in the analysis using a TFileInfo object.
		 * 
		 * @param dataFile Datafile information to be added to the dataset of files.
		 */
		void AddDataFile(TFileInfo* dataFile);

		/**
		 * Set the first event that is going to be analysed. The first event consider that the TDSet has an order, commonly following the insertion order.
		 * 
		 * @param firstEvent Number of the first event that is going to be analysed (Inclusive)
		 */
		void SetFirstEvent(Long64_t firstEvent);
		
		/**
		 * Return the number of the first event that is going to be analysed.
		 * 
		 * @return Number of the event.
		 */
		Long64_t GetFirstEvent();

		/**
		 * Set the number of events to be analysed.
		 * 
		 * @param nEvents Number of events that are going to be analysed starting from property FirstEvent.
		 */
		void SetNEvents(Long64_t nEvents);
		
		/**
		 * Return the number of events that are going to be analysed.
		 * 
		 * @return Number of events that are going to be analysed starting from property FirstEvent.
		 */
		Long64_t GetNEvents();

		/**
		 * Execute the analysis using the given selector.
		 * 
		 * @param selector Selector to be used.
		 */
		virtual void doRun(PAFBaseSelector* selector);
		
		/**
		 * Executes the checks to verify if the project is ready to run.
		 */
		virtual void doProjectChecks();

	protected:
		/**
		 * Initialise the object.
		 */
		void InitMembers();

		/**
		 * Check if the given Tree does it exist in the rootFile.
		 * 
		 * @param rootFile ROOT file object.
		 * @param treeName Name of the Tree to look for.
		 */
		bool ExistsTree(TFile* rootFile, const char* treeName);
		
		/**
		 * Open a directory and look for all the posible trees recursively.
		 * 
		 * @param directory TDirectory where the search should be performed.
		 * @param resultTrees List of all the trees already found.
		 * @param path Current path where the method is looking for.
		 */
		void GetListOfTrees(TDirectory* directory, TList* resultTrees, const char* path);

		/**
		 * Return the directory path of a given path.
		 * 
		 * @param objName Complete path.
		 */
		virtual TString GetDirectoryFromObjName(TString& objName);
		
		/**
		 * Return the name of the item given a path.
		 * 
		 * @param objName Complete path.
		 */
		virtual TString GetNameFromObjName(TString& objName);

	protected:
		/**
		 * Set the data files set to use during the analysis.
		 */
		TDSet* fDataFiles;
		
		/**
		 * Number of the first event that is going to be analysed. The first event consider that the TDSet has an order, commonly following the insertion order.
		 */
		Long64_t fFirstEvent;
		
		/**
		 * Number of events that are going to be analysed starting from property FirstEvent.
		 */
		Long64_t fNEvents;

	ClassDef(PAFProject, 1);
};
