#ifndef __STRING_TO_PROTEIN_WRAPPER_HPP
#define __STRING_TO_PROTEIN_WRAPPER_HPP

#include <string>
#include <memory>
#include <vector>
#include "../protein/Protein.hpp"

#define PROTSEPARATOR '-'


std::shared_ptr<Protein> wrapString(std::string protein_name);
std::vector<std::vector<std::shared_ptr<Protein>>> wrapStringVector(std::vector<std::string> vector);

#endif /* __STRING_TO_PROTEIN_WRAPPER_HPP  */