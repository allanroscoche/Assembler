#include "read.h"

class PTree
{
 public:
  PTree(void);
  PTree * insert(Read * r);
  void print();

 private:
  bool full;
  Read * seq;
  PTree * base[4];
};
