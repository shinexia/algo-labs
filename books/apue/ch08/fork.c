#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int globvar = 6;
char buf[] = "a write to stdout\n";

int main() {
  int var;
  pid_t pid;
  
  var = 88;
  if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1) {
    fprintf(stderr, "write error: %s\n", strerror(errno));
  }
  printf("before fork\n");

  if ((pid = fork()) < 0) {
    fprintf(stderr, "fork error: %s\n", strerror(errno));
  } else if (pid == 0) {
    /* child */
    globvar++;
    var++;
  } else {
    /* parrent */
    sleep(2);
  }

  printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);

  exit(0);
}