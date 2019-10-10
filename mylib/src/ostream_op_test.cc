#include "mylib/ostream_op.h"
#include "glog/logging.h"
#include "gtest/gtest.h"

TEST(mylib, StreamutilTest) {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    LOG(INFO) << vec;

    std::list<int> list;
    list.push_back(3);
    list.push_back(5);
    LOG(INFO) << list;

    std::map<std::string, int> map;
    map["a"] = 10;
    map["b"] = 20;
    LOG(INFO) << map;
}
