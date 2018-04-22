#include <stdio.h>
#include <stdlib.h>
#include <string.h>
=#include "DLinkedList.h"
#include "DFS.h"
#include "ArrayStack.h"


void GraphInit(Graph *g){
  g->glist = (List*)malloc(sizeof(List)*nv);
  g->numV= nv;
  g->numE = 0;
  
  for(int i =0; i <nv; i++)
    ListInit(&(g->glist[i]));
  
  g->visitInfo=(int*)malloc(sizeof(int) * g->numV);
  memset(g->visitInfo, 0, sizeof(int)*g->numV);
}

void GraphDestroy(Graph *g){
  if(g->glist !=NULL)
    free(g->glist);
  if(g->visitInfo != NULL)
    free(g->visitInfo);
}

void AddEdge(Graph *g, int fromV, int toV){
  LInsert(&(g->glist[fromV]), toV);
  LInsert(&(g->glist[toV]), fromV);
  g->numE+=1;
}

int VistiV(Graph *g, int visitV){
  if(g->visitInfo[visitV] == 0){
    g->visitInfo[visitV] = 1;
    printf("%c ", visitV+65);
    return 1;
  }
  return 0;
}

void DFSshow(Graph *g, int startV){ 
  Stack st;
  int visitV = startV;
  int nextV;
  
  StackInit(&st);
  VisitV(g, visitV);
  Push(&st, visitV);
  
  while(LFirst(&(g->glist[visitV]) == 1){
    int visitF = 0;
    
    if(VisitV(g,nextV) ==1){
      Push(&st, visitV);
      visitV = nextV;
      visitF = 1;
    }
    else{
      while(LNext(&(g->glist[visitV]), &nextV) ==1){
        if(VisitV(g, nextV) == 1){
          Push(&st, visitV);
          visitV = nextV;
          visitF = 1;
          break;
        }
      }
    }
    if(visitF == 0){
      if(SEmpty(&st) == 1)
        break;
      else
        visitV = Pop(&st);
    }
  }
    
    memset(g->visitInfo,0,sizeof(int)*g->numV);
}
    
