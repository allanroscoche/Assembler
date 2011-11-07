#include <stdio.h>
#include "read.h"
#include <stdlib.h>

#define D_MAX 5000
#define max_l 4

int main(void){

  ReadTable * table;
  table = createTable("solid.csfasta");
  unsigned int count=0;
  int stop;
  unsigned int i,j,k,l;
  unsigned int size;
  unsigned int max;

  size=table->size/2;
  /*
  for(l=1;l<=max_l;l++){
    table[l] = (ReadTable *) malloc (sizeof(ReadTable));
    table[l]->table = malloc(sizeof(Read *)*(size));
    table[l]->size = size;
    size = size/2;
    }*/

  unsigned int other_count=0;

  count = table->size;
  for(l=0;l<max_l;l++){
    size = count;
    count=0;
    k=1;
    while((size > 0) && (k<3)){
      for(i=0;i<size;i++){
        if(table->table[i] != NULL)
          for(j=i+1;(j<size)&&(j<(i+D_MAX));j++){
            if(table->table[j]!=NULL)
              if(comparador(table->table[i],table->table[j],k)){
                other_count++;
                size-=1;
                break;
              }
          }
      }
      k++;
    }
  }
  printf("count:%d\n",other_count);
  printf("end\n");

  count = countTable(table);
  printf("N:%d\n",count);

  // printTable(table[0]);
  //getchar();
  // */
  return 0;
}
