#ifndef __DATA_MANAGER_HPP
#define __DATA_MANAGER_HPP

#include <string>

#include "InputDataManager.hpp"
#include "ConcreteStream.hpp"


class DataManager {

private:

	InputDataManager* manager_;

public:

	DataManager();
	~DataManager();

	void updateData(ConcreteStream& streamData) const;
	bool saveData(std::string filename) const;
	ConcreteStream* loadData(std::string filename) const;


};

#endif  /* __DATA_MANAGER_HPP */