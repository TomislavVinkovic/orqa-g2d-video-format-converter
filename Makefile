FILENAME = g2dconvert
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
ASSETS_DIR = assets
BUILD_DIR = build

all: compile build

clean:
	rm -f $(FILENAME)
	rm -f $(OBJ)
	rm -rf $(BUILD_DIR)

compile: $(OBJ)
	$(CXX) -no-pie -lg2d $(OBJ) -o $(FILENAME)
	

build: compile
	rm -rf $(BUILD_DIR)/*
	mkdir -p $(BUILD_DIR)
	# Copy the executable to the build directory
	cp $(FILENAME) $(BUILD_DIR)/
	rm -f $(FILENAME)
	# Copy everything from the assets directory to the build directory
	# cp -r $(ASSETS_DIR)/* $(BUILD_DIR)/

%.o: %.cpp
	$(CXX) -std=c++20 -c $< -o $@
