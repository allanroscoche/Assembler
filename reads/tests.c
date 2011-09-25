#include <stdio.h>
#include "read.h"

int main(void)
{
  Read * seq1;
  unsigned char sequencia1[] = "cgtccgtacgttatat";
  seq1 = createRead(sequencia1);
  print(seq1);

  Read * seq2;
  unsigned char  sequencia2[] = "ccgtccgtacgttata";
  seq2 = createRead(sequencia2);
  print(seq2);

  Read * seq3;
  unsigned char  sequencia3[] = "ccgtccgtacgttatg";
  seq3 = createRead(sequencia3);
  print(seq3);

  printf("result:%d\n",sobrepostos(seq1,seq2));
  printf("result:%d\n",sobrepostos(seq2,seq3));


  //ReadTable * table;
  //table = createTable("teste.csfasta");
  //printTable(table);
  //getchar();

  return 0;
}
