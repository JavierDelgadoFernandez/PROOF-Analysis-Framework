/**
 * @brief Abstract class where users should place his own code using inheritance.
 * @file PAFChainItemSelector.h
 * @author I. Gonzalez Caballero, J. Delgado Fernandez
 * @version 1.0
 * @date 2014-12-04
 */

#pragma once

#include "PAFISelector.h"

#include <vector>

#include "TLeaf.h"
#include "TString.h"

#include "TH1F.h"
#include "TH1D.h"
#include "TH2F.h"
#include "TProfile.h"
#include "TTree.h"

#include "PAF.h"
#include "PAFFindHelper.h"
#include "PAFIType.h"

/**
 * @class PAFChainItemSelector
 * @brief Abstract class where users should place his own code using inheritance.
 */
class PAFChainItemSelector : public PAFISelector
{
	public:
		/**
		 * Default constructor.
		 */
		PAFChainItemSelector();

		/**
		 * Destructor.
		 */
		virtual ~PAFChainItemSelector();

		/**
		 * Initialise method called only once per worker.
		 */
		virtual void Initialise();

		/**
		 * InitialiseParameters called after Initialise and only once per worker.
		 */
		virtual void InitialiseParameters();

		/**
		 * InsideLoop method, called once per event and after the initialise methods.
		 */
		virtual void InsideLoop();

		/**
		 * Summary method, runs after the whole process ends and it is executed on the client node. Used to print the results.
		 */
		virtual void Summary();

		/**
		 * Set the data to the selector that it is not going to change during the whole analysis in each worker.
		 *
		 * @param input List of inputs that come from the project.
		 * @param output List of items where the selector will leave the results.
		 * @param selectorParams Input variables set on the project.
		 */
		void SetStaticData(TList* fInput, TSelectorList* fOutput, PAFVariableContainer* selectorParams);

		/**
		 * Set the data to the selector that will be changing. It may be called several times during the analysis.
		 *
		 * @param variables Variables that are coming from the input data.
		 */
		void SetDynamicData(PAFVariableContainer* variables);

		/**
		 * Set the value of a given key.
		 *
		 * @param key Key used to store the value.
		 * @param object Object stored.
		 * @tparam T Type of the value.
		 */
		template<typename T>
		void SetParam(const char* key, T object);

		/**
		 * Get the value of a parameter.
		 *
		 * @param key Key used to store the value.
		 * @tparam T Type of the value.
		 * @return Value stored or NULL.
		 */
		template<typename T>
		T GetParam(const char* key);

		/**
		 * Get the value of a parameter as an int.
		 *
		 * @param key Key used to store the value.
		 * @return Value stored.
		 */
		Int_t GetParamInt(const char* key);

		/**
		 * Get the value of a parameter as a float.
		 *
		 * @param key Key used to store the value.
		 * @return Value stored.
		 */
		Float_t GetParamFloat(const char* key);

		/**
		 * Get the value of a parameter as a double.
		 *
		 * @param key Key used to store the value.
		 * @return Value stored.
		 */
		Double_t GetParamDouble(const char* key);

		/**
		 * Get the value of a parameter as a string.
		 *
		 * @param key Key used to store the value.
		 * @return Value stored.
		 */
		TString GetParamString(const char* key);

		/**
		 * Copies the value of a parameter key inside a given target.
		 *
		 * @param key Key used to store the value.
		 * @param target Member where the value should be left.
		 * @tparam T Type of the value.
		 */
		template<typename T>
		void AssignParam(const char* key, T& target);

		/**
		 * Get the value of a variable.
		 *
		 * @param key Key used to store the value.
		 * @tparam T Type of the value.
		 * @return Value stored or NULL.
		 */
		template<typename T>
		T Get(const char* key);

		/**
		 * Get the value of a variable as an integer.
		 *
		 * @param key Key used to store the value.
		 * @return Value stored or NULL.
		 */
		Int_t GetInt(const char* key);

		/**
		 * Get the value of a variable as a float.
		 *
		 * @param key Key used to store the value.
		 * @return Value stored or NULL.
		 */
		Float_t GetFloat(const char* key);

		/**
		 * Get the value of a variable as an double.
		 *
		 * @param key Key used to store the value.
		 * @return Value stored or NULL.
		 */
		Double_t GetDouble(const char* key);

		
		/**
		 * Get the value of a list of items.
		 *
		 * @param key Key used to store the value.
		 * @param i Position of the item.
		 * @tparam T Type of the value.
		 * @return Value stored or NULL.
		 */
		template<typename T>
		T Get(const char* key, Int_t i);

