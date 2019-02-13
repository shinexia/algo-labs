
EXT_DIR = ../../build


CXXFLAGS += -g -Wall -Wextra -std=c++11 -pthread

LDFLAGS  += -I$(EXT_DIR)/include -L$(EXT_DIR)/lib -Wl,-rpath,$(EXT_DIR)/lib -lmyutil -lgtest -lgtest_main

TESTS=$(wildcard *_test.cc)
TARGETS=$(TESTS:.cc=)
RUNS=$(addprefix run_, $(TARGETS))
TEST_ARGS=

.PHONY: test $(RUNS)
test: $(RUNS)

%_test: %_test.cc %.o
	g++ $^ -o $@ $(LDFLAGS) $(CXXFLAGS)

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
