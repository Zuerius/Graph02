//loadGraph.h
//
#include "intList.h"

#include <stdio.h>
#include <stdlib.h>
#ifndef loadGraph
#define loadGraph

int loadEdges (FILE *inFile, IntList* array, int n);



void initEdges (int num, IntList* array);


//Edge parseEdge (char line[]);



#endif
