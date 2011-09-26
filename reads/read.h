#ifndef _READ_H_
#define _READ_H_

#define B_CHAR 4

#define _3B 0x3F // 3 bases
#define _2B 0xF  // 2 bases
#define _1B 0x3  // 1 base

#define _S1B 2 // shift 1 base
#define _S2B 4 // shift 2 bases
#define _S3B 6 // shift 3 bases

#define QUAL 20

typedef struct
{
  unsigned int size; // tamanho do vetor
  unsigned char begin:4; //inicio no primeiro byte
  unsigned char end:4; // fim no ultimo byte

  unsigned char * bases; // cada char tem que guardar 4 bases

} Read;

typedef struct
{
  unsigned int size;
  Read * * table;
} ReadTable;

unsigned int compare(Read *, Read *);

Read * createRead(unsigned char *);
void convertRead(Read *, unsigned char *);
int compareRead(Read * A, Read * B);
void print(Read * );
void printTable(ReadTable * );
ReadTable * createTable(unsigned char * );
unsigned int convert(Read *, unsigned char *);
char * convertSolid(char *);

#endif
