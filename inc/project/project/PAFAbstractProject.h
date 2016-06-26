/**
 * @brief Abstract class with common funcionality of different PAFIProjects.
 * @file PAFAbstractProject.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2015-04-18
 */

#pragma once

#include <vector>

#include "TString.h"

#include "PAFISettings.h"
#include "PAFIExecutionEnvironment.h"
#include "PAFPackage.h"
#include "PAFPackageSelector.h"
#include "PAFLibrary.h"
#include "PAFISelector.h"
#include "PAFChainSelector.h"
#include "PAFChainItemSelector.h"
#include "PAFBaseSelector.h"
#include "PAFVariableContainer.h"
#include "PAFIProgressUpdated.h"

/**
 * @class PAFAbstractProject
 * @brief Abstract class with common funcionality of different PAFIProjects.
 */
class PAFAbstractProject 
{
	public:
		/**
		 * Create a PAFAbstractProject.
		 */
		PAFAbstractProject();
		
		/**
		 * Create a PAFAbstractProject.
		 * 
		 * @param executionEnvironment Execution environment to be used.
		 */
		PAFAbstractProject(PAFIExecutionEnvironment* executionEnvironment);
		
		/**
		 * Delete a PAFAbstractProject.
		 */
		virtual ~PAFAbstractProject();

		/**
		 * Set the ExectutionEnvironment to be used.
		 * 
		 * @param ExectutionEnvironment ExectutionEnvironment to use.
		 */
		void SetExecutionEnvironment(PAFIExecutionEnvironment* executionEnvironment);
		
		/**
		 * Return the ExecutionEnvironment.
		 * 
		 * @return ExecutionEnvironment object.
		 */
		PAFIExecutionEnvironment* GetExecutionEnvironment();

		/**
		 * Set the list of packages to use.
		 * 
		 * @param packages std::vector with the list of packages to use.
		 */
		void SetPackages(std::vector<PAFPackage*>* packages);
		
		/**
		 * Return the list of packages to use.
		 * 
		 * @return std::vector with the list of packages to use.
		 */
		std::vector<PAFPackage*>* GetPackages();
		
		/**
		 * Add a package to the list of packages.
		 * 
		 * @param packageName Name of the package.
		 */
		void AddPackage(TString& packageName);
		
		/**
		 * Add a package to the list of packages.
		 * 
		 * @param packageName Name of the package.
		 */
		void AddPackage(const char* packageName);
		
		/**
		 * Add a package to the list of packages using a PAFPackage object.
		 * 
		 * @param package Package object to be added.
		 */
		void AddPackage(PAFPackage* package);

		/**
		 * Set the list of the selectors that are going to be used.
		 * 
		 * @param selectorPackages List of the packages to use.
		 */
		void SetSelectorPackages(std::vector<PAFPackageSelector*>* selectorPackages);
		
		/**
		 * Return the list of the selectors packages.
		 * 
		 * @return List of the selectors packages.
		 */
		std::vector<PAFPackageSelector*>* GetSelectorPackages();
		
		/**
		 * Add a selector to the list of selector packages.
		 * 
		 * @param packageSelectorName Name of the selector package.
		 */
		void AddSelectorPackage(TString& packageSelectorName);
		
		/**
		 * Add a selector to the list of selector packages.
		 * 
		 * @param packageSelectorName Name of the selector package.
		 */
		void AddSelectorPackage(const char* packageSelectorName);
		
		
		/**
		 * Add a selector to the list of selector packages using a PAFPackageSelector object.
		 * 
		 * @param packageSelector PAFPackageSelector object to be used.
		 */
		void AddSelectorPackage(PAFPackageSelector* packageSelector);

		/**
		 * Set the list of libraries that are going to be used.
		 * 
		 * @param libraries List of libraries to be used.
		 */
		void SetLibraries(std::vector<PAFLibrary*>* libraries);
		
		/**
		 * Return the list of the libraries.
		 * 
		 * @return List of libraries.
		 */
		std::vector<PAFLibrary*>* GetLibraries();
		
		/**
		 * Add a library to the list of libraries.
		 * 
		 * @param libraryName Name of the library.
		 */
		void AddLibrary(TString& libraryName);
		
		/**
		 * Add a library to the list of libraries.
		 * 
		 * @param libraryName Name of the library.
		 */
		void AddLibrary(const char* libraryName);
		
		/**
		 * Add a library to the list of libraries using a PAFLibrary object.
		 * 
		 * @param library PAFLibrary object.
		 */
		void AddLibrary(PAFLibrary* library);

		/**
		 * Set the settings that the project is going to use.
		 * 
		 * @param settings The PAFISettings object to use.
		 */
		void SetPAFSettings(PAFISettings* settings);
		
		/**
		 * Return the settings that the project is going to use.
		 * 
		 * @return PAFISettings object.
		 */
		PAFISettings* GetPAFSettings();

		/**
		 * Set the filename of the resultant analysis file.
		 * 
		 * @param fileName Filname desired.
		 */
		void SetOutputFile(TString& fileName);
		
		/**
		 * Set the filename of the resultant analysis file.
		 * 
		 * @param fileName Filname desired.
		 */
		void SetOutputFile(const char* fileName);
		
		/**
		 * Return the filename of the resultant analysis file.
		 * 
		 * @return Filename that is going to be used.
		 */
		TString GetOutputFile();

		/**
		 * Set the input parameters.
		 * 
		 * @param inputParameters PAFVariableContainer object.
		 */
		void SetInputParameters(PAFVariableContainer* inputParameters);
		
