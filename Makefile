FILENAME = g2dconvert
SRC = $(wildcard *.cpp) tests/G2dConvertTestSuite.cpp
OBJ = $(SRC:.cpp=.o)
ASSETS_DIR = assets
BUILD_DIR = build
TESTS_DIR = tests
TEST_INPUTS_DIR = $(TESTS_DIR)/inputs
TEST_EXPECTED_DIR = $(TESTS_DIR)/expected

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

	# Copy test assets into the build directory
	mkdir -p $(BUILD_DIR)/$(TESTS_DIR)/inputs
	mkdir -p $(BUILD_DIR)/$(TESTS_DIR)/expected
	cp -r $(TEST_INPUTS_DIR)/ $(BUILD_DIR)/$(TESTS_DIR)/
	cp -r $(TEST_EXPECTED_DIR)/ $(BUILD_DIR)/$(TESTS_DIR)/

%.o: %.cpp
	$(CXX) -std=c++20 -c $< -o $@
