#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/uio.h>

int main(){
  char ch1[10], ch2[10], ch3[10];
  struct iovec iov[3];
  ssize_t nr;
  int fd, i;
  
  fd = open("data.txt", O_RDONLY);
  
  if (fd == -1){
    perror("open");
    return 1;
  }
  
  iov[0].iov_base = ch1;
  iov[0].iov_len = sizeof(ch1);
  iov[1].iov_base = ch2;  
  iov[1].iov_len = sizeof(ch2);
  iov[2].iov_base = ch3;  
  iov[2].iov_len = sizeof(ch3);
  
  nr = readv(fd, iov, 3);
  if(nr == -1){
    perror("readv");
    return 1;
  }
  
  for (i = 0; i <3; i++)
    printf ("%d: %s", i, (char*) iov[i].iov_base);
    
  if (close(fd)){
    perror("close");
    return 1;
  }
  
  return 0;

}
