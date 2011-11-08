#include <stdio.h>
#include "read.h"
#include <stdlib.h>

#define D_MAX 5000
#define max_l 3

int main(void){

  ReadTable * table;
  table = createTable("solid.csfasta");
  unsigned int count=0;
  int stop;
  int result;
  unsigned int i,j,k,l;
  unsigned int size,old_size;
  unsigned int max;

  old_size=table->size;
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
    k=0;
    while((size > 0) && (k<4)){
      for(i=0;i<size;i++){
        if((i % 90000) ==0)
          printf("%d%% of %d\n",i*100/size,k);
        if(table->table[i] != NULL){
          for(j=i+1;(j<size)&&(j<(i+D_MAX));j++){
            if(table->table[j]!=NULL){
              result = comparador(table->table[i],table->table[j],k);
              if(result>1){
                if(result == 2){
                  deleteRead(table->table[j]);
                  table->table[j] = NULL;
                  //size-=1;
                }
                other_count++;
                //size-=1;
                break;
              }
            }
          }
        }
      }
      k++;
    }
  }
  printf("count:%d\n",other_count);
  printf("end\n");

  count = countTable(table);
  printf("O:%d, N:%d\n",old_size, count);

  // printTable(table[0]);
  //getchar();
  // */
  return 0;
}
