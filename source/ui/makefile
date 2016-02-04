EXEC_NAME = information
OBJ_FILES = gAPP.o MainWindow.o
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