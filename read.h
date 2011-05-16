#ifndef _READ_
#define _READ_

#include <iostream>
#include <vector>
#include "chop.h"

using std::ostream;
using std::istream;

class Read {

 public:
  Read( void);
  Read( char *);
  Read( const Read &);
  Read( const Read *);
  ~Read();
  void print();
  friend ostream &operator<<( ostream&, const Read &);
  friend istream &operator>>( istream&, Read &);
  Read * operator!();
  bool operator+=(Read &);
  int operator==(Read & );
  unsigned int getLength();
  Read * chop_tail(unsigned int);
  Read * chop_head(unsigned int);
  Read * chop(unsigned int);
  unsigned int size();
  int compare(Read &, Chop &);
  char first_char();
  int first();

 private:
  std::vector <unsigned char> bases;
  unsigned char begin;
  unsigned char end;
  void addchar(char *);
  unsigned int convert_solid(char *);
  unsigned int countLength(char *);
};

#endif
