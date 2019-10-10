#include "solution.h"
#include "cmath"
#include "glog/logging.h"
#include "mylib/util.h"

static int MaxPoint = 6;
static int g_maxValue = 6;

int GetProbabilities(int number, std::vector<int>& probs) {
    if (number < 1) {
        probs.clear();
        return -1;
    }
    int num_prob = number * (MaxPoint - 1) + 1;
    probs.resize(num_prob);
    std::vector<int> tmp(num_prob);
    int flag = number & 1;
    {
        std::vector<int>& a = flag == 1 ? probs : tmp;
        for (int i = 0; i < MaxPoint; ++i) {
            a[i] = 1;
        }
    }
    flag = 1 - flag;
    for (int n = 2; n <= number; ++n) {
        std::vector<int>& a = flag == 1 ? probs : tmp;
        std::vector<int>& b = flag == 1 ? tmp : probs;
        int max = (MaxPoint - 1) * n + 1;
        for (int k = 0; k < max; ++k) {
            a[k] = b[k];
            for (int j = 1; j < MaxPoint && j <= k; ++j) {
                a[k] += b[k - j];
            }
        }
        flag = 1 - flag;
    }
    return 0;
}

void PrintProbability_Solution2(int number) {
    if (number < 1) return;

    int* pProbabilities[2];
    pProbabilities[0] = new int[g_maxValue * number + 1];
    pProbabilities[1] = new int[g_maxValue * number + 1];
    for (int i = 0; i < g_maxValue * number + 1; ++i) {
        pProbabilities[0][i] = 0;
        pProbabilities[1][i] = 0;
    }

    int flag = 0;
    for (int i = 1; i <= g_maxValue; ++i) pProbabilities[flag][i] = 1;

    for (int k = 2; k <= number; ++k) {
        for (int i = 0; i < k; ++i) pProbabilities[1 - flag][i] = 0;

        for (int i = k; i <= g_maxValue * k; ++i) {
            pProbabilities[1 - flag][i] = 0;
            for (int j = 1; j <= i && j <= g_maxValue; ++j)
                pProbabilities[1 - flag][i] += pProbabilities[flag][i - j];
        }

        flag = 1 - flag;
    }

    LOG(INFO) << mylib::stringify(pProbabilities[flag] + number,
                                  (g_maxValue - 1) * number + 1);

    delete[] pProbabilities[0];
    delete[] pProbabilities[1];
}
