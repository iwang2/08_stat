#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
  int fd = open("blah.txt", O_CREAT | O_WRONLY, 0644);
  char stuff[256] = "The bird winged his test.\n";
  write(fd, stuff, 256);
  close(fd);
  
  struct stat sb;
  stat("blah.txt", &sb);
  
  printf("file size: %d\n", (int)sb.st_size);
  printf("permissions: %o\n", sb.st_mode);
  printf("time: %s", ctime(&sb.st_atime));
}
