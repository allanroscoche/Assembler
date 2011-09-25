#include "grude.h"

// adicionando um read já alinhado ao Grude
int adicionarRead(Grude * g, Read * read)
{
  unsigned int read_size;

  read_size = read->size + read->begin*4 + read->end;

  if(read_size > N_BASES)
    return 0;

  for(i=0;i<read_size;i++){
    switch ( (seq->bases[i/4] >> (i%B_CHAR)*2) & 0x3) {
    case 0:
      bases[i].A++;
      break;
    case 1:
      bases[i].T++;
      break;
    case 2:
      bases[i].G++;
      break;
    case 3:
      bases[i].C++;
      break;
    default:
      printf("Error, verify sorce code\n");
      break;
    }
  }
  return 1;
}
