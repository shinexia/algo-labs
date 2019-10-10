#include "solution.h"
#include "gtest/gtest.h"

TEST(codingInterviews, TestDynamicArray) {
    DynamicArray<int> data;
    data.Insert(10);
    EXPECT_DOUBLE_EQ(data.getMedian(), 10.0);
    data.Insert(11);
    EXPECT_DOUBLE_EQ(data.getMedian(), 10.5);
    data.Insert(9);
    EXPECT_DOUBLE_EQ(data.getMedian(), 10);
    data.Insert(12);
    EXPECT_DOUBLE_EQ(data.getMedian(), 10.5);
    data.Insert(13);
    EXPECT_DOUBLE_EQ(data.getMedian(), 11);
}