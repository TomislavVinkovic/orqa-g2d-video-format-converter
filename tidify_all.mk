TOOLCHAIN_PATH = /home/orqa2/data/immx8mp/SDK/sysroots/armv8a-poky-linux/usr

INCLUDE_DIRS = -Iinclude \
	-I$(TOOLCHAIN_PATH)/include \
	-I$(TOOLCHAIN_PATH)/include/c++/11.3.0 \
	-I$(TOOLCHAIN_PATH)/include/c++/11.3.0/aarch64-poky-linux

CXXFLAGS += -O3 $(INCLUDE_DIRS) -pedantic -Wall -Wextra -std=c++20 -D__aarch64__ -D__LP64__ \
	--gcc-toolchain=$(TOOLCHAIN_PATH)

SRCS1 = $(shell find include/ -type f -name '*.hpp')
SRCS2 = $(shell find src/ -type f -name '*.cpp')
TMPS = $(patsubst %hpp, %txt, $(SRCS1)) $(patsubst %cpp, %txt, $(SRCS2))

TEMP_DST = ct

.PHONY: tidify

tidify: $(TMPS)
	@find $(TEMP_DST) -name '*.txt' | xargs cat >> tidify_report.txt

%.txt: %.hpp
	@echo Checking $<
	@mkdir -p $(TEMP_DST)/$(dir $@)
	@clang-tidy --quiet --config-file=.clang-tidy $< -- $(CXXFLAGS) >> $(TEMP_DST)/$@ 2>/dev/null

%.txt: %.cpp
	@echo Checking $<
	@mkdir -p $(TEMP_DST)/$(dir $@)
	@clang-tidy --quiet --config-file=.clang-tidy $< -- $(CXXFLAGS) >> $(TEMP_DST)/$@ 2>/dev/null
