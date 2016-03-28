SOURCES=$(shell find . -name "*.cpp")
OBJECTS=$(SOURCES:%.cpp=%.o)
TARGET=protein_information
CXXFLAGS = -std=c++11 -Wpedantic -Wall -Wextra -Winit-self -Wconversion -Weffc++ -Wstrict-null-sentinel -Wctor-dtor-privacy -Woverloaded-virtual
CPPUNIT_PATH=/usr/include/cppunit
GSL = `gsl-config --cflags --libs`

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJECTS)
		$(LINK.cpp) $^ $(LOADLIBES) $(LDLIBS) $(CXXFLAGS) $(GSL) -L${CPPUNIT_PATH}/lib -lstdc++ -lcppunit -ldl -o $@

.PHONY: clean
clean:
		rm -f $(TARGET) $(OBJECTS)