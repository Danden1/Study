#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList"

void ListInit(List *l){
  l->head = (Node*)malloc(sizeof(Node));
  l->head->next = NULL;
  l->count = 0;
}

void LInsert(List *l, int data){
  Node *newnode = (Node*)malloc(sizeof(Node));
  newnode->data = data;
  newnode->next = l->head->next;
  l->head->next = newnode;

  (l->count)++;
}

int LFirst(List *l, int *data){
  if(l->head->next == NULL)
    return 0;
  l->before = l->head;
  l->cur = l->cur->next;
  
  *data = l->cur->data;
  return 1;
}

int LNext(List *l, int *data){
  if(l->cur->next == NULL)
    return 0;
  l->before = l->cur;
  l->cur = l->cur->next;
  
  *data = l->cur->data;
  
  return 1;
  
}
