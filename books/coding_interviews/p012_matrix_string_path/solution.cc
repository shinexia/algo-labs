#include "solution.h"
#include <cstring>
#include "mylib/util.h"

static const int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool backt(char* matrix, int rows, int cols, char* str, bool* board, int i,
           int j) {
    char start = str[0];
    for (int k = 0; k < 4; ++k) {
        const int* direction = directions[k];
        int x = i + direction[0];
        int y = j + direction[1];
        if (0 <= x && x < rows && 0 <= y && y < cols) {
            int idx = x * cols + y;
            if (board[idx] == false && matrix[idx] == start) {
                if (str[1] == '\0') {
                    return true;
                }
                board[idx] = true;
                if (backt(matrix, rows, cols, str + 1, board, x, y)) {
                    return true;
                }
                board[idx] = false;
            }
        }
    }
    return false;
}

bool HasPath(char* matrix, int rows, int cols, char* str) {
    char start = str[0];
    if (start == '\0') {
        return true;
    }
    if (rows < 1 || cols < 1) {
        return false;
    }
    int N = rows * cols;
    bool* board = new bool[N];
    memset(board, 0, N);
    mylib::deleted_unique_ptr<bool> board_s(board, [](bool* t) { delete[] t; });
    for (int i = 0; i < rows; ++i) {
        auto base = i * cols;
        for (int j = 0; j < cols; ++j) {
            if (matrix[base + j] == start) {
                if (str[1] == '\0') {
                    return true;
                }
                board[base + j] = true;
                if (backt(matrix, rows, cols, str + 1, board, i, j)) {
                    return true;
                }
                board[base + j] = false;
            }
        }
    }
    return false;
}
