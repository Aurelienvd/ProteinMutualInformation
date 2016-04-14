/**
 *  A container for the InformationEntity class. There are three entities, the input, the channel and the output (cf. Shannon Communication Model).
 */


#ifndef __INFORMATION_PROTEINS_CONTAINER_HPP
#define __INFORMATION_PROTEINS_CONTAINER_HPP

#include <cstddef>
#include <algorithm>

#include "InformationEntity.hpp"

class InformationProteinsContainer {

	private:

		//----------------------------
		// Private data members
		//
		// input_
		// 		The entity representing the input.
		//
		// output_
		//		The entity representing the output.
		//
		// channel_
		//		The entity representing the channel.
		//----------------------------

		InformationEntity* input_;
		InformationEntity* output_;
		InformationEntity* channel_;

		ProteinComplex* getComplex(unsigned int size) const;

	public:

		InformationProteinsContainer();
		~InformationProteinsContainer();

		//---------------------------------
		// Getters
		//---------------------------------

		/**
		 * Get the input Information Entity.
		 *
		 * @return the input_.
		 */

		InformationEntity* getInput() const;

		/**
		 * Get the output Information Entity.
		 *
		 * @return the output_.
		 */

		InformationEntity* getOutput() const;

		/**
		 * Get the channel Information Entity.
		 *
		 * @return the channel_.
		 */

		InformationEntity* getChannel() const;

		/**
		 * Get  the complexes binded with the channel.
		 *
		 * @param size The size of the complexes returned.
		 *
		 * @return A std::vector of ProteinComplex pointers.
		 */

		std::vector<ProteinComplex*> getOneSidedComplexes(unsigned int size) const;

		/**
		 * Get the complex representing the whole communication model.
		 * For a binary model, for instance, the complex returned contains the input, the ouput and the channel.
		 *
		 * @param size The size of the whole communication complex required.
		 *
		 * @return A ProteinComplex.
		 */

		ProteinComplex* getWholeCommunicationComplex(unsigned int size) const;

		/**
		 * Get the dissociation constants of the one sided complexes.
		 *
		 * @param size The size of the one sided complexes.
		 *
		 * @return A std::vector of doubles values.
		 */

		std::vector<double> getOneSidedComplexesDissociationConstant(unsigned int size) const;

		/**
		 * Get the dissociation constant of the whole communication complex.
		 *
		 * @param size The size of the whole communication complex.
		 *
		 * @return The dissociation constant of the whole complex.
		 */

		double getWholeCommunicationComplexDissociationConstant(unsigned int size) const;

		/**
		 * Get the input concentration.
		 *
		 * @return the input concentration.
		 *
		 * @see InformationEntity#getProteinConcentration
		 */

		double getInputConcentration() const;
		
		/**
		 * Get the output concentration.
		 *
		 * @return the output concentration.
		 *
		 * @see InformationEntity#getProteinConcentration
		 */

		double getOutputConcentration() const;

		/**
		 * Get the channel concentration.
		 *
		 * @return the channel concentration.
		 *
		 * @see InformationEntity#getProteinConcentration
		 */

		double getChannelConcentration() const;

		/**
		 * Get the range of values that the input can have.
		 *
		 * @return A std::vector of double values.
		 *
		 * @see InformationEntity#getRange
		 */

		std::vector<double> getInputRange() const;

		/**
		 * Get the range of values that the output can have.
		 *
		 * @return A std::vector of double values.
		 *
		 * @see InformationEntity#getRange
		 */

		std::vector<double> getOutputRange() const;

		/**
		 * Get the range of values that the channel can have.
		 *
		 * @return A std::vector of double values.
		 *
		 * @see InformationEntity#getRange
		 */

		std::vector<double> getChannelRange() const;

		/**
		 * Get the biggest middle range value.
		 * 
		 * To find the biggest value, this object gets the middle range value of
		 * the input, the output and the channel and compares them.
		 *
		 * @return A float value that is the biggest range value.
		 *
		 * @see InformationEntity#getRangeMidValue
		 */

		float getBiggestMidRangeValue() const;

		//------------------------------------------
		// Setters
		//------------------------------------------

		/**
		 * Set the input to an already existing InformationEntity.
		 *
		 * @param in A pointer to an InformationEntity created before.
		 */

		void setInput(InformationEntity* in);

		/**
		 * Set the output to an already existing InformationEntity.
		 *
		 * @param in A pointer to an InformationEntity created before.
		 */

		void setOutput(InformationEntity* out);

		/**
		 * Set the channel to an already existing InformationEntity.
		 *
		 * @param in A pointer to an InformationEntity created before.
		 */

		void setChannel(InformationEntity* chan);

		/**
		 * Set the concentration of the input to the given value.
		 *
		 * @param concent The required protein concentration.
		 *
		 * @see InformationEntity#setProteinConcentration
		 */

		void setInputConcentration(double concent);

		/**
		 * Set the concentration of the output to the given value.
		 *
		 * @param concent The required protein concentration.
		 *
		 * @see InformationEntity#setProteinConcentration
		 */

		void setOutputConcentration(double concent);

		/**
		 * Set the concentration of the channel to the given value.
		 *
		 * @param concent The required protein concentration.
		 *
		 * @see InformationEntity#setProteinConcentration
		 */

		void setChannelConcentration(double concent);
};

#endif /* __INFORMATION_PROTEINS_CONTAINER_HPP */