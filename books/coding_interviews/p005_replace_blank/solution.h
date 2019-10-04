#pragma once

int ReplaceBlank(char str[], int length) {
    int blankCount = 0;
    int strLength = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        ++strLength;
        if (str[i] == ' ') {
            ++blankCount;
        }
    }
    int totalLength = blankCount * 2 + strLength;
    if (totalLength > length) {
        return -1;
    }
    int i = strLength - 1;
    int j = totalLength - 1;
    while (i >= 0) {
        char c = str[i--];
        if (c == ' ') {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
        } else {
            str[j--] = c;
        }
    };
    return 0;
}
