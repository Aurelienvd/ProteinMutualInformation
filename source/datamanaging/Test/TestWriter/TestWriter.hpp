#ifndef __TEST_WRITER_HPP
#define __TEST_WRITER_HPP

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../../FileDataWriter.hpp"

#define FILE "writingTest.txt"

class TestWriter : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE (TestWriter);
	CPPUNIT_TEST (writeTest);
	CPPUNIT_TEST_SUITE_END ();

	public:
		void setUp(void);
		void tearDown(void);

	protected:
		void writeTest(void);

	private:
		FileDataWriter* writer_;

};


#endif /*  __TEST_WRITER_HPP   */