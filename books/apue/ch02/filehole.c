#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main() {
    int fd;
    if ((fd = creat("filehole.log", FILE_MODE)) < 0) {
        fprintf(stderr, "creat error %s\n", strerror(errno));
        exit(-1);
    }
    if (write(fd, buf1, sizeof(buf1)) != sizeof(buf1)) {
        fprintf(stderr, "buf1 write error %s\n", strerror(errno));
        exit(-1);
    }
    if (lseek(fd, 16384, SEEK_SET) == -1) {
        fprintf(stderr, "lseek error %s\n", strerror(errno));
        exit(-1);
    }
    if (write(fd, buf2, sizeof(buf2)) != sizeof(buf2)) {
        fprintf(stderr, "buf2 write error %s\n", strerror(errno));
        exit(-1);
    }
    exit(0);
}
