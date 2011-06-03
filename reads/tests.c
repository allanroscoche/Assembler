#include <stdio.h>
#include "read.h"

int main(void)
{
  Read * seq1;
  unsigned char sequencia1[] = "acgtacgtacgt";
  seq1 = createRead(sequencia1);
  print(seq1);

  Read * seq2;
  unsigned char  sequencia2[] = "ccgtccgtacgtt";
  seq2 = createRead(sequencia2);
  print(seq2);

  //Read * seq3;
  //seq3 = createRead(sequencia2);
  //print(seq3);

  printf("result:%d\n",compare(seq1,seq2));

  //ReadTable * table;
  //table = createTable("teste.csfasta");
  //printTable(table);
  //getchar();

  return 0;
}
