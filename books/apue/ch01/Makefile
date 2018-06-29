CC=gcc
CXX=g++

CFLAGS=-fPIC -g -O2 --std=c11 -I/usr/local/include -I.
CXXFLAGS=-fPIC -g -O2 --std=c++11 -I/usr/local/include -I. -I../../../cpp/include
LDFLAGS=-L/usr/local/lib -lgtest -lgtest_main -L../../../build -lmylib

SOURCES=$(wildcard *.c)
TARGETS=$(SOURCES:.c=)
RUNS=$(addprefix run_, $(TARGETS))

.PHONY: all
all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $^

gitignore:
	@echo $(addprefix '\n', $(TARGETS)) > .gitignore

.PHONY: clean
clean:
	rm -fr *_test *.dSYM *.o $(TARGETS)
