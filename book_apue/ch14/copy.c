#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

#define BUFSIZE (500 * 1000)

void set_fl(int fd, int flags);
void clr_fl(int fd, int flags);

int main(void) {
    char buf[BUFSIZE];
    int ntowrite, nwrite;

    ntowrite = read(STDIN_FILENO, buf, sizeof(buf));
    fprintf(stderr, "read %d bytes\n", ntowrite);

    set_fl(STDOUT_FILENO, O_NONBLOCK);

    char* ptr = buf;
    while (ntowrite > 0) {
        errno = 0;
        nwrite = write(STDOUT_FILENO, ptr, ntowrite);
        fprintf(stderr, "nwrite = %d, errno = %d\n", nwrite, errno);
        if (nwrite > 0) {
            ptr += nwrite;
            ntowrite -= nwrite;
        }
    }
    clr_fl(STDOUT_FILENO, O_NONBLOCK);
    return 0;
}

void set_fl(int fd, int flags) {
    int val;
    if ((val = fcntl(fd, F_GETFL, 0)) < 0) {
        perror("fcntl F_GETFL");
        exit(-1);
    }
    val |= flags;
    if (fcntl(fd, F_SETFL, val) < 0) {
        perror("fcntl F_SETFL");
        exit(-1);
    }
}

void clr_fl(int fd, int flags) {
    int val;
    if ((val = fcntl(fd, F_GETFL, 0)) == -1) {
        perror("fcntl F_GETFL");
        exit(-1);
    }
    val &= ~flags;
    if (fcntl(fd, F_SETFL, val) == -1) {
        perror("fcntl F_SETFL");
        exit(-1);
    }
}