		/**
		 * Get the value of a list of items as an int.
		 *
		 * @param key Key used to store the value.
		 * @param i Position of the item.
		 * @return Value stored or NULL.
		 */
		Int_t GetInt(const char* key, Int_t i);

		/**
		 * Get the value of a list of items as a float.
		 *
		 * @param key Key used to store the value.
		 * @param i Position of the item.
		 * @return Value stored or NULL.
		 */
		Float_t GetFloat(const char* key, Int_t i);

		/**
		 * Get the value of a list of items as an double.
		 *
		 * @param key Key used to store the value.
		 * @param i Position of the item.
		 * @return Value stored or NULL.
		 */
		Double_t GetDouble(const char* key, Int_t i);
		
		/**
		 * Copies the value of a variable key inside a given target.
		 *
		 * @param key Key used to store the value.
		 * @param target Member where the value should be left.
		 * @tparam T Type of the value.
		 */
		template<typename T>
		void Assign(const char* key, T& target);

		/**
		 * Copies the value of the list of variables inside a given target.
		 *
		 * @param key Key used to store the value.
		 * @param target Member where the value should be left.
		 * @param i Position of the item.
		 * @tparam T Type of the value.
		 */
		template<typename T>
		void Assign(const char* key, T& target, Int_t i);
		
		/**
		 * Get a leaf using a given name.
		 *
		 * @param key Key used to store the TLeaf.
		 * @return Pointer to the TLeaf.
		 */
		TLeaf* GetLeaf(const char* key);

		/**
		 * Get a branch using a given name.
		 *
		 * @param key Key used to store the TBranch.
		 * @return Pointer to the TBranch.
		 */
		TBranch* GetBranch(const char* key);

		/**
		 * Test if a key exists inside the variable dictionary.
		 *
		 * @param key Key to test.
		 * @return True in the case of success.
		 */
		Bool_t Exists(const char* key);

		/**
		 * Calculate the number of items inside a variable.
		 *
		 * If the variable contains a single value, returns 1, in the case of an array, std::vector or TList it will manage to calculate the size.
		 *
		 * @param key Variable to check.
		 * @return Number of items insise of a variable.
		 */
		Int_t GetSizeOf(const char* key);

		//Helpers methods

		/**
		 * Look for an input item in the fInput list.
		 *
		 * @param name Name to use in the search.
		 * @return Object found or NULL.
		 */
		template<typename T>
		T FindInput(const char* name);

		/**
		 * Look for an input item in the fOutput list.
		 *
		 * @param name Name to use in the search.
		 * @return Object found or NULL.
		 */
		template<typename T>
		T FindOutput(const char* name);

		/**
		 * Create a Tree and store it in order to have it in the result file.
		 *
		 * @param name Name to the Tree.
		 * @param title Title to the Tree.
		 *
		 * @return Pointer to the created tree.
		 */
		TTree* CreateTree(const char* name, const char* title);

		/**
		 * Create a histogram of 1 dimesions composed by floats.
		 *
		 * @param name Name to the histogram.
		 * @param title Title to the histogram.
		 * @param nbinsx
		 * @param xlow
		 * @param xup
		 *
		 * @return Pointer to the created histogram.
		 */
		TH1F* CreateH1F(const char* name, const char* title, 
				Int_t nbinsx, Axis_t xlow, Axis_t xup);

		/**
		 * Create a histogram of 1 dimesions composed by floats.
		 *
		 * @param name Name to the histogram.
		 * @param title Title to the histogram.
		 * @param nbinsx
		 * @param bins
		 *
		 * @return Pointer to the created histogram.
		 */
		TH1F* CreateH1F(const char* name, const char* title,
				Int_t nbinsx, Float_t* bins);

		/**
		 * Create a histogram of 1 dimesions composed by floats.
		 *
		 * @param name Name to the histogram.
		 * @param title Title to the histogram.
		 * @param nbinsx
		 * @param bins
		 *
		 * @return Pointer to the created histogram.
		 */
		TH1F* CreateH1F(const char* name, const char* title,
				Int_t nbinsx, Double_t* bins);

		/**
		 * Create a histogram of 1 dimesions composed by doubles.
		 *
		 * @param name Name to the histogram.
		 * @param title Title to the histogram.
		 * @param nbinsx
		 * @param xlow
		 * @param xup
		 *
		 * @return Pointer to the created histogram.
		 */
		TH1D* CreateH1D(const char* name, const char* title,
				Int_t nbinsx, Axis_t xlow, Axis_t xup);

