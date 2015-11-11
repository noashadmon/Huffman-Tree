// Author: Sean Davis
#ifndef DECODER_H
#define	DECODER_H
#include <iostream>
using namespace std;

class treenode
{
  public:
  char item;
  treenode *left;
  treenode *right;
  treenode(char let = 0, treenode *l = NULL, treenode *r = NULL) : item(let), left(l), right(r){}
};

class Decoder
{
treenode root;
void construct(const unsigned char *encodedMessage);
public:
  Decoder();
  ~Decoder();
  void decode(const unsigned char* encodedMessage, const int encodedSize, 
    unsigned char* decodedMessage, int *decodedSize);
private:

};

#endif	/* DECODER_H */

