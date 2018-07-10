#define _GNU_SOURCE

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

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
        fprintf(stderr, "usage: %s <file>\n", argv[0]);
        return -1;
    }

    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe:");
        return -1;
    }
    int n;
    for (;;) {
        if ((n = splice(in, NULL, pipefd[1], NULL, 1024,
                        SPLICE_F_MOVE | SPLICE_F_MORE)) < 0) {
            perror("splice stdin:");
            return -1;
        }
        if (0 == n) {
            return 0;
        }
        if ((splice(pipefd[0], NULL, STDOUT_FILENO, NULL, n,
                    SPLICE_F_MOVE | SPLICE_F_MORE)) != n) {
            perror("splice stdout:");
            return -1;
        }
    }
    return 0;
}
