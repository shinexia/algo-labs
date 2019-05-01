//
// Created by shine on 3/21/19.
//

#include <string>
#include <vector>
#include <thread>

void proc(const std::string& str1, const std::string& str2)
{
    while (true) {
        std::equal(str1.begin(), str1.end(), str2.begin());
    }
}

int main() {
    size_t thread_num = 50;

    std::string str1 = "abcdef";
    std::string str2 = "abcdef";

    std::vector<std::thread> threads(thread_num);

    for (size_t i=0; i< thread_num; ++i) {
        threads[i] = std::thread(proc, str1, str2);
    }

    for (auto& t : threads) {
        t.join();
    }
}
