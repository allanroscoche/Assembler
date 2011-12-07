#include <stdio.h>
#include "read.h"
#include <stdlib.h>


#ifdef _OPENMP
#define TRUE 1
#define FALSE 0
#include <omp.h>
#endif

#define D_MAX 500
#define max_l 1



int main(void)
{
#ifdef _OPENMP
  (void) omp_set_dynamic(FALSE);
  if (omp_get_dynamic()) {printf("Warning: dynamic adjustment of threads has been set\n");}
  (void) omp_set_num_threads(4);
#endif
  ReadTable * table;

  printf("Carregando..\n");
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
  printf("Comparando..\n");
  count = table->size;
  for(l=0;l<max_l;l++){
    size = count;
    count=0;
    k=0;
#pragma omp parallel default(none) shared(k,table,size) private(i,j,result)
    {
    while((size > 0) && (k<1)){
#pragma omp for
      for(i=0;i<size;i++){
        //if((i % 90000) ==0)
        //  printf("%d of %d%%\n",other_count,i*100/size);
        if(table->table[i] != NULL){
          for(j=i+1;(j<size)&&(j<(i+D_MAX));j++){
            if(table->table[j]!=NULL){
              result = comparador(table->table[i],table->table[j],k);
              if(result>1){
                //other_count++;
                if(result == 2){
                  deleteRead(table->table[j]);
                  table->table[j] = NULL;
                  //size-=1;
                  //break;
                }
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
