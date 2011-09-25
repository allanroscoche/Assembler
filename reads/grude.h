#ifndef _GRUDE_H_
#define _GRUDE_H_

#include "read.h"

#define N_BASES 35
#define N_ASAS 5

typedef struct {
  unsigned char A;
  unsigned char C;
  unsigned char G;
  unsigned char T;
} GBase;


typedef struct {
  GBase bases[N_BASES + N_ASAS*2];
} Grude;


void adicionarRead(Grude * g, Read * read);

Read * simplificaGrude(Grude * g);


#endif
