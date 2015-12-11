export CC = g++
export CXXFLAGS = -std=c++11 -Wpedantic -Wall -Wextra -Winit-self -Winline -Wconversion -Weffc++ -Wstrict-null-sentinel -Wold-style-cast -Wnoexcept -Wctor-dtor-privacy -Woverloaded-virtual -Wconversion -Wsign-promo
INSTALL_DIR = ./exe
EXEC_NAME = information
MUTUAL_DIR = Mutual\ Information
ROOT_DIR = RootFinder
TRANSMISSION_DIR = Transmission\ Matrix

all : $(EXEC_NAME)

clean :
	@(cd $(MUTUAL_DIR) && $(MAKE) $@)
	@(cd $(ROOT_DIR) && $(MAKE) $@)
	@(cd $(TRANSMISSION_DIR) && $(MAKE) $@)

$(EXEC_NAME) : $(OBJ_FILES)
	@(cd $(MUTUAL_DIR) && $(MAKE))
	@(cd $(ROOT_DIR) && $(MAKE))
	@(cd $(TRANSMISSION_DIR) && $(MAKE))

install :
	cp $(EXEC_NAME) $(INSTALL_DIR)