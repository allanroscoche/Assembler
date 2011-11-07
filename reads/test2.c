#include <stdio.h>
#include "read.h"

void shifter(int read_end, int add_end){
  int i;

  Read * seq[4];

  unsigned char sequencia1[] = "AGCTTTTCATTCTGACTGCAACGGGCAA";
  seq[0] = createRead(sequencia1);

  unsigned char sequencia2[] = "acgt";
  seq[1] = createRead(sequencia2);

  unsigned char sequencia3[] = "acgt";
  seq[2] = createRead(sequencia3);

  unsigned char sequencia4[] = "acgt";
  seq[3] = createRead(sequencia4);

  Read * seq_add[4];

  unsigned char  sequencia_add1[] = "TTTCATTCTGACTGCAACGGGCAATAAG";
  seq_add[0] = createRead(sequencia_add1);

  unsigned char  sequencia_add2[] = "CTTTTCATTCTGACTGCAACGGGCAATAAGT";
  seq_add[1] = createRead(sequencia_add2);

  unsigned char  sequencia_add3[] = "ttcgtacgtctcg";
  seq_add[2] = createRead(sequencia_add3);

  unsigned char  sequencia_add4[] = "acgt";
  seq_add[3] = createRead(sequencia_add4);

  for(i=0;i<1;i++){
    printf("R:%d\n",comparador(seq[read_end],seq_add[i],i+1));
    printf("\n\n");
  }
  //printf("-----------\n");
}


int main(void)
{
  int i,j;
  for(i=0;i<1;i++)
    shifter(i,0);
  return 0;
}
