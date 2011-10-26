#include <stdio.h>
#include "read.h"
#include <stdlib.h>

#define D_MAX 5000

int main(void)
{
  ReadTable * table[5];
  table[0] = createTable("solid.csfasta");
  unsigned int count=0;
  int stop;
  unsigned int i,j,k,l;
  unsigned int size;
  unsigned int max;

  /*
  for(l=1;l<5;l++){
    table[l] = (ReadTable *) malloc (sizeof(ReadTable));
    table[l]->table = malloc(sizeof(Read *)*(table[0]->size));
    }*/
  unsigned int other_count=0;

  count = table[0]->size;
  max=count;
  for(l=0;l<1;l++){
    size = count;
    count=0;
    k=0;
    while((size > 0) && (k<10)){
      for(i=0;i<size;i++){
        if((i%1000000)==0)
          printf("%d of %d, count:%d\n",(i),max,other_count);
        if(table[l]->table[i] != NULL)
          for(j=i+1;(j<size)&&(j<(i+D_MAX));j++){
            if(table[l]->table[j]!=NULL)
              if(sobrepostos(table[l]->table[i],table[l]->table[j],k+1)){
                other_count++;
                //adiciona(table[l]->table[i],table[l]->table[j],k+1);
                //deleteRead(table[l]->table[j]);
                //table[l+1]->table[count++]=table[l]->table[i];
                //table[l]->table[i]=NULL;
                //table[l]->table[j]=NULL;
                //size-=1;
                break;
              }
          }
      }
      k++;
    }
    }
  printf("%d\n",other_count);
  printf("end\n");
  /*
  for(i=0;i<2;i++){
    count = countTable(table[i]);
    printf("N:%d\n",count);
  }
  */
  // printTable(table[0]);
  //getchar();
  // */
  return 0;
}
