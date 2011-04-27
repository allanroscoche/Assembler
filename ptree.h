#include "read.h"

class PTree
{
 public:
  PTree(void);
  PTree(Read r);
  PTree * insert(Read & r);
  void print(int level=0);

 private:
  bool full;
  Read * seq;
  PTree * base[4];

};
