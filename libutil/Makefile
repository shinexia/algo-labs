CC=gcc
CXX=g++

CFLAGS=-fPIC -g -O2 --std=c11 -I/usr/local/include -I./include
CXXFLAGS=-fPIC -g -O2 --std=c++11 -I/usr/local/include -I./include
TEST_LDFLAGS=-L/usr/local/lib -lgtest -lgtest_main

SRC_DIR=src
DIST_DIR=lib

SRC_CPP=$(wildcard src/*.cc)
OUT_OBJ=$(SRC_CPP:.cc=.o)

$(DIST_DIR)/libutil.so: $(OUT_OBJ) | $(DIST_DIR)
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
distclean:
	rm -fr $(DIST_DIR)/*
