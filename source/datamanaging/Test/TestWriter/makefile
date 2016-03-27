CPPUNIT_PATH=/usr/include/cppunit
OBJECTS = main.o TestWriter.o
MAIN_OBJECTS = ../../FileDataWriter.o ../../DataManager.o

test: main.o TestWriter.o $(MAIN_OBJECT)
	$(CC) -o test main.o TestWriter.o $(MAIN_OBJECTS) -L${CPPUNIT_PATH}/lib -lstdc++ -lcppunit -ldl

TestWriter.o: TestWriter.cpp
	$(CC) $(CXXFLAGS) -c TestWriter.cpp -I${CPPUNIT_PATH}/include

main.o: main.cpp
	$(CC) $(CXXFLAGS) -c main.cpp -I${CPPUNIT_PATH}/include

clean:
	rm -f *.o ftest