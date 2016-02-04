EXEC_NAME = root
LIBS = `gsl-config --cflags --libs`
OBJ_FILES = main.o RootFinder.o

all : $(EXEC_NAME)

clean :
	rm $(EXEC_NAME) $(OBJ_FILES)

$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES) $(LIBS)

%.o: %.cpp
	$(CC) $(CXXFLAGS) $(LIBS) -o $@ -c $<

install :
	cp $(EXEC_NAME) $(INSTALL_DIR)