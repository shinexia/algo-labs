#include <stdio.h>
#include <unistd.h>

int main(void) {
  pid_t pid = getpid();
  printf("hello world from process ID %ld\n", (long)pid);
}
