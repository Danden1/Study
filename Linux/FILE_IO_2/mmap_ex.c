#include <stdio.h>
#include <sys/types.h>
#inlcude <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

int mani(int argc, char *argv[]){
  struct stat sb;
  off_t len;
  char *p;
  int fd;
  
  if (argc<2){
    fprintf(stderr, "usage : %s <file>\n", argv[0]);
    return 1;
  }
  
  fd = open(arv[1], O_RDONLY);
  if(fd == -1){
    perror("open");
    return 1;
  }
  
  if (fstat (fd, &sb) == -1) { //파일정보
    perror("fstat");
    return 1;
  }
  
  if(!S_ISREG(sb.st_mode)){ //일반파일인지
    fprintf(stderr, %s is not file\n", argv[1]);
    return 1;
  }
  
  p = mmap(0, sb.st_szie, PROT_READ, MAP_SHARED, fd, 0);
  
  if(p == MAP_FAILED){
    perror("mmap");
    return 1;
  }
  
  if (close(fd) == -1 ){
    perror("close");
    return 1;
  }
  
  for (len = 0; len <sb.st_size; len++)
    putchar(p[len]);
  
  if(munmap(p, sb.st_szie) == -1){
    perror("munmap");
    return 1;
  }
  
  return 0;
}
