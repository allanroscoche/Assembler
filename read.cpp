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
  convert(b);
}
Read::Read( const Read &init):length(init.length)
{
  bases = new unsigned char[length/b_char];
  unsigned int i;
  for(i=0; i<=(length/b_char); i++)
    bases[i]=init.bases[i];
}
Read::~Read()
{
  delete bases;
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

  for(i=0; i<=(length/b_int); i++)
   ptr_inv->bases[i] = ~bases[i];

   return *ptr_inv;
}
ostream & operator<<( ostream &out, const Read & read)
{
  unsigned int i, b;
  for(i=0;i<read.length;i++)
    {
      // retira uma base do inteiro
      b =     (read.bases[ i/b_char ] >> ((i*2) % b_char) ) & 3;
      //cout << endl << (read.bases[ i/b_int ] >> ((i*2) % b_int) );
      switch(b){
      case A:
	out << "A";
	break;
      case C:
	out << "C";
	break;
      case G:
	out << "G";
	break;
      case T:
	out << "T";
	break;
      }
    }
  out << endl;

  return out;
}
void Read::convert(char * read)
{
  int count = 0;
  while( read[count] != '\0')
    count++;
  length = count;

  bases = new unsigned char[length/b_char];
  for(count=0; count<=(length/b_char); count++)
    bases[count]=0;

  for(count=0;count<length;count++)
    {
      int b;
      switch(read[count]){
      case 'A':
      case 'a':
	b=A;
      break;
      
      case 'C':
      case 'c':
	b=C;
      break;
      
      case 'G':
      case 'g':
	b=G;
      break;
      
      case 'T':
      case 't':
	b=T;
      break;
      
      default:
	cerr << "base invalida" << endl;
      }
      // adiciona uma base ao inteiro
      bases[count/b_char] |= b << ((count*2) % b_char);
      //cout << read[count] << bases[count/b_int] << endl;
      //cout << b << " ";
    }
}
