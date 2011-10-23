#include <stdio.h>
#include "read.h"

int main(void)
{
  /*
  Read * seq1;
  unsigned char sequencia1[] = "AGCTTTTCATTCTGACTGCAACGGGCAATAA";
  seq1 = createRead(sequencia1);
  print(seq1);

  Read * seq2;
  unsigned char  sequencia2[] = "GCTTTTCATTCTGACTGCAACGGGCAATAAG";
  seq2 = createRead(sequencia2);
  print(seq2);

  Read * seq3;
  unsigned char  sequencia3[] = "ccgtccgtacgttatg";
  seq3 = createRead(sequencia3);
  print(seq3);

  printf("result:%d\n",sobrepostos(seq1,seq2,1));
  //printf("result:%d\n",sobrepostos(seq2,seq3,1));

  //adiciona(seq1,seq2,10);

  //printf("s1:%d\n",(int)seq1);
  //deleteRead(seq1);
  //free(seq1);
  //seq1=NULL;
  //printf("s1:%d\n",(int)seq1);
  //if(seq1 != NULL)
  //  print(seq1);
  // */
 
  ReadTable * table;
  table = createTable("../data/test.in");
  unsigned int count=0;
  int stop;
  unsigned int i,j,k;

  /*
  for(i=0;i<10;i++){
    print(table->table[i]);
    print(table->table[i+1]);
    printf("R:%d\n",sobrepostos(table->table[i],table->table[i+1],1));
  }
  */
  
  //for(k=0;k<15;k++){
        stop=1;
        printf("i:%d\n",k);
        for(i=0;i<table->size-1;i++){
          if(table->table[i] != NULL)
            for(j=i+1;j<table->size-1;j++){
              if(table->table[j] != NULL)
                if(sobrepostos(table->table[i],table->table[j],1)){
                  if(stop)
                    print(table->table[i]);
                  adiciona(table->table[i],table->table[j],1);
                  if(stop){
                    print(table->table[j]);
                    print(table->table[i]);
                    printf("------\n");
                  }
                  deleteRead(table->table[j]);
                  table->table[j]=NULL;
                  i++;
                  if(stop){
                    stop=0;
                    //getchar();
                  }
                  break;
                }
            }
        }
        //}
  count = countTable(table);
  printf("N:%d\n",count);
  //printf("%d\n",table->table[1]->size*4);
  //printTable(table);
  //getchar();
  // */
  return 0;
}
