#include <stdio.h>
#include "read.h"

void shifter(int shift, int add_end){

  Read * seq1;
  unsigned char sequencia1[] = "t";
  seq1 = createRead(sequencia1);

  Read * seq2;
  unsigned char sequencia2[] = "tt";
  seq2 = createRead(sequencia2);

  Read * seq3;
  unsigned char sequencia3[] = "ttt";
  seq3 = createRead(sequencia3);

  Read * seq4;
  unsigned char sequencia4[] = "tttt";
  seq4 = createRead(sequencia4);

  Read * seq_add[4];

  unsigned char  sequencia_add1[] = "acgt";
  seq_add[0] = createRead(sequencia_add1);

  unsigned char  sequencia_add2[] = "acgtg";
  seq_add[1] = createRead(sequencia_add2);

  unsigned char  sequencia_add3[] = "acgtgc";
  seq_add[2] = createRead(sequencia_add3);

  unsigned char  sequencia_add4[] = "acgtgct";
  seq_add[3] = createRead(sequencia_add4);


  adiciona(seq1,seq_add[add_end],shift);
  print(seq1);
  adiciona(seq2,seq_add[add_end],shift);
  print(seq2);
  adiciona(seq3,seq_add[add_end],shift);
  print(seq3);
  adiciona(seq4,seq_add[add_end],shift);
  print(seq4);
  printf("------------\n");
}


int main(void)
{
  int i,j;
  for(i=0;i<2;i++){
    for(j=1;j<=3;j++)
      shifter(j,i);
    printf("#########\n");
  }
  return 0;
}
