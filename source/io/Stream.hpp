#ifndef __STREAM_MANAGER_HPP
#define __STREAM_MANAGER_HPP


#include <vector>
#include <string>

#define DELIMITER '|'
#define NBCOLUMNS 3
#define SPACER ' '
#define NDATASYMBOL '%'
#define PROTEINSEPARATOR '-'
#define DATADIRECTORY "data"
#define NBRCOMPLEXNAME "Number"

/**
 * Stream abstract class that defines common behaviors for stream operations class.
 */


class Stream {

	protected:

		//-----------------------------
		// Protected data members
		//-----------------------------
		//
		// complexes_
		//		A vector of string representing the complexes of a protein communication model.
		//
		// partners_
		//		A vector of string representing the partners of a protein communication model.
		//
		// dissociation_constants_
		//		A vector of string representing the dissociation constants of protein complexes.
		//
		// nbData_
		//		The size of the data vector.

		std::vector<std::string> complexes_;
		std::vector<std::string> partners_;
		std::vector<std::string> dissociation_constants_;

		unsigned int nbData_ = 0;

	public:

		//---------------------------
		// Getters and Setters
		//---------------------------

		/**
		 * Get a vector of string representing the proteic complexes.
		 *
		 * @return The proteic complexes.
		 *
		 * @see ProteinComplex
		 */

		std::vector<std::string> getComplexes() const;

		/**
		 *	Get a vector of string representing the partners of proteic complexes.
		 *
		 * @see ProteinComplex
		 */

		std::vector<std::string> getPartners() const;

		/**
		 * Get a vector of string representing the dissociation constants of proteic complexes.
		 */

		std::vector<std::string> getConstants() const;

		/**
		 * Set all the data of a stream.
		 *
		 * @param A vector of proteic complexes.
		 * @param A vector of partners of proteic complexes.
		 * @param A vector of dissociation constants of proteic complexes.
		 */

		void updateData(std::vector<std::string> complexes, std::vector<std::string> partners, std::vector<std::string> constants);

		/**
		 * Get the number of data (i.e. the size of the data members vectors).
		 *
		 * @return The number of data of this class instance.
		 */

		unsigned int getNbData() const;

		/**
		 * Set the filename of a Stream instance (this filename will be used to saved data or load data).
		 *
		 * @param The filename.
		 *
		 * @see IOManager
		 */

		virtual void setFilename(std::string) = 0;

};

#endif /*  __STREAM_MANAGER_HPP */