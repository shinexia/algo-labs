#define _GNU_SOURCE
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    int in;
    if (argc == 1) {
        in = STDIN_FILENO;
    } else if (argc == 2) {
        if ((in = open(argv[1], O_RDONLY)) < 0) {
            perror("open");
            return -1;
        }
    } else {
        fprintf(stderr, "usage: %s file\n", argv[0]);
        return -1;
    }
    if (tee(in, STDOUT_FILENO, INT_MAX, SPLICE_F_NONBLOCK) < 0) {
        perror("tee");
        return -1;
    }
    close(in);
    return 0;
}
