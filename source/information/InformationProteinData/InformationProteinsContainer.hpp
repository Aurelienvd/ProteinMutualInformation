/**
 *  A container for the InformationEntity class. There are three entities, the input, the channel and the output (cf. Shannon Communication Model).
 */


#ifndef __INFORMATION_PROTEINS_CONTAINER_HPP
#define __INFORMATION_PROTEINS_CONTAINER_HPP

#include <cstddef>
#include <algorithm>
#include <vector>
#include <memory>
#include <map>

#include "InformationEntity.hpp"

class InformationProteinsContainer {

	typedef std::vector<std::shared_ptr<InformationEntity>> infovector;
	typedef std::vector<std::shared_ptr<ProteinComplex>> complexvector;
	typedef std::map<unsigned int, complexvector> complexes_map;
	typedef std::pair<unsigned int, complexvector> complexes_pair;

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
		//
		// inputs_
		//		A vector of entities that represents multiple inputs. (for multivariate info)
		//----------------------------
		std::shared_ptr<InformationEntity> input_;
		std::shared_ptr<InformationEntity> output_;
		std::shared_ptr<InformationEntity> channel_;
		infovector inputs_;

		std::shared_ptr<ProteinComplex> getComplex(unsigned int size) const;

	public:

		InformationProteinsContainer();
		~InformationProteinsContainer() = default;

		//---------------------------------
		// Getters
		//---------------------------------

		/**
		 * Get the input Information Entity.
		 *
		 * @return the input_.
		 */

		std::shared_ptr<InformationEntity> getInput() const;

		/**
		 * Get the inputs Information Entity. (for multivariate info)
		 *
		 * @return the inputs_.
		 */

		infovector getInputs() const;

		/**
		 * Get the output Information Entity.
		 *
		 * @return the output_.
		 */

		std::shared_ptr<InformationEntity> getOutput() const;

		/**
		 * Get the channel Information Entity.
		 *
		 * @return the channel_.
		 */

		std::shared_ptr<InformationEntity> getChannel() const;

		/**
		 * Get  the complexes binded with the channel.
		 *
		 * @param size The size of the complexes returned.
		 *
		 * @return A std::vector of ProteinComplex pointers.
		 */

		std::vector<std::shared_ptr<ProteinComplex>> getOneSidedComplexes(unsigned int size) const;

		/**
		 * Get the complex representing the whole communication model.
		 * For a binary model, for instance, the complex returned contains the input, the ouput and the channel.
		 *
		 * @param size The size of the whole communication complex required.
		 *
		 * @return A ProteinComplex.
		 */

		std::shared_ptr<ProteinComplex> getWholeCommunicationComplex(unsigned int size) const;

		/**
		 * Get all the complexes between min size and max size. (for multivariate info)
		 *
		 * @param min The minimum size of a complex.
		 *
		 * @param max The maximum size of a complex.
		 *
		 * @return A map mapping a size with complexes (which size matches the param).
		 */

		complexes_map getAllComplexesBetween(unsigned int min, unsigned int max);

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
		 * Get inputs concentration.
		 *
		 * @return inputs concentration.
		 *
		 * @see InformationEntity#getProteinConcentration
		 */

		std::vector<double> getInputsConcentration() const;
		
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
		 * Get the range of values that the inputs can have.
		 *
		 * @return A std::vector<std::vector> of double values.
		 *
		 * @see InformationEntity#getRange
		 */

		std::vector<std::vector<double>> getInputsRange() const;

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

		void setInput(std::shared_ptr<InformationEntity> in);

		/**
		 * Set the inputs to an already existing vector of InformationEntities.
		 *
		 * @param inputs A vector of InformationEntities created before.
		 */

		void setInputs(infovector inputs);

		/**
		 * Add a input to the inputs vector.
		 *
		 * @param in A pointer to an InformationEntity created before.
		 */

		void addToInputs(std::shared_ptr<InformationEntity> in);

		/**
		 * Set the output to an already existing InformationEntity.
		 *
		 * @param in A pointer to an InformationEntity created before.
		 */

		void setOutput(std::shared_ptr<InformationEntity> out);

		/**
		 * Set the channel to an already existing InformationEntity.
		 *
		 * @param in A pointer to an InformationEntity created before.
		 */

		void setChannel(std::shared_ptr<InformationEntity> chan);

		/**
		 * resets inputs vector.
		 */

		void resetInputs();

		/**
		 * Set the concentration of the input to the given value.
		 *
		 * @param concent The required protein concentration.
		 *
		 * @see InformationEntity#setProteinConcentration
		 */

		void setInputConcentration(double concent);

		/**
		 * Set the concentration of an input to the given value.
		 *
		 * @param concent The required protein concentration.
		 *
		 * @see InformationEntity#setProteinConcentration
		 */

		void setInputsConcentration(double concent, int index);

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