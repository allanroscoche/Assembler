#include <iostream>

using std::cout;
using std::endl;
using std::cerr;
using std::ostream;

#include "read.h"

enum BASE { A, C, G, T};
const int b_int = 16;
const char b_char = 4;

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

  bases = std::vector<unsigned char>(length/b_char,0);

  for(p=init.bases.begin(); p!=init.bases.end(); p++)
    cout << (int)*p << " ";
  cout << endl;
}
Read::~Read()
{
  //delete bases;
}
unsigned int Read::getSize(void)
{
  return sizeof(Read)+(length/b_char);
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

  // aumenta o tamanho
  length += read.length;

  // reserva espaço na memória
  bases.reserve( read.length/b_char );
 
  shift = read.length % b_char;

  for(pt=read.bases.begin();pt!=read.bases.end();pt++)
    bases.push_back(*pt);

  for(i=0;i<read.bases.size();i++){
    bases[i+(read.length/b_char)] = read.bases[i];
  }

  return true;

}
ostream & operator<<( ostream &out, const Read & read)
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
  out << endl;

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
	cerr << "base invalida" << endl;
      }
      // adiciona uma base ao inteiro
      bases[i/b_char] |= b << (i % b_char)*2;
    }
}
