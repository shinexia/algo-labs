
CFLAGS=-fPIC -g -std=c11 -I/usr/local/include -I./include
CXXFLAGS=-fPIC -g -std=c++11 -I/usr/local/include -I./include

DIST_DIR  := lib
BUILD_DIR := .
TARGET    := $(notdir $(PWD))

SRC_CPP := $(shell find src/ ! -name "*_test.cc" -name "*.cc")
OUT_OBJ := $(SRC_CPP:.cc=.o)

$(DIST_DIR)/lib$(TARGET).so: $(OUT_OBJ) | $(DIST_DIR)
	ar rcs $@ $^

$(BUILD_DIR)/%.o: %.cc | $(BUILD_DIR)/src
	$(CXX) $(CXXFLAGS) -c $^ -o $@

$(DIST_DIR):
	$(shell mkdir -p $(DIST_DIR))

test:
	echo "not implemented"

.PHONY: clean
clean:
	rm -fr src/*.o src/*.dSYM

.PHONY: distclean
distclean: clean
	rm -fr $(DIST_DIR)/*
