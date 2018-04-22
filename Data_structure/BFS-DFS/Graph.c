#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "DLinkedList.h"

void GraphInit(Graph *g){
  g->glist = (List*)malloc(sizeof(List)*nv);
  g->numV= nv;
  g->numE = 0;
  
  for(int i =0; i <nv; i++)
    ListInit(&(g->glist[i]));
}

void GraphDestroy(Graph *g){
  if(g->glist !=NULL)
    free(g->glist);
}

void AddEdge(Graph *g, int fromV, int toV){
  LInsert(&(g->glist[fromV]), toV);
  LInsert(&(g->glist[toV]), fromV);
  g->numE+=1;
}

