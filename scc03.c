//graph02.c
//Seth Crawford
//sacrawfo@ucsc.edu
//1304569

#include <stdio.h>
//#include "intList.h"
#include <stdlib.h>
#include <string.h>
#include "loadGraph.h"


IntList* transposeGraph (IntList* origGraph, int n){
   IntList* transGraph = calloc(n, sizeof(IntList)); 
   int j;
   for(j = 0; j < n; j++){
      transGraph[j] = intNil;
   }
   for(j = 0; j < n; j++){
      IntList origTemp = origGraph[j];
      while(origTemp != intNil){
         int origElem = intFirst(origTemp);
         transGraph[origElem -1] = intCons(j+1, transGraph[origElem-1]);
         
         origTemp = intRest(origTemp);
      }
   }
   return transGraph;
}

void DFS(IntList* inGraph, int* dTime, int* fTime, int* parent, char* color, int* time, int currentNode, int *fStack ){
   color[currentNode] = 'g';
   *time = *time+1;
   dTime[currentNode] = *time;
   IntList temp = inGraph[currentNode];
   while ( temp != intNil){
      int edgeDest = intFirst(temp);
      //edgeDest is value not slot
      if(color[edgeDest-1] == 'w'){
         parent[edgeDest-1] = currentNode+1;
         
         DFS(inGraph, dTime, fTime, parent, color, time, edgeDest-1, fStack);
      }
      temp = intRest(temp);
      }
   *time = *time+1;
   fTime[currentNode] = *time;
   fStack[fTime[currentNode]] = currentNode+1;
   color[currentNode] = 'b';
   
}

//Setup for DFS
void dfsFunction(IntList* inGraph, int numVert){
   int time = 0;
   int dTime[numVert];
   int fTime[numVert];
   int parent[numVert];
   char color[numVert];
   int fStack[numVert*2];
   int i;
   for(i = 0; i <numVert; i++){
      color[i] = 'w';
   }
   for(i=0; i <2*numVert; i++){
      fStack[i] = 0;
   }
   for(i=0; i<numVert; i++){
      if(color[i] == 'w'){
         parent[i]=-1;
         DFS(inGraph, dTime, fTime, parent, color, &time, i,fStack);
      }
   }
   printf("\nV  dT  fT  P");
   for(i=0; i<numVert; i++){
      printf("\n%d  %d  %d  %d",i+1, dTime[i], fTime[i], parent[i]);
   }
   printf("\n\nFinish Stack\n");
   for(i=2*numVert; i>=0; i--){
      if(fStack[i] != 0){
         printf("%d ",fStack[i]);
      }
   }
   printf("\n\n");
}
//First node is in slot 0
//pass in slot number not vertex number.

void printElem(IntList l){
   if(l != intNil){
      printf("%d", intFirst(l));
   }
   return;
}

void printline(IntList l){
   if( l == intNil){
      printf("null\n");
    
   }
   else{
      IntList temp = l;
      printf("[");
      printElem(temp);
      temp = intRest(temp);
      while(temp != intNil){
         printf(", ");
         printElem(temp);
         temp = intRest(temp);
      }
      printf("]\n");
   }
   return;
}

/*
void initEdges(int num, IntList* array){
   int counter = 0;
   while (counter < num){
      array[counter] = intNil;
      counter++;
   }
   return;
}

int loadEdges (FILE *inFile, IntList* array, int n){
   int counter = 0;
   int x, y;
   while (fscanf(inFile, "%d %d",&x ,&y) !=EOF){
      IntList newL =  intCons(y, array[x-1]);
      array[x-1] = newL;
      counter++;
   }
   return counter;
}
*/
int main(int argc, char *argv[]){
   if(argc==0){
      printf("Please provide an input file. \n");
      return 0;
   }  
   

   char *file1 = argv[1];
   FILE *inFile; 
   inFile = fopen(file1, "r" );
//   printf("%s was used for input and was opened. \n", file1);
   
   int n;

   fscanf (inFile, "%d", &n);
   IntList* array = calloc(n, sizeof(IntList));
//   IntList* array[n];
//   puts("array made"); //debug
   
   initEdges(n, array);
//   puts("initEdges called"); //debug   
   int m;
   m = loadEdges(inFile, array, n);
//   puts("load edges called");
   int counter = 0;
   printf("n = %d\n",n);
   printf("m = %d\n",m);  
   while(counter < n){
      printf("%d ", counter+1);
      printline(array[counter]);
      counter++;
   }
   fclose(inFile);

   dfsFunction(array, n);

   printf("Transpose 1\n");
   IntList* transposedGraph = transposeGraph(array, n);
   int tCounter = 0;
   while (tCounter < n){
      printf ("%d ", tCounter+1);
      printline(transposedGraph[tCounter]);
      tCounter++;
   }
   dfsFunction(transposedGraph, n);
/*   printf("Transpose 2 \n");
   IntList* transposedGraph1 = transposeGraph(transposedGraph, n);
   tCounter = 0;
   while (tCounter <n){
      printf("%d ", tCounter+1);
      printline(transposedGraph1[tCounter]);
      tCounter++;
   }
   printf("Tranpose 3 \n");
   IntList* transposedGraph2 = transposeGraph(transposedGraph1,n);
   tCounter = 0;
      while(tCounter < n){
      printf("%d ", tCounter+1);
      printline(transposedGraph2[tCounter]);
      tCounter++;
   }
*/
return 0;   
}

