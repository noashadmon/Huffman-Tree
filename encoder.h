// Author: Sean Davis
#ifndef ENCODER_H
#define	ENCODER_H
#include "BinaryHeap.h"

class Encoding
{
  public:
    char count;
    unsigned encoding;
    Encoding(char cnt = 0, unsigned enc = 0) : count(cnt), encoding(enc){}
};
class Encoder
{
//public:
  BinaryHeap<node*> heap;
  node *root;
  Encoding encodings[256];
  unsigned masks[256];
  void search(node *n, Encoding encoding, unsigned mask);
  void createTree(const unsigned char *m, const int s);
 public:
  Encoder();
  void encode(const unsigned char *message, const int size, 
    unsigned char *encodedMessage, int *encodedSize);
  ~Encoder();
  int getDepth(unsigned int d);
   //void PrintTree(const node* x);
//private:

};

#endif	/* ENCODER_H */

