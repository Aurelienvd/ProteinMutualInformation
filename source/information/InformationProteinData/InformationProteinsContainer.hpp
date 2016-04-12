#ifndef __INFORMATION_PROTEINS_CONTAINER_HPP
#define __INFORMATION_PROTEINS_CONTAINER_HPP

#include <cstddef>
#include <algorithm>

#include "InformationEntity.hpp"

class InformationProteinsContainer {

	private:

		InformationEntity* input_;
		InformationEntity* output_;
		InformationEntity* channel_;

		ProteinComplex* getComplex(unsigned int size) const;

	public:

		InformationProteinsContainer();
		~InformationProteinsContainer();

		InformationEntity* getInput() const;
		InformationEntity* getOutput() const;
		InformationEntity* getChannel() const;

		std::vector<ProteinComplex*> getOneSidedComplexes(unsigned int size) const;  // Returns A vector containing all the complexes of size 'size' defining as 1 complex binded with the channel;
		ProteinComplex* getWholeCommunicationComplex(unsigned int size) const;

		std::vector<double> getOneSidedComplexesDissociationConstant(unsigned int size) const;
		double getWholeCommunicationComplexDissociationConstant(unsigned int size) const;

		double getInputConcentration() const;
		double getOutputConcentration() const;
		double getChannelConcentration() const;

		std::vector<double> getInputRange() const;
		std::vector<double> getOutputRange() const;
		std::vector<double> getChannelRange() const;

		float getBiggestMidRangeValue() const;

		void setInput(InformationEntity* in);
		void setOutput(InformationEntity* out);
		void setChannel(InformationEntity* chan);

		void setInputConcentration(double concent);
		void setOutputConcentration(double concent);
		void setChannelConcentration(double concent);
};

#endif /* __INFORMATION_PROTEINS_CONTAINER_HPP */