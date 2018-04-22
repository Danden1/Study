#ifndef _DFS_
#define _DFS_

#include "DLinkedList.h"

enum {A,B,C,D,E,F,G,H,I,J};

struct Graph{
  int numV;
  int numE;
  List *glist;
  int *visitInfo;
};

void GraphInit(Graph *g, int nv);
void GraphDestroy(Graph *g);
void AddEdge(Graph *g, int fromV, int toV);
void DFSshow(Graph *g, int startV);

#endif
