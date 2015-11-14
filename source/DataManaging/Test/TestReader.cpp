#include "TestReader.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(TestReader);

void TestReader::setUp(void)
{
	reader_ = new FileDataReader();
	reader_->setFilename(FILE);
}

void TestReader::tearDown(void)
{
	delete reader_;
}

void TestReader::readTest(void)
{
	CPPUNIT_ASSERT_EQUAL (true, reader_->readDataFromFile());
}

void TestReader::dataTest(void)
{
	reader_->readDataFromFile();
	
	CPPUNIT_ASSERT_EQUAL (NBRDATA, static_cast<int> (reader_->getComplexes().size()));
	CPPUNIT_ASSERT_EQUAL (NBRDATA, static_cast<int> (reader_->getPartners().size()));
	CPPUNIT_ASSERT_EQUAL ((NBRDATA), static_cast<int> (reader_->getConstants().size()));
}