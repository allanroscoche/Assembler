#include <stdio.h>
#include "read.h"

#define D_MAX 5000

int main(void)
{
  ReadTable * table;
  table = createTable("../data/test.in");
  unsigned int count=0;
  int stop;
  unsigned int i,j,k;
  unsigned int size = table->size;
  k=0;
  while((size > 0) && (k<3)){
    for(i=0;i<size;i++){
      if(table->table[i] != NULL)
        for(j=i+1;(j<size)&&(j<(i+D_MAX));j++){
          if(table->table[j]!=NULL)
            if(sobrepostos(table->table[i],table->table[j],k+1)){
              adiciona(table->table[i],table->table[j],k+1);
              deleteRead(table->table[j]);
              table->table[j]=NULL;
              //size-=1;
              break;
            }
        }
    }
    k++;
  }
  printf("end\n");
  count = countTable(table);
  printf("N:%d\n",count);
  printTable(table);
  //getchar();
  // */
  return 0;
}
