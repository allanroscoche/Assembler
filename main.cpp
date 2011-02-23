#include <iostream>
using std::cout;
using std::endl;
#include "read.h"

int main()
{
  Read teste("taccccccccc");

  cout << teste;
  
  Read teste2(teste);

  cout << "Tam:" << teste.getLength() << endl;

  cout << teste2;

  teste2 += teste;

  cout << teste2;

  cout << "Tam:" << teste2.getLength() << endl;

  return 0;
}
