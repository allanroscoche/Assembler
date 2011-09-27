#include <stdio.h>
#include "read.h"

int main(void)
{
  /*
  Read * seq1;
  unsigned char sequencia1[] = "ttttt";
  seq1 = createRead(sequencia1);
  print(seq1);

  Read * seq2;
  unsigned char  sequencia2[] = "ccttacgt";
  seq2 = createRead(sequencia2);
  print(seq2);

  Read * seq3;
  unsigned char  sequencia3[] = "ccgtccgtacgttatg";
  seq3 = createRead(sequencia3);
  //print(seq3);

  //printf("result:%d\n",sobrepostos(seq1,seq2,1));
  //printf("result:%d\n",sobrepostos(seq2,seq3,1));

  adiciona(seq1,seq2,3);
  print(seq1);
  */
  ReadTable * table;
  table = createTable("../data/test.in");
  unsigned int count=0;
  unsigned int i;
  for(i=0;i<table->size-1;i++){
    if(sobrepostos(table->table[i],table->table[i+1]),1)
      count++;
  }
  printf("N:%d\n",count);
  //printTable(table);
  //getchar();

  return 0;
}
