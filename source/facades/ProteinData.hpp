
/**
 * A facade that construct global ADT of the system.
 *
 * The global ADT will contains all the information available after that a file is loaded.
 *
 * @see IOManager
 */

#ifndef __PROTEIN_DATA_HPP
#define __PROTEIN_DATA_HPP


#include "../protein/ProteinsContainerBuilder.hpp"
#include "../communicationdata/ConcreteStream.hpp"
#include "Facade.hpp"

class ProteinData: public Facade {

private:

	//----------------------
	// Private data members
	//----------------------
	//
	// protein_adt_builder_
	// 		A pointer to a builder of the global ADT.

	std::unique_ptr<ProteinsContainerBuilder> protein_adt_builder_;

public:

	/** @name Constructors */
	//@{
	/** Default constructor.
	 * 
	 * @see Facade
	 */
	//@}

	ProteinData(ProcessDirector* director);
	virtual ~ProteinData() = default;

	/**
	 * Construct the global ADT which is an instance of the ProteinsContainer class.
	 *
	 * @param data Data indicating to the builder what to build.
	 *
	 * @see ConcreteStream
	 * @see ProteinsContainerBuilder
	 */

	void constructADT(std::shared_ptr<ConcreteStream> data);

	/**
	 * Return the ADT built.
	 *
	 * @return The ADT built.
	 *
	 * @see ProteinsContainer
	 */

	std::shared_ptr<ProteinsContainer> getADT() const;

};

#endif /* __PROTEIN_DATA_HPP  */