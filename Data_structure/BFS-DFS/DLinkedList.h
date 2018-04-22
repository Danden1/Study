#ifndef _D_LIST_
#define _D_LIST_

strcut Node{
  int data;
  Node *next;
};

struct List{
  Node *head;
  Node *cur;
  Node *before;
  int count;
};

void ListInit(List *l);
void LInsert(List *l, int data);

int LFirst(List *l, int *data);
int LNext(List *l, int *data);

#endif