		/**
		 * Create a histogram of 1 dimesions composed by doubles.
		 *
		 * @param name Name to the histogram.
		 * @param title Title to the histogram.
		 * @param nbinsx
		 * @param bins
		 *
		 * @return Pointer to the created histogram.
		 */
		TH1D* CreateH1D(const char* name, const char* title,
				Int_t nbinsx, Double_t* bins);


		/**
		 * Create a histogram of 2 dimesions composed by floats.
		 *
		 * @param name Name to the histogram.
		 * @param title Title to the histogram.
		 * @param nbinsx
		 * @param xbins
		 * @param nbinsy
		 * @param ybins
		 *
		 * @return Pointer to the created histogram.
		 */
		TH2F* CreateH2F(const char* name, const char* title,
				Int_t nbinsx, Float_t* xbins,
				Int_t nbinsy, Float_t* ybins);

		/**
		 * Create a histogram of 2 dimesions composed by floats.
		 *
		 * @param name Name to the histogram.
		 * @param title Title to the histogram.
		 * @param nbinsx
		 * @param xbins
		 * @param nbinsy
		 * @param ybins
		 *
		 * @return Pointer to the created histogram.
		 */
		TH2F* CreateH2F(const char* name, const char* title,
				Int_t nbinsx, Double_t* xbins,
				Int_t nbinsy, Double_t* ybins);

		/**
		 * Create a histogram of 2 dimesions composed by floats.
		 *
		 * @param name Name to the histogram.
		 * @param title Title to the histogram.
		 * @param nbinsx
		 * @param xbins
		 * @param nbinsy
		 * @param ylow
		 * @param yup
		 *
		 * @return Pointer to the created histogram.
		 */
		TH2F* CreateH2F(const char* name, const char* title,
				Int_t nbinsx, Double_t* xbins,
				Int_t nbinsy, Axis_t ylow, Axis_t yup);

		/**
		 * Create a histogram of 2 dimesions composed by floats.
		 *
		 * @param name Name to the histogram.
		 * @param title Title to the histogram.
		 * @param nbinsx
		 * @param xlow
		 * @param xup
		 * @param nbinsy
		 * @param ylow
		 * @param yup
		 *
		 * @return Pointer to the created histogram.
		 */
		TH2F* CreateH2F(const char* name, const char* title,
				Int_t nbinsx, Axis_t xlow, Axis_t xup,
				Int_t nbinsy, Axis_t ylow, Axis_t yup);
  
		/**
		 * Create a profile.
		 *
		 * @param name Name to the profile.
		 * @param title Title to the histogram.
		 * @param nbinsx
		 * @param xlow
		 * @param xup
		 * @param ylow
		 * @param yup
		 */
		TProfile* CreateProfile(const char* name, const char* title,
				Int_t nbinsx, Axis_t xlow, Axis_t xup,
				Axis_t ylow, Axis_t yup);

	protected:
		/**
		 * List of items that come from the execution.
		 */
		TList* 			fInput;

		/**
		 * List of output items.
		 */
		TSelectorList* 		fOutput;

		/**
		 * Data that the analysis should use.
		 */
		PAFVariableContainer* 	fVariables; //! Do not stream

		/**
		 * Parameters to use in the analysis.
		 */
		PAFVariableContainer* 	fSelectorParams;

	ClassDef(PAFChainItemSelector, 1);
};

template <typename T>
inline void PAFChainItemSelector::SetParam(const char* key, T object)
{
	fSelectorParams->Add(key, object);
}

template <typename T>
T PAFChainItemSelector::GetParam(const char* key)
{
	return fSelectorParams->Get<T>(key);
}

template <typename T>
void PAFChainItemSelector::AssignParam(const char* key, T& target)
{
	target = GetParam<T>(key);
}

template <typename T>
T PAFChainItemSelector::Get(const char* key)
{
	T* value = (T*)fVariables->Get<PAFIType*>(key)->GetPointer();
	return *value;
}

template <typename T>
T PAFChainItemSelector::Get(const char* key, Int_t i)
{
	T* value = (T*)fVariables->Get<PAFIType*>(key)->GetPointer(i);
	return *value;
}

template <typename T>
void PAFChainItemSelector::Assign(const char* key, T& target)
{
	target = Get<T>(key);
}

template <typename T>
void PAFChainItemSelector::Assign(const char* key, T& target, Int_t i)
{
	target = Get<T>(key, i);
}

template <typename T>
T PAFChainItemSelector::FindInput(const char* name)
{
	return PAFFindHelper::Find<T>(fInput, name);
}

template <typename T>
T PAFChainItemSelector::FindOutput(const char* name)
{
	return PAFFindHelper::Find<T>(fOutput, name);
}
