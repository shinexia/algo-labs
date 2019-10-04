#pragma once

bool Find(int* matrix, int rows, int colomns, int number) {
    if (matrix == nullptr || rows < 1 || colomns < 1) {
        return false;
    }
    bool found = false;
    int row = 0;
    int column = colomns - 1;
    do {
        auto val = matrix[row * colomns + column];
        if (number == val) {
            found = true;
            break;
        } else if (number < val) {
            --column;
        } else {
            ++row;
        }
    } while (row < rows && colomns >= 0);
    return found;
}
