EXEC_NAME = protein
OBJ_FILES = main.o ProteinsContainerBuilder.o ProteinsContainer.o ProteinComplex.o GlobalProtein.o
INSTALL_DIR = ./exe

ifneq ($(CXXFLAGS),-std=c++11 -Wpedantic -Wall -Wextra -Winit-self -Wconversion -Weffc++ -Wstrict-null-sentinel -Wctor-dtor-privacy -Woverloaded-virtual)
	CXXFLAGS = -std=c++11
endif

ifneq ($(CC), g++)
	CC = g++
endif

all : $(EXEC_NAME)

clean :
	rm $(EXEC_NAME) $(OBJ_FILES)

$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES) $(LIBS)

%.o: %.cpp
	$(CC) $(CXXFLAGS) $(LIBS) -o $@ -c $<

install :
	cp $(EXEC_NAME) $(INSTALL_DIR)