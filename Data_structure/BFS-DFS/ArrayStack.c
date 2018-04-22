#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"

void StackInit(Stack *st){
  st->topIndex = -1;
}

int SEmpty{
  if(st->topIndex == -1)
    return 1;
  else
    return 0;
}

void Push(Stack *st, int data){
  st->topIndex +=1;
  st->stackArr[st->topIndex] = data;
}

int Pop(Stack *st){
  int rIdx;
  
  if(SEmpty(st))
    exit(-1);
  rIdx = st->topIndex;
  topIndex -=1;
  return st->stackArr[rIdx];
}

