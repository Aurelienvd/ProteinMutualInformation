CPPUNIT_PATH=/usr/include/cppunit
OBJECTS = main.o TestReader.o
MAIN_OBJECTS = ../../FileDataReader.o ../../DataManager.o

test: main.o TestReader.o $(MAIN_OBJECT)
	$(CC) -o test main.o TestReader.o $(MAIN_OBJECTS) -L${CPPUNIT_PATH}/lib -lstdc++ -lcppunit -ldl

TestReader.o: TestReader.cpp
	$(CC) $(CXXFLAGS) -c TestReader.cpp -I${CPPUNIT_PATH}/include

main.o: main.cpp
	$(CC) $(CXXFLAGS) -c main.cpp -I${CPPUNIT_PATH}/include

clean:
	rm -f *.o ftest
