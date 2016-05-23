#include "OctaveRootFinder.hpp"

OctaveRootFinder::OctaveRootFinder(): octave_solutions_(), upper_bounds_(),lower_bounds_({rflowerbounds::kFirstBound, rflowerbounds::kSecondBound, 
										rflowerbounds::kThirdBound, rflowerbounds::kForthBound, rflowerbounds::kFifthBound, rflowerbounds::kSixthBound}), values_() {}

void OctaveRootFinder::setUpperBounds(std::vector<double> bounds)
{
	upper_bounds_ = bounds;
}

void OctaveRootFinder::setValues(std::vector<double> values)
{
	values_ = values;
}

void OctaveRootFinder::writeToFile(std::string filename, std::vector<double> data, std::string separator) const
{
	std::ofstream file(filename);

	if(file.is_open()){
		std::string str = "";
		for (unsigned int i = 0; i < rfconfig::kSystemSize; i++){
			str += std::to_string(data.at(i)) + separator;	
		}
		str.pop_back();
		file << str;
		file.close();
	}
}

void OctaveRootFinder::writeValues() const
{
	std::string filename = OCTAVEDIR + octaveconfig::kValuesFilename + octaveconfig::kFileExtension;
	writeToFile(filename, values_, octaveconfig::kOutDataSeparator);
}

std::vector<double> OctaveRootFinder::getGuesses() const
{
	std::vector<double> guesses;
	double guess;
	for (unsigned int i = 0; i < infoconfig::kNbComplexBoundToChannel; i++){
		guesses.push_back(upper_bounds_[0]);
	}

	guesses.push_back(upper_bounds_[1]);
	guesses.push_back(upper_bounds_[2]);

	return guesses;
}

void OctaveRootFinder::writeGuesses() const
{
	
	std::vector<double> guesses = lower_bounds_;
	std::string filename = OCTAVEDIR + octaveconfig::kGuessesFilename + octaveconfig::kFileExtension;
	writeToFile(filename, guesses, octaveconfig::kOutDataSeparator);
}

void OctaveRootFinder::callOctave()
{
	std::system((octaveconfig::kOctaveCommand + octaveconfig::kOctaveExeFile).c_str());
}

void OctaveRootFinder::readRoots()
{
	std::ifstream file(OCTAVEDIR + octaveconfig::kRootsFilename + octaveconfig::kFileExtension);
	if (file.is_open()){
		std::string line;
		std::vector<double> roots;
		std::getline(file, line);
		file.close();
		
		std::vector<std::string> split = splitString(line, (octaveconfig::kOutDataSeparator.c_str())[0]);

		for (std::string str : split){
			roots.push_back(std::stod(str));
		}

		octave_solutions_ = roots;
	}
}

void OctaveRootFinder::solve()
{
	writeValues();
	writeGuesses();
	callOctave();
	readRoots();
}

std::vector<double> OctaveRootFinder::getSolutions() const
{
	return octave_solutions_;
}