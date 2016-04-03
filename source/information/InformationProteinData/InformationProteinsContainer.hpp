#ifndef __INFORMATION_PROTEINS_CONTAINER_HPP
#define __INFORMATION_PROTEINS_CONTAINER_HPP

#include <cstddef>

#include "InformationEntity.hpp"

class InformationProteinsContainer {

	private:

		InformationEntity* input_;
		InformationEntity* output_;
		InformationEntity* channel_;

	public:

		InformationProteinsContainer();
		~InformationProteinsContainer();

		InformationEntity* getInput() const;
		InformationEntity* getOutput() const;
		InformationEntity* getChannel() const;

		void setInput(InformationEntity* in);
		void setOutput(InformationEntity* out);
		void setChannel(InformationEntity* chan);




};

#endif /* __INFORMATION_PROTEINS_CONTAINER_HPP */