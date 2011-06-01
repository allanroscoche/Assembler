#include <stdio.h>
#include "read.h"

int main(void)
{
  
  Read * seq1;
  unsigned char sequencia1[] = "acgt";
  seq1 = createRead(sequencia1);
  print(seq1);

  Read * seq2;
  unsigned char sequencia2solid[] = "T0202233";
  unsigned char * sequencia2;
  sequencia2 = convertSolid(sequencia2solid);
  seq2 = createRead(sequencia2);
  print(seq2);
  deleteRead(seq2);

  Read * seq3;
  seq3 = createRead(sequencia2);
  print(seq3);

  ReadTable * table;
  table = createTable("entrada.csfasta");

  return 0;
}
