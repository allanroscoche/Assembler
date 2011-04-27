#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
#include "read.h"
#include "ptree.h"

int main()
{
  char seq1[] = "taaaaaaaac";
  char seq2[] = "cggt";
  char seq3[] = "taaaaaaagc";
  std::ifstream dados;
  dados.open("teste2.csfasta");

  Read teste(seq1);
  Read teste2(seq2);
  Read teste3(seq3);
  
  cout << "t1:" << teste;
  cout << "t2:" << teste2;
  cout << "t3:" << teste3;


  //cout << "c1:" << *teste.chop_head(1);
  teste.chop_head(1);

  cout << "t1:" << teste;


  /*
  PTree t;
  t.print();
  t.insert(teste);
  cout << teste;
  t.print();

  t.insert(teste3);
  t.print();
 
/*
  while(!dados.eof()){
    dados >> teste3;
    cout << "T" << teste3;
  }
*/

  dados.close();
  return 0;
}
