#ifndef _READ_
#define _READ_

#include <iostream>
#include <vector>

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
  Read operator!();
  bool operator+=(Read );
  unsigned int getLength();
  Read chop_tail(unsigned int);
  Read chop_head(unsigned int);
  Read chop(unsigned int);

 private:
  std::vector <unsigned char> bases;
  unsigned int length;
  void addchar(char *);
  unsigned int convert_solid(char *);
  unsigned int countLength(char *);
};

#endif
