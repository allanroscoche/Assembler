#ifndef _READ_
#define _READ_

#include <iostream>

using std::ostream;
using std::istream;

class Read {
public:
     Read( char * = 0);
     Read( const Read &);
     ~Read();
     friend ostream &operator<<( ostream&, const Read &);
     Read operator!();
     unsigned int getLength();
     unsigned int getSize();
private:
     unsigned char * bases;
     unsigned int length;
     void convert(char *);
};

#endif
