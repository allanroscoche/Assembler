#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
#include "read.h"

int main()
{

  std::ifstream dados;
  dados.open("teste2.csfasta");

  Read teste("taccccccccc");
  Read teste2(teste);
  Read teste3;

  while(!dados.eof()){
    dados >> teste3;
    cout << "T" << teste3;
  }
  /*

  cout << "Tam:" << teste.getLength() << endl;

  cout << teste2;

  teste2 += teste;

  cout << "Tam:" << teste2.getLength() << endl;

  cout << teste2;
  */
  return 0;
}
