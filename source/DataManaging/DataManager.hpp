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
		std::vector<double> dissociation_constants_;

		unsigned int index_ = 0;

	public:

		std::vector<std::string> getComplexes() const;
		std::vector<std::string> getPartners() const;
		std::vector<double> getConstants() const;
		unsigned int getIndex() const;

		void incIndex() {++index_;}
		void decIndex() {--index_;}
		void resetIndex() {index_ = 0;}

};