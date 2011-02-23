#ifndef _READ_
#define _READ_

#include <iostream>
#include <vector>

using std::ostream;
using std::istream;


class Read {
public:
     Read( char * = 0);
     Read( const Read &);
     ~Read();
     friend ostream &operator<<( ostream&, const Read &);
     friend istream &operator>>( istream&, Read &);
     Read operator!();
     bool operator+=(Read );
     unsigned int getLength();
     unsigned int getSize();
private:
     std::vector <unsigned char> bases;
     unsigned int length;
     void addchar(char *);
     unsigned int countLength(char *);
};

#endif
