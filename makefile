INCLUDE_DIRS = -Iinclude

CXXFLAGS += -O2 $(INCLUDE_DIRS) -pedantic -Wall -Wextra -std=c++20
CXXSRCS = $(shell find src/ -type f -name '*.cpp')
CXXSRCSTESTS = $(shell find tests/ -type f -name '*.cpp')
CXXOBJS = $(patsubst %cpp, %o, $(CXXSRCS))
CXXOBJSTESTS = $(patsubst %cpp, %o, $(CXXSRCSTESTS))

LFLAGS += -lg2d

TARGET = libg2dconvert.a
TARGET_TESTS = test
BIN_DST = bin/
LIB_DST = $(BIN_DST)lib/
TEST_DST = $(BIN_DST)test/
OBJ_DST = obj/

TEST_INPUTS_DIR = tests/inputs
TEST_EXPECTED_DIR = tests/expected

.PHONY: all $(TARGET_TESTS) $(TARGET_LIB) clean

# Default target to build everything
all: $(TARGET_LIB) $(TARGET_TESTS)

# Create the static library
$(TARGET): $(CXXOBJS)
	@mkdir -p $(BIN_DST)
	@mkdir -p $(LIB_DST)
	@ar rcs $(LIB_DST)$@ $(addprefix $(OBJ_DST), $(CXXOBJS))
	$(info Build done: $@)

# Create the test executable
$(TARGET_TESTS): $(CXXOBJSTESTS) $(TARGET)
	@mkdir -p $(TEST_DST)
	@$(CXX) $(addprefix $(OBJ_DST), $(CXXOBJSTESTS)) -L$(LIB_DST) -lg2dconvert $(LFLAGS) -o $(TEST_DST)$@
	
	@cp -r $(TEST_INPUTS_DIR) $(TEST_DST)
	@cp -r $(TEST_EXPECTED_DIR) $(TEST_DST)
	$(info Build done: $@)

%.o: %.cpp
	$(info Building Cpp: $@)
	@mkdir -p $(OBJ_DST)$(dir $@)
	@$(CXX) $(CXXFLAGS) $< -c -o $(OBJ_DST)$@

clean:
	@rm -rf $(OBJ_DST)
	@rm -rf $(BIN_DST)
	$(info Cleanup Done)