CC=gcc
CXX=g++

MYUTIL_DIR=../../libutil
CFLAGS=-fPIC -g -O2 --std=c11 -I/usr/local/include -I.
CXXFLAGS=-fPIC -g -O2 --std=c++11 -I/usr/local/include -I. -I$(MYUTIL_DIR)/include
LDFLAGS=-L/usr/local/lib -lgtest -lgtest_main -L$(MYUTIL_DIR)/lib -lutil

TESTS=$(wildcard *_test.cc)
TARGETS=$(TESTS:.cc=)
RUNS=$(addprefix run_, $(TARGETS))
TEST_ARGS=

.PHONY: test $(RUNS)
test: $(RUNS)

%_test: %_test.o %.o test_main.cc
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^

.PHONY: clean
clean:
	rm -fr *.o *.dSYM $(TARGETS)

run_max_subsequence_sum_test: max_subsequence_sum_test
	./$< $(TEST_ARGS)

run_binary_search_test: binary_search_test
	./$< $(TEST_ARGS)

run_gcd_test: gcd_test
	./$< $(TEST_ARGS)

run_pow_test: pow_test
	./$< $(TEST_ARGS)
