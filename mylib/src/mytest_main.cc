
#include <cstdio>
#include "glog/logging.h"
#include "gtest/gtest.h"
#include "valgrind/valgrind.h"

#ifdef ARDUINO
void setup() { testing::InitGoogleTest(); }

void loop() { RUN_ALL_TESTS(); }

#else

GTEST_API_ int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    google::InitGoogleLogging(argv[0]);
    FLAGS_logtostderr = true;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif
