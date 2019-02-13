#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        return -1;
    }
    int fd;
    if ((fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0666)) < 0) {
        perror("open");
        return -1;
    }
    // replace standard output with output file
    if (dup2(fd, STDOUT_FILENO) < 0) {
        perror("dup2");
        close(fd);
        return -1;
    }
    // print to standard output
    printf("hello, world\n");
    close(fd);
    return 0;
}
