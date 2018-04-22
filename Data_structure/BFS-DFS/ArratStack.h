#ifndef _AS_
#define _AS_

struct Stack{
  int StackArr[100];
  int topIndex;
};

void StackInit(Stack *st);
int SEmpty(Stack *st);
void Push(Stack *st. int data);
int Pop(Stack *st);

#endif
