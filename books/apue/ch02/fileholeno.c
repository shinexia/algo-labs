#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main() {
    int fd;
    if ((fd = creat("fileholeno.log", FILE_MODE)) < 0) {
        fprintf(stderr, "creat error %s\n", strerror(errno));
        exit(-1);
    }
    ssize_t N = 16384;
    char buf0[N];
    ssize_t N1 = sizeof(buf1);
    for (int i = 0; i < N1; i++) {
        buf0[i] = buf1[i];
    }
    for (int i = N1; i < N; i++) {
        buf0[i] = '.';
    }
    if (write(fd, buf0, N) != N) {
        fprintf(stderr, "buf0 write error %s\n", strerror(errno));
        exit(-1);
    }
    if (write(fd, buf2, sizeof(buf2)) != sizeof(buf2)) {
        fprintf(stderr, "buf2 write error %s\n", strerror(errno));
        exit(-1);
    }
    exit(0);
}
