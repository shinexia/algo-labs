#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
  if (argc != 1) {
    fprintf(stderr, "usage: ./copy_nobuf < filepath\n");
    exit(1);
  }
  int c;
  while((c = getc(stdin)) != EOF) {
    if(putc(c, stdout) == EOF) {
      fprintf(stderr, "write error, msg:%s\n", strerror(errno));
      exit(1);
    }
  }
  exit(0);
}
