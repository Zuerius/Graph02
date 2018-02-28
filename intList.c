//intList.c
//Seth Crawford
//sacrawfo@ucsc.edu
//1304569


#include "intList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

   struct IntListNode{
      int element;
      IntList next;
   };
   
   const IntList intNil = NULL;

   typedef struct IntListNode IntListNode;

   int intFirst(IntList oldL){
      return oldL->element;
   }
   //should return the rest of the list
   IntList intRest(IntList oldL){
     return oldL->next;
   }
   //add new item
   IntList intCons(int newE, IntList oldL){
      IntList newL = calloc(1, sizeof(struct IntListNode));
      newL->element = newE;
      newL->next = oldL;
      return newL;
   }
/*   char* intListStr(IntList oldL){
      char* s; 
      s = "[";
      s = strcat (s, listToString("", oldL));
      return s;
      }
   
 char* listToString (char* prefix, IntList oldL){
      char* s;
      if(oldL == intNil){
         s = "]";
      }
      else{
         s = strcat(prefix, intFirst(oldL));
         s = strcar(s, listToString(",", intRest(oldL)));
      }
      return s;
}
*************************************************/
   
