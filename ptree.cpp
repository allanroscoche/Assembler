#include "ptree.h"
#include "read.h"
#include <iostream>

PTree::PTree(void)
{
  full = false;
  seq = NULL;
  for(int i=0; i<4; i++)
    base[i] = NULL;
}
PTree * PTree::insert(Read * read)
{

  if( (full==true) && (seq==NULL) )
    {
      
    }
  if( (full==false) && (seq!=NULL)
    {

    }
  if( (full==false) && (seq==NULL) )
    {
      seq = new Read(read);
    }


}
void PTree::print()
{
  if( seq != NULL )
    seq->print();
  else if( full == false)
    std::cout << "Empty" << std::endl;
  
  for(int i=0; i<4; i++)
    if(base[i] != NULL)
      base[i]->print();

}
