#include "read.h"
#include <stdlib.h>
#include <stdio.h>

unsigned int convertSolid(Read * seq, unsigned char * read)
{
  unsigned int i;
  int fim = seq->size*B_CHAR + seq->end;
  for(i=0;i<fim;i++){
    seq->bases[i] = 0;
    char b;
    switch(read[i]){
    case 'A':
    case 'a':
      b=0;
      break;
      
    case 'C':
    case 'c':
      b=1;
      break;
      
    case 'G':
    case 'g':
      b=2;
      break;
      
    case 'T':
    case 't':
      b=3;
      break;
      
    default:
      printf("base invalida:%d\n",b);
    }
    // adiciona uma base ao inteiro
    seq->bases[i / B_CHAR] |= b << (i%B_CHAR)*2;
    
  }
  return i;
}

unsigned int getSize(unsigned char * entrada)
{
  unsigned int i;
  while(entrada[i] != 0)
    i++;
  return i;
}
void print(Read * seq)
{
  unsigned int i;
  int fim = seq->size*B_CHAR + seq->end;
  for(i=0; i<fim ;i++){
    switch( (seq->bases[i/4] >> (i%B_CHAR)*2) & 0x3)
      {
      case 0:
	printf("A");
	break;
      case 1:
	printf("C");
	break;
      case 2:
	printf("G");
	break;
      case 3:
	printf("T");
	break;
      }
  }
  printf("\n");
}

Read * createRead(unsigned char * entrada)
{
  // alloca o ponteiro de Read
  Read * novo = (Read *) malloc (sizeof(Read));

  // acha o tamanho
  int sizeSeq = getSize(entrada);
  novo->size = sizeSeq / B_CHAR;
  novo->end = sizeSeq % B_CHAR;
  novo->begin = 0;
  
  // alloca o vetor
  novo->bases = (unsigned char *) malloc (sizeof(unsigned char));

  //converte o read
  convertSolid(novo,entrada);
  
  // retorna o endereco do read
  return novo;

}
int deleteRead(Read * read)
{
  free(read->bases);
  free(read);
}
ReadTable * createTable(unsigned char * arquivo)
{
  FILE *fp;
  unsigned char buffer[500];
  ReadTable * table;

  fp = fopen(arquivo, "r");

  if(fp == NULL){
    printf("Erro ao abrir o arquivo\n");
    return NULL;
  }
  int cont = 0;
  char * read;
  read = fgets(buffer,500,fp);
  while( read != NULL){
    read = fgets(buffer,500,fp);
    if(buffer[0] == 'T'){
      
      cont++;
    }
  }
  
  fclose(fp);
  
  printf("%d sequencias\n",cont);
  return table;
}
