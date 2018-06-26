CC=gcc
CXX=g++

CFLAGS=-fPIC -g -O2 --std=c11 -I/usr/local/include -I.
CXXFLAGS=-fPIC -g -O2 --std=c++11 -I/usr/local/include -I. -I../../../cpp/include
LDFLAGS=-L/usr/local/lib -lgtest -lgtest_main -L../../../build -lmylib

TESTS=$(wildcard *_test.cc)
TARGETS=$(TESTS:.cc=)
RUNS=$(addprefix run_, $(TARGETS))

.PHONY: test $(RUNS)
test: $(RUNS)

run_max_subsequence_sum_test: max_subsequence_sum_test
	./$<

%_test: %_test.cc %.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^

.PHONY: clean
clean:
	rm -fr *_test *.dSYM *.o $(TARGETS)
