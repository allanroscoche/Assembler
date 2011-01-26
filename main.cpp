#include <iostream>
using std::cout;
using std::endl;
#include "read.h"

int main()
{
  Read teste("tacccgttaaaccccccccccccccccccccccccccccccccc");

  cout << teste;

  //cout << !teste;

  cout << "Tam:" << teste.getLength() << endl;
  cout << "Mem:" << teste.getSize() << endl;

  return 0;
}
