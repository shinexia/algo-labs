#include "solution.h"
#include "glog/logging.h"
#include "gtest/gtest.h"

TEST(codingInterviews, TestCQueue) {
    CQueue<int> q;
    q.appendTail(1);               // 0, 1
    q.appendTail(2);               // 0, 2
    EXPECT_EQ(q.deleteHead(), 1);  // 1, 0
    EXPECT_EQ(q.deleteHead(), 2);  // 0, 0
    q.appendTail(3);               // 0, 1
    EXPECT_EQ(q.deleteHead(), 3);  // 0, 0
    q.appendTail(4);               // 0, 1
    q.appendTail(5);               // 0, 2
    q.appendTail(6);               // 0, 3
    EXPECT_EQ(q.deleteHead(), 4);  // 2, 0
    q.appendTail(7);               // 2, 1
    q.appendTail(8);               // 2, 2
    EXPECT_EQ(q.deleteHead(), 5);  // 1, 2
    EXPECT_EQ(q.deleteHead(), 6);  // 0, 2
    EXPECT_EQ(q.deleteHead(), 7);  // 1, 0
    EXPECT_EQ(q.deleteHead(), 8);  // 0, 0

    EXPECT_THROW(q.deleteHead(), std::exception);
}
