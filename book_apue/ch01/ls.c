#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    fprintf(stderr, "usage: ls directory_name\n");
    exit(1);
  }
  char *dir_path = argv[1];
  
  DIR *dp;
  struct dirent *dirp;
  if ((dp = opendir(dir_path)) == NULL) {
    fprintf(stderr, "can't open %s, msg: %s\n", dir_path, strerror(errno));
    exit(1);
  }
  while((dirp = readdir(dp)) != NULL) {
    printf("%d %s\n", dirp->d_type, dirp->d_name);
  }
  closedir(dp);
  exit(0);
}
