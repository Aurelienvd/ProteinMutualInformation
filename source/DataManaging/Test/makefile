CPPUNIT_PATH=/usr/include/cppunit
OBJECTS = main.o TestReader.o
MAIN_OBJECTS = ../FileDataReader.o ../DataManager.o

test: main.o TestReader.o $(MAIN_OBJECT)
	gcc -o test main.o TestReader.o $(MAIN_OBJECTS) -L${CPPUNIT_PATH}/lib -lstdc++ -lcppunit -ldl

TestReader.o: TestReader.cpp
	gcc -c TestReader.cpp -I${CPPUNIT_PATH}/include

main.o: main.cpp
	gcc -c main.cpp -I${CPPUNIT_PATH}/include

clean:
	rm -f *.o ftest
