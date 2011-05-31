#ifndef _READ_H_
#define _READ_H_

typedef Base struct
{
  unsigned char b1:2;
  unsigned char b2:2;
  unsigned char b3:2;
  unsigned char b4:2;
} Base;


typedef Read struct
{
  unsigned char size; // tamanho do vetor
  unsigned char begin:4; //inicio no primeiro byte
  unsigned char end:4; // fim no ultimo byte

  Bases * bases; // cada char tem que guardar 4 bases

} Read;

typedef ReadTable struct
{
  unsigned int size;
  Read * table;
} ReadTable;

Read * createRead(unsigned char *);
ReadTable * createTable(void);
int compareRead(Read * A, Read * B);

#endif
