#include <stdio.h>
#include <stdlib.h>
#include "CQue.h"

void QInit(Queue *q){
  q->front = 0;
  q->rear = 0;
}

int QEmpty(Queue *q){
  if(q->front == q->rear)
    return 1;
  else
    return 0;
}

int NextIdx(int pos){
  if(pos == 100-1)//end
    return 0;
  else 
    return pos +1;
}

void Enqueue(Queue *q, int data){
  if(NextIdx(q->rear) == q->front)
    exit(-1);
  q->rear = NextIdx(q->rear);
  q->queArr[q->rear] = data;
}

int Dequeue(Queue *q){
  if(QEmpty(q))
    exit(-1);
  q->front = NextIdx(q->front);
  return q->queArr[q->front];
}

