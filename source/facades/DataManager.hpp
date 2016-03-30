#ifndef __DATA_MANAGER_HPP
#define __DATA_MANAGER_HPP

#include <string>

#include "../io/InputDataManager.hpp"
#include "../communicationdata/ConcreteStream.hpp"
#include "Facade.hpp"


class DataManager: public Facade {

private:

	InputDataManager* manager_;

public:

	DataManager(ProcessDirector* director);
	virtual ~DataManager();

	void updateData(ConcreteStream* streamData) const;
	bool saveData() const;
	ConcreteStream* loadData() const;


};

#endif  /* __DATA_MANAGER_HPP */