#include <stdio.h>

int mian(){
  FILE *in, *out;
  
  struct pirate{
    char name[100];
    unsigned long booty;
    unsigned int beard_len;
  } p , blackbeard = {"Edward", 950, 40};
  
  out = fopen("data", "w");
  if(!out){
    perror("fopen");
    return 1;
  }
  
  if(!fwrite (&blackbeard, sizeof(struct pirate), 1, out)){
    perror("fwrite");
    return 1;
  }
  
  if(fclose(out)){
    perror("fclose");
    return 1;
  }
  
  in = fopen("data", "r");
  if(!in){
    perror("fopen");
    return 1;
  }
  
  if(fclose(in)){
    perror("fclose")'
    return 1;
  }
  
  printf ("name = %s, booty = &lu beard_len = &u\n", p.name, p.booty, p.beard_len);
  
  return 0;

}