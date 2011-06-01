#include "read.h"
#include <stdlib.h>
#include <stdio.h>


unsigned int convert(Read * seq, unsigned char * read)
{
  unsigned int i;
  for(i=0;i<seq->size+seq->end;i++)
    seq->bases[i] = 0;

  int fim = seq->size*B_CHAR + seq->end;
  for(i=0;i<fim;i++){
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

void convertRead(Read * novo, unsigned char * entrada)
{
  //if(novo == NULL){
  //  printf("erro: read nao alocado\n");
  //  return;
  //}

  int sizeSeq = getSize(entrada);
  novo->size = sizeSeq / B_CHAR;
  novo->end = sizeSeq % B_CHAR;
  novo->begin = 0;

  //printf("d:%d\n",sizeof(unsigned char)*novo->size+1);
  novo->bases = (unsigned char *) malloc(sizeof(unsigned char)*(novo->size+1));
  if(novo->bases == NULL){
    printf("erro\n");
    return;
  }
  convert(novo,entrada);
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
  novo->bases = (unsigned char *) malloc (sizeof(unsigned char)*(novo->size+1));
  if(novo->bases == NULL){
    printf("erro: read nao alocado\n");
    return NULL;
  }

  //converte o read
  convert(novo,entrada);

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
  unsigned char * seq;
  Read * readSeq;
  ReadTable * table;

  fp = fopen(arquivo, "r");

  if(fp == NULL){
    printf("Erro ao abrir o arquivo\n");
    return NULL;
  }

  table = (ReadTable *) malloc (sizeof(ReadTable));

  int cont = 0;
  unsigned char * read;
  read = fgets(buffer,500,fp);
  while( read != NULL){
    read = fgets(buffer,500,fp);
    if(buffer[0] == 'T'){
      seq = convertSolid(buffer);
      table->table = realloc(table->table,sizeof(Read*)*cont+1);
      table->table[cont] = createRead(seq);
      cont++;
      free(seq);
    }
  }

  table->size = cont;
  fclose(fp);

  printf("%d sequencias\n",table->size);

  return table;
}

void printTable(ReadTable * table)
{
  unsigned int i;
  for(i=0;i<table->size;i++){
    print(table->table[i]);
  }
}

char * convertSolid(char * entrada)
{
  char * saida;
  char primeiro, segundo;
  int i=0;
  int tamanho=0;

  while(entrada[i++] != 0)
    tamanho++;

  saida = (char *) malloc (sizeof(char)*tamanho);

  primeiro = entrada[0];
  saida[0] = primeiro;

  for(i=1;i<tamanho;i++) {
    segundo = entrada[i];

    switch(primeiro){
    case 'A':
      switch(segundo){
      case '0':
        saida[i]='A';
        break;
      case '1':
        saida[i]='C';
        break;
      case '2':
        saida[i]='G';
        break;
      case '3':
        saida[i]='T';
        break;
      }
      break;
    case 'C':
      switch(segundo){
      case '0':
        saida[i]='C';
        break;
      case '1':
        saida[i]='A';
        break;
      case '2':
        saida[i]='T';
        break;
      case '3':
        saida[i]='G';
        break;
      }
      break;
    case 'G':
      switch(segundo){
      case '0':
        saida[i]='G';
        break;
      case '1':
        saida[i]='T';
        break;
      case '2':
        saida[i]='A';
        break;
      case '3':
        saida[i]='C';
        break;
      }
      break;
    case 'T':
      switch(segundo){
      case '0':
        saida[i]='T';
        break;
      case '1':
        saida[i]='G';
        break;
      case '2':
        saida[i]='C';
        break;
      case '3':
        saida[i]='A';
        break;
      }
      break;
    }
    primeiro = saida[i];
  }
  saida[i+1]='\0';
  return saida;
}
