#ifndef _CQUE_
#define _CQUE_

strcut Queue{
  int front;
  int rear;
  int queArr[100];
};

void QInit(Queue *q);
int DEqueue(Queue *q);
void Enqueue(Queue *q, int data);
#endif
