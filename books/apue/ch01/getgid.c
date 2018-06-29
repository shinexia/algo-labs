#include <stdio.h>
#include <unistd.h>

int main(void) {
  printf("gid=%ld\n", (long)getgid());
}
