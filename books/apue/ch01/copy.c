
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFSIZE 4096

int main(int argc, char* argv[]) {
  if (argc != 1) {
    fprintf(stderr, "usage: ./copy < filepath\n");
    exit(1);
  }
  int n;
  char buf[BUFFSIZE];
  while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
    if (write(STDOUT_FILENO, buf, n) != n) {
      fprintf(stderr, "write error, msg:%s\n", strerror(errno));
      exit(1);
    }
  }
  if (n < 0) {
    fprintf(stderr, "read error, msg:%s\n", strerror(errno));
    exit(1);
  }
  exit(0);
}
