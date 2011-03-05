#include <iostream>
#include <stdlib.h>
//using std::cout;
//using std::endl;
//using std::cerr;
//using std::ostream;

#include "read.h"

enum BASE { A, C, G, T};
const int b_int = 16;
const char b_char = 4;
Read::Read(void)
{
  length = 0;
}
Read::Read( char * b)
{
  length = countLength(b);
  bases = std::vector<unsigned char>(length/b_char,0);
  addchar(b);

}
Read::Read( const Read &init):
  length(init.length)
{
  std::vector<unsigned char>::const_iterator p;

  //bases = std::vector<unsigned char>(length/b_char,0);

  for(p=init.bases.begin(); p!=init.bases.end(); p++)
    bases.push_back(*p);
  bases.push_back(*p);
}
Read::~Read()
{
  //delete bases;
}
unsigned int Read::getLength(void)
{
  return length;
}

Read Read::operator!()
{
    unsigned int i;
    Read * ptr_inv;

    ptr_inv = new Read(*this);

    for(i=0; i<=bases.size(); i++)
      ptr_inv->bases[i] = ~bases[i];

    return *ptr_inv;
}
bool Read::operator+=(Read read){

  unsigned int i, shift;
  std::vector<unsigned char>::iterator pt;

  shift = (b_char - (length % b_char));

  // reserva espaço na memória
  bases.reserve( read.length/b_char );

  for(pt=read.bases.begin();pt!=read.bases.end();pt++)
    bases.push_back((*pt) >> shift*2);
  bases.push_back(*pt >> shift*2);

  shift = length % b_char;

  for(i=0;i<read.bases.size();i++){
    bases[i+(read.length/b_char)] |= read.bases[i] << shift*2;
  }

  // aumenta o tamanho
  length += read.length;

  return true;

}
unsigned int Read::convert_solid(char * read)
{
  unsigned int i;
  char b;
  unsigned int size;

  i=1;
  while( read[i]!=0 )
    i++;
  size = i-1;

  bases.reserve(size);

  i=1;
  while( read[i]!=0 )
    {
      switch(read[i])
        {
        case '0':
          b=0;
          break;
        case '1':
          b=1;
          break;
        case '2':
          b=2;
          break;
        case '3':
          b=3;
          break;
        default:
          std::cerr << "err: " << read[i] << "\n";
        }
      if(i%4 == 1)
        bases[i]=0;
      // adiciona uma base ao inteiro
      bases[(i-1)/b_char] |= b << ((i-1) % b_char)*2;
      i++;
    }

  // returns the size
  return size;
}
std::istream & operator>>( std::istream &in, Read & read)
{
  char * buff;
  buff = (char *) malloc(sizeof(char)*500);
  do
    in.getline(buff,500);
  while((buff[0] != 'T') && !in.eof());
  std::cout << buff << std::endl;
  if(!in.eof())
    read.length = read.convert_solid(buff);
}
std::ostream & operator<<( std::ostream &out, const Read & read)
{
  unsigned int i, b;
  for(i=0;i<read.length;i++)
    {
      // retira uma base do inteiro
      b =  (read.bases[ i/b_char ] >> (i % b_char)*2 ) & 3;
      switch(b){
      case 0:
        out << "A";
        break;
      case 1:
        out << "C";
        break;
      case 2:
        out << "G";
        break;
      case 3:
        out << "T";
        break;
      }
    }
  out << std::endl;


  return out;
}
unsigned int Read::countLength(char * read)
{
  unsigned int size=0;
  while(read[size]!='\0')
    size++;
  return size;
}
void Read::addchar(char * read)
{
  unsigned int i;
  for(i=0;i<length;i++){
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
        std::cerr << "base invalida" << std::endl;
      }
      // adiciona uma base ao inteiro
      bases[i/b_char] |= b << (i % b_char)*2;
    }
}
