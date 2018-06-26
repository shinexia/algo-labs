CC=gcc
CXX=g++

CFLAGS=-fPIC -g -O2 --std=c11 -I/usr/local/include -I./include
CXXFLAGS=-fPIC -g -O2 --std=c++11 -I/usr/local/include -I./include
TEST_LDFLAGS=-L/usr/local/lib -lgtest -lgtest_main

OUT_DIR=../build
SRC_DIR=src

SRC_CPP=$(wildcard src/*.cc)
OUT_OBJ=$(patsubst $(SRC_DIR)/%,$(OUT_DIR)/%,$(SRC_CPP:.cc=.o))

$(OUT_DIR)/libmylib.a: $(OUT_OBJ)
	$(shell mkdir -p $(OUT_DIR))
	ar rcs $@ $^

$(OUT_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CXX) $(CXXFLAGS) -c $^ -o $@

.PHONY: clean
clean:
	rm -fr *_test *.dSYM *.o $(OUT_DIR)/*
