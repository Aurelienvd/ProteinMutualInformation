CC = g++
CXXFLAGS = -std=c++11 -Wpedantic -Wall -Wextra -Winit-self -Winline -Wconversion -Weffc++ -Wstrict-null-sentinel -Wold-style-cast -Wnoexcept -Wctor-dtor-privacy -Woverloaded-virtual -Wconversion -Wsign-promo
EXEC_NAME = information
LIBS = `pkg-config gtkmm-3.0 --cflags --libs`
OBJ_FILES = gAPP.o
INSTALL_DIR = ./exe

all : $(EXEC_NAME)

clean :
	rm $(EXEC_NAME) $(OBJ_FILES)

$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES) $(LIBS)

%.o: %.cpp
	$(CC) $(CXXFLAGS) $(LIBS) -o $@ -c $<

install :
	cp $(EXEC_NAME) $(INSTALL_DIR)