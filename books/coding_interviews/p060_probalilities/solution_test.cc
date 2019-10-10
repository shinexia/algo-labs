#include "solution.h"
#include <cmath>
#include "glog/logging.h"
#include "gtest/gtest.h"
#include "mylib/util.h"

namespace {
struct TestCase {
    int number;
    int ret_code;
    int probs[100];
    int num_prob;
};

bool arrayEqual(std::vector<int> &a, int *b, int num_b) {
    if (a.size() != num_b) {
        return false;
    }
    for (int i = 0; i < num_b; ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

}  // namespace

TEST(codingInterviews, TestGetProbabilities) {
    TestCase cases[] = {
        {1, 0, {1, 1, 1, 1, 1, 1}, 6},
        {2,
         0,
         {
             1,
             2,
             3,
             4,
             5,
             6,
             5,
             4,
             3,
             2,
             1,
         },
         11},
        {3, 0, {1, 3, 6, 10, 15, 21, 25, 27, 27, 25, 21, 15, 10, 6, 3, 1}, 16},
        {4,
         0,
         {1,   4,   10,  20, 35, 56, 80, 104, 125, 140, 146,
          140, 125, 104, 80, 56, 35, 20, 10,  4,   1},
         21}};

    int N = sizeof(cases) / sizeof(TestCase);
    for (int i = 0; i < N; ++i) {
        auto &c = cases[i];
        int total = 0;
        std::vector<int> probs;
        int retCode = GetProbabilities(c.number, probs);
        for (auto &x : probs) {
            total += x;
        }
        EXPECT_EQ(retCode, c.ret_code) << "i: " << i;
        EXPECT_EQ(total, std::pow<int>(6, c.number));
        EXPECT_TRUE(arrayEqual(probs, c.probs, c.num_prob))
            << "probs: " << mylib::stringify(probs)
            << ", expect: " << mylib::stringify(c.probs, c.num_prob);
    }
    PrintProbability_Solution2(4);
}
