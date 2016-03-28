#ifndef __DATA_MANAGER_HPP
#define __DATA_MANAGER_HPP

#include <string>

#include "../datamanaging/InputDataManager.hpp"
#include "../datamanaging/ConcreteStream.hpp"
#include "Facade.hpp"


class DataManager: public Facade {

private:

	InputDataManager* manager_;

public:

	DataManager(ProcessDirector* director);
	virtual ~DataManager();

	void updateData(ConcreteStream& streamData) const;
	bool saveData(std::string filename) const;
	ConcreteStream* loadData(std::string filename) const;


};

#endif  /* __DATA_MANAGER_HPP */