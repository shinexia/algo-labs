#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

static int splice_copy(int fd_in, int fd_out) {
    char buf[4096];
    int bytes;
    while ((bytes = read(fd_in, buf, sizeof(buf))) > 0) {
        if (write(fd_out, buf, bytes) != bytes) {
            fprintf(stderr, "write fd_out error, msg: %s\n", strerror(errno));
            return -1;
        }
    }
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "usage %s <from> <to>\n", argv[0]);
        exit(-1);
    }
    char* file_from = argv[1];
    char* file_to = argv[2];

    int fd_in;
    int fd_out;

    if ((fd_in = open(file_from, O_RDONLY)) < 0) {
        fprintf(stderr, "open file from failed, msg: %s\n", strerror(errno));
        exit(-1);
    }

    if ((fd_out = open(file_to, O_WRONLY | O_TRUNC | O_CREAT, 0644)) < 0) {
        fprintf(stderr, "open file to failed, msg: %s\n", strerror(errno));
        close(fd_in);
        exit(-1);
    }

    int rc = splice_copy(fd_in, fd_out);

    close(fd_in);
    close(fd_out);

    exit(rc);
}
