#ifndef __TestReader__HPP
#define __TestReader__HPP

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../FileDataReader.hpp"

#define FILE "testData.txt"
#define NBRDATA 3


class TestReader : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE (TestReader);
	CPPUNIT_TEST (readTest);
	CPPUNIT_TEST (dataTest);
	CPPUNIT_TEST_SUITE_END ();

	public:
		void setUp(void);
		void tearDown(void);

	protected:
		void readTest(void);
		void dataTest(void);

	private:
		FileDataReader* reader_;

};




#endif /*  __TestReader__HPP  */