		/**
		 * Return the input parameters.
		 * 
		 * @return PAFVariableContainer object.
		 */
		PAFVariableContainer* GetInputParameters();
		
		/**
		 * Add a new parameter under the given key.
		 * 
		 * @param key Key used to store the parameter.
		 * @param param Value that will be stored.
		 * @tparam T Type of the value item.
		 */
		template <typename T>
		void SetInputParam(const TString& key, T param);
		
		/**
		 * Add a new parameter under the given key.
		 * 
		 * @param key Key used to store the parameter.
		 * @param param Value that will be stored.
		 * @tparam T Type of the value item.
		 */
		template <typename T>
		void SetInputParam(const char* key, T param);

		/**
		 * Set the list of dynamic histograms.
		 * 
		 * @param dynamicHistograms List of histograms to be shown.
		 */
		void SetDynamicHistograms(std::vector<TString>* dynamicHistograms);
		
		/**
		 * Return the list of dynamic histograms.
		 * 
		 * @return List of strings that specify the name of the histograms.
		 */
		std::vector<TString>* GetDynamicHistograms();
		
		/**
		 * Add a new histogram to the list of dynamic histograms.
		 * 
		 * @param histogram Histogram name to be added.
		 */
		void AddDynamicHistogram(TString& histogram);
		
		/**
		 * Add a new histogram to the list of dynamic histograms.
		 * 
		 * @param histogram Histogram name to be added.
		 */
		void AddDynamicHistogram(const char* histogram);

		/**
		 * Set if the compilation of the code will occure in the worker nodes.
		 * 
		 * @param compileOnSlaves True if the code should be compiled in the worker nodes.
		 */
		void SetCompileOnSlaves(bool compileOnSlaves);
		
		/**
		 * Return if the compilation of the code will occure in the worker nodes.
		 * 
		 * @return True if the code should be compiled in the worker nodes.
		 */
		bool GetCompileOnSlaves();

		/**
		 * Set the object that will be used to report the progress status.
		 * 
		 * @param progressUpdated PAFIProgressUpdated object.
		 */
		void SetProgressUpdated(PAFIProgressUpdated* progressUpdated);
		
		/**
		 * Return the object that will be used to report the progress status.
		 * 
		 * @return PAFIProgressUpdated object.
		 */
		PAFIProgressUpdated* GetProgressUpdatedFunction();

		/**
		 * Execute the anlaysis.
		 * 
		 * Compiles the code, initialise the environment, runs the anlysis and diseposes the environment.
		 * 
		 * @return Resultant items.
		 */
		TList* Run();
		
		/**
		 * Template method in order to execute check if the project could be executed.
		 */
		virtual void doProjectChecks() = 0;
		
		/**
		 * Template method that executes the analysis.
		 * 
		 * @param selector The selector that will be used.
		 */
		virtual void doRun(PAFBaseSelector* selector) = 0;

	protected:
		/**
		 * Initialise the object.
		 */
		void InitMembers();

		/**
		 * Create a object of a specific class.
		 * 
		 * @param className Name of the class of the object.
		 * @tparam T Resultant type of the object.
		 * @return Object created.
		 */
		template<typename T>
		T CreateObject(const char* className);

		/**
		 * Compile or prepare a package.
		 * 
		 * @param package Package to be prepared.
		 */
		void PreparePackage(PAFPackage* package);
		
		/**
		 * Prepare the list of packages.
		 */
		void PreparePackages();
		
		/**
		 * Load the project inside the environment.
		 */
		void LoadProjectItems();
		
		/**
		 * Create the instance of the analysis.
		 */
		void PreparePAFSelector();
		
		/**
		 * Notify to the environment about the dynamic histograms.
		 */
		void AddDynamicHistograms();

	protected:
		/**
		 * Execution environment to be used.
		 */
		PAFIExecutionEnvironment* fExecutionEnvironment;
		
		/**
		 * Input parameters variable container.
		 */
		PAFVariableContainer* fInputParameters;
		
		/**
		 * Selector of PAF to be used.
		 */
		PAFISelector* fPAFSelector;
		
		/**
		 * Packages of code to be used.
		 */
		std::vector<PAFPackage*>* fPackages; //!
		
		/**
		 * Packages of code that contains selectors.
		 */
		std::vector<PAFPackageSelector*>* fSelectorPackages; //!
		
		/**
		 * Libraries to use during the analysis.
		 */
		std::vector<PAFLibrary*>* fLibraries; //!
		
		/**
		 * Output filename where the resultant items will be left.
		 */
		TString fOutputFile;
		
		/**
		 * Dynamic histograms that will be refreshed during the analysis.
		 */
		std::vector<TString>* fDynamicHistograms;
		
		/**
		 * Settings that configure the project execution.
		 */
		PAFISettings* fPAFSettings;
		
		/**
		 * Set if the code will be compiled on the workers side.
		 */
		bool fCompileOnSlaves;
		
		/**
		 * Object that handles the notification of the status.
		 */
		PAFIProgressUpdated* fProgressUpdated;

	ClassDef(PAFAbstractProject, 1);
};

template <typename T>
inline void PAFAbstractProject::SetInputParam(const TString& key, T param)
{
	SetInputParam(key.Data(), param);
}

template <typename T>
inline void PAFAbstractProject::SetInputParam(const char* key, T param)
{
	fInputParameters->Add(key, param);
}

template<>
inline void PAFAbstractProject::SetInputParam(const TString& key, const char* param)
{
	TString tparam(param);
	SetInputParam(key.Data(), tparam);
}

template <>
inline void PAFAbstractProject::SetInputParam(const char* key, const char* param)
{
	TString tparam(param);
	SetInputParam(key, tparam);
}
