#ifndef _GRAPH_
#define _GRAPH_

#include "DLinkedList.h"

enum {A,B,C,D,E,F,G,H,I,J};

struct Graph{
  int numV;
  int numE;
  List *glist;
};

void GraphInit(Graph *g, int nv);
void GraphDestroy(Graph *g);
void AddEdge(Graph *g, int fromV, int toV);

#endif
