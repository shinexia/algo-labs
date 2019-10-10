#include "solution.h"
#include "glog/logging.h"
#include "gtest/gtest.h"
#include "mylib/util.h"

namespace {
struct MaxInWindowTestCase {
    int nums[20];
    int num_len;
    int winsize;
    int expect[20];
};

template <typename T>
bool is_equal(const std::vector<T>& out, T* expect, int expect_size) {
    if (out.size() != expect_size) {
        return false;
    }
    for (int i = 0; i < expect_size; ++i) {
        if (out[i] != expect[i]) {
            return false;
        }
    }
    return true;
}
}  // namespace

TEST(codingInterviews, TestMaxInWindow) {
    MaxInWindowTestCase cases[] = {
        {{2, 3, 4, 2, 6, 2, 5, 1}, 8, 3, {4, 4, 6, 6, 6, 5}},
    };
    int N = sizeof(cases) / sizeof(MaxInWindowTestCase);
    for (int i = 0; i < N; ++i) {
        auto& c = cases[i];
        std::vector<int> vec(c.num_len);
        for (int k=0; k<c.num_len; ++k) {
            vec[k] = c.nums[k];
        }
        auto out = MaxInWindow(vec, c.winsize);
        int expect_size = c.num_len - c.winsize + 1;
        EXPECT_TRUE(is_equal(out, c.expect, expect_size))
            << "out: " << mylib::stringify(out, out.size())
            << ", expect: " << mylib::stringify(c.expect, expect_size);
    }
}

namespace {
struct Step {
    // 1: insert, -1: pop, 0: stop
    int op;
    int number;
    int max;
};

struct TestCase {
    Step steps[40];
};
}  // namespace

TEST(codingInterviews, TestQueueWithMax) {
    TestCase cases[] = {{{{1, 2, 2},
                          {1, 3, 3},
                          {1, 4, 4},
                          {1, 2, 4},
                          {1, 6, 6},
                          {1, 2, 6},
                          {1, 5, 6},
                          {1, 1, 6},
                          {-1, 2, 6},
                          {-1, 3, 6},
                          {-1, 4, 6},
                          {-1, 2, 6},
                          {-1, 6, 5},
                          {-1, 2, 5},
                          {-1, 5, 1},
                          {0, 0, 0}}}};

    int N = sizeof(cases) / sizeof(TestCase);
    for (int i = 0; i < N; ++i) {
        auto& c = cases[i];
        QueueWithMax<int> q;
        int j = 0;
        while (true) {
            Step step = c.steps[j];
            if (step.op == 0) {
                break;
            } else if (step.op == 1) {
                q.push_back(step.number);
            } else {
                int number = q.pop_front();
                EXPECT_EQ(number, step.number)
                    << "i: " << i << ", j: " << j << ", op: " << step.op
                    << ", number: " << step.number;
                if (number != step.number) {
                    return;
                }
            }
            EXPECT_EQ(q.max(), step.max)
                << "i: " << i << ", j: " << j << ", op: " << step.op
                << ", number: " << step.number;
            if (q.max() != step.max) {
                return;
            }
            ++j;
        }
    }
}
