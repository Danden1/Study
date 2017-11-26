#include <stdio.h>
#include <unistd.h>
#include <poll.h>
#define TIMEOUT 5

int main(){
  struct pollfd fds[2];
  int ret;
  
  //표준 입력 감시
  
  fds[0].fd = STDIN_FILENO; //std input
  fds[0].events = POLLIN;
  
  //output
  fds[1].fd = STDOUT_FILENO;
  fds[1].events = POLLOUT;
  
  //준비 끝, 블록
  ret = poll (fds, 2, TIMEOUT * 1000);
  if(ret == -1){
      perror("poll");
    return 1;
  }
  
  if (!ret){
    printf( "%d sec elapsed.\n", TIMEOUT);
    return 0;
  }
  
  if (fds[0].revents &POLLIN)
    printf("stdin is readable\n");
    
  if (fds[1].revetns & POLLOUT)
    printf("stdout is writeable\n");
    
  return 0;
  
  }
    
