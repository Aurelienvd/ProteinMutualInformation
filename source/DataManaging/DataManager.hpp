#ifndef __DATA_MANAGER_HPP
#define __DATA_MANAGER_HPP


#include <vector>
#include <string>

#define DELIMITER '|'
#define NBDATA 3
#define SPACER ' '
#define NDATASYMBOL '%'


class DataManager {

	protected:

		std::vector<std::string> complexes_;
		std::vector<std::string> partners_;
		std::vector<std::string> dissociation_constants_;

		unsigned int nbData_ = 0;

	public:

		std::vector<std::string> getComplexes() const;
		std::vector<std::string> getPartners() const;
		std::vector<std::string> getConstants() const;
		unsigned int getNbData() const;
		virtual void setFilename(std::string) = 0;

		void setNbData(unsigned int nbData);

};

#endif /*  __DATA_MANAGER_HPP */