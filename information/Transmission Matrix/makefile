CC = g++
CXXFLAGS = -std=c++11 -Wpedantic -Wall -Wextra -Winit-self -Winline -Wconversion -Weffc++ -Wstrict-null-sentinel -Wold-style-cast -Wnoexcept -Wctor-dtor-privacy -Woverloaded-virtual -Wconversion -Wsign-promo
EXEC_NAME = matrix
OBJ_FILES = main.o MatrixCalculator.o

all : $(EXEC_NAME)

clean :
	rm $(EXEC_NAME) $(OBJ_FILES)

$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES)

%.o: %.cpp
	$(CC) $(CXXFLAGS) -o $@ -c $<

install :
	cp $(EXEC_NAME) $(INSTALL_DIR)