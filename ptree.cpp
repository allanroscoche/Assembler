#include "ptree.h"
#include "read.h"
#include "chop.h"
#include <iostream>

PTree::PTree(void)
{
  full = false;
  seq = NULL;
  for(int i=0; i<4; i++)
    base[i] = NULL;
}
PTree::PTree(Read r)
{
  full = false;
  seq = new Read(r);
  for(int i=0; i<4; i++)
    base[i] = NULL;
}
PTree * PTree::insert(Read & read)
{

  if( (full==true) && (seq==NULL) ){
      std::cout << "um\n";
  }
  if( (full==false) && (seq!=NULL) ) {
    Chop cut;
    int equal = seq->compare(read,cut);
    if(equal > 5 ) {
      int chop = cut.end+1;
      /*
      PTree * corte = new PTree(seq->chop(chop));
      if(base[corte->seq->first()] == NULL)
	base[corte->seq->first()] = corte;
      else
	base[corte->seq->first()]->insert(*corte->seq);
   
      
      PTree * novo = new PTree(read.chop_head(chop));
      if(base[novo->seq->first()] == NULL)
	base[novo->seq->first()] = novo;
      */
    }
  }
  if( (full==false) && (seq==NULL) ) {
    seq = new Read(read);
  }
  

}
void PTree::print(int level)
{
  if(level == 0)
    std::cout << "-------\n";
  else
    for(int i=0;i<level;i++)
      std::cout << "  ";
  if( seq != NULL )
    seq->print();
  else if( full == false)
    std::cout << "Empty" << std::endl;
  
  level++;
  for(int i=0; i<4; i++)
    if(base[i] != NULL)
      base[i]->print(level);

}
