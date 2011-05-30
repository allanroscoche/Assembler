#include <stdio.h>
#include "read.h"

int main(void)
{
  Read * seq1;
  unsigned char sequencia1[] = "acgt";
  seq1 = createRead(sequencia1);
  print(seq1);

  Read * seq2;
  unsigned char sequencia2[] = "cttagc";
  seq2 = createRead(sequencia2);
  print(seq2);

  ReadTable * table;
  table = createTable("entrada.csfasta");

  return 0;
}
