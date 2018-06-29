#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>

#define MAXLINE 255

static void sig_int(int);

int main(void) {
  char buf[MAXLINE];
  pid_t pid;
  int status;

  if (signal(SIGINT, sig_int) == SIG_ERR) {
    fprintf(stderr, "signal error, msg:%s\n", strerror(errno));
    exit(1);
  }

  printf("%% ");
  while(fgets(buf, MAXLINE, stdin) != NULL) {
    int N = strlen(buf);
    if (N <= 1) {
      printf("%% ");
      continue;
    }
    if (buf[N - 1] == '\n') {
      buf[N - 1] = 0;
    }
    if((pid = fork()) < 0) {
      perror("fork error");
      exit(1);
    } else if (pid == 0) {
      /* child */
      execlp(buf, buf, (char* )0);
      fprintf(stderr, "couldn't execute: %s, msg:%s\n", buf, strerror(errno));
      exit(127);
    }
    /* parent */
    if ((pid = waitpid(pid, &status, 0)) < 0) {
      perror("waitpid error");
      exit(1);
    }
    printf("%% ");
  }
}

void sig_int(int signo) {
  printf("interrupted signo=%d\n%% ", signo);
}