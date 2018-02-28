//loadGraph.c



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loadGraph.h"
/*
int LoadEdges (File*inFile, IntList* array, int n);
void initEdges (int num, IntList* array);
*/
int loadEdges (FILE *inFile, IntList* array, int n){
   int counter = 0;
   int x, y;
   while (fscanf(inFile, "%d %d",&x, &y) != EOF){
      IntList newL = intCons(y, array[x-1]);
      array[x-1] = newL;
      counter++;
   }
   return counter;
}

void initEdges (int num, IntList* array){
   int counter = 0;
   while(counter < num){
      array[counter] = intNil;
      counter++;
   }
   return;
}

/*Edge parseEdge(char line[]){
   Edge newE;
   int numFields;
       numFields = sscanf(line, " %d %d %lf %*s", &newE.from, &newE.to, &newE.weight);
   if (numFields < 2 || numFields > 3){
      printf("Bad edge: %s", line);
      exit(1);
      }
   if (numFields == 2){
      newE.weight = 0.0;
   }
   return newE;
}*/
