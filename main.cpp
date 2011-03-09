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

  cout << teste;
  cout << teste.chop_tail(5);

/*
  while(!dados.eof()){
    dados >> teste3;
    cout << "T" << teste3;
  }
*/

  dados.close();
  return 0;
}
