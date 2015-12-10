#include "TestWriter.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(TestWriter);

void TestWriter::setUp(void)
{
	writer_ = new FileDataWriter();
	writer_->setFilename(FILE);
	std::vector<std::string> complexes = {"Csk1-Skp2", "Cks1-Cdk2-p27", "Cks1-p27"};
	std::vector<std::string> partners = {"p27","Skp2","Cdk2"};
	std::vector<std::string> constants = {"0.47", "0.0001", "3"};
	writer_->updateData(complexes, partners, constants);
}

void TestWriter::tearDown(void)
{
	delete writer_;
}

void TestWriter::writeTest(void)
{
	CPPUNIT_ASSERT_EQUAL (true, writer_->writeData());
}