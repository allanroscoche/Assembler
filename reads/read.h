
#ifndef _READ_H_
#define _READ_H_

#define B_CHAR 4

typedef struct
{
  unsigned char size; // tamanho do vetor
  unsigned char begin:4; //inicio no primeiro byte
  unsigned char end:4; // fim no ultimo byte

  unsigned char * bases; // cada char tem que guardar 4 bases

} Read;

typedef struct
{
  unsigned int size;
  Read * table;
} ReadTable;

Read * createRead(unsigned char * );
void print(Read * );
ReadTable * createTable(unsigned char * );


#endif
