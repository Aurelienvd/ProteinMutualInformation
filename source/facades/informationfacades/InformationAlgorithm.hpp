#ifndef __INFORMATION_ALGORITHM_HPP
#define __INFORMATION_ALGORITHM_HPP

#include "../Facade.hpp"
#include "../../information/InformationStrategy/InformationStrategy.hpp"
#include "../../information/ResultTable/ResultTable.hpp"

#include <cstddef>
#include <memory>


class InformationAlgorithm : public Facade {

	private:

		std::shared_ptr<InformationStrategy> strategy_;

	public:

		InformationAlgorithm(ProcessDirector* director);

		void setStrategy(std::shared_ptr<InformationStrategy> strat);
		void startAlgorithm(std::shared_ptr<ResultTable> res);

};


#endif /* __INFORMATION_ALGORITHM_HPP  */