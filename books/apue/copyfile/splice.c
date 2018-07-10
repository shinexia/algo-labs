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
    int pipefd[2];
    if (pipe(pipefd) < 0) {
        perror("pipe:");
        return -1;
    }
    int n;
    for (;;) {
        if ((n = splice(fd_in, NULL, pipefd[1], NULL, 4096,
                        SPLICE_F_MOVE | SPLICE_F_MORE)) < 0) {
            perror("splice fd_in:");
            return -1;
        }
        if (0 == n) {
            fprintf(stderr, "DONE\n");
            return 0;
        }
        if (splice(pipefd[0], NULL, fd_out, NULL, n,
                   SPLICE_F_MOVE | SPLICE_F_MORE) != n) {
            perror("splice fd_out:");
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
