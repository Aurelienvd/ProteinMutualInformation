export CC = g++
export CXXFLAGS = -std=c++11 -Wpedantic -Wall -Wextra -Winit-self -Wconversion -Weffc++ -Wstrict-null-sentinel -Wctor-dtor-privacy -Woverloaded-virtual
EXEC_NAME = information
export LIBS = `pkg-config gtkmm-3.0 --cflags --libs`
INSTALL_DIR = ./exe
DATA_DIR = DataManaging
UI_DIR = ui

all : $(EXEC_NAME)

clean :
	@(cd $(DATA_DIR) && $(MAKE) $@)
	@(cd $(UI_DIR) && $(MAKE) $@)

$(EXEC_NAME) : $(OBJ_FILES)
	@(cd $(DATA_DIR) && $(MAKE))
	@(cd $(UI_DIR) && $(MAKE))

install :
	cp $(EXEC_NAME) $(INSTALL_DIR)