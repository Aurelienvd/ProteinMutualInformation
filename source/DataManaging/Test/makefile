export CC = g++
export CXXFLAGS = -std=c++11 -Wpedantic -Wall -Wextra -Winit-self -Winline -Wconversion -Weffc++ -Wstrict-null-sentinel -Wold-style-cast -Wnoexcept -Wctor-dtor-privacy -Woverloaded-virtual -Wconversion -Wsign-promo
EXEC_NAME = information
export LIBS = `pkg-config gtkmm-3.0 --cflags --libs`
INSTALL_DIR = ./exe
TESTW_DIR = TestReader
TESTR_DIR = TestWriter

all : $(EXEC_NAME)

clean :
	@(cd $(TESTW_DIR) && $(MAKE) $@)
	@(cd $(TESTR_DIR) && $(MAKE) $@)

$(EXEC_NAME) : $(OBJ_FILES)
	@(cd $(TESTR_DIR) && $(MAKE))
	@(cd $(TESTW_DIR) && $(MAKE))

install :
	cp $(EXEC_NAME) $(INSTALL_DIR)