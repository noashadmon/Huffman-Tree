//  Author: Sean Davis
#include <cstdlib>
#include <iostream>
#include <ostream>
#include "BinaryHeap.h"
#include "decoder.h"
using namespace std;

Decoder::Decoder()
{
} // Decoder()


Decoder::~Decoder()
{
} // ~Decoder()


void Decoder::decode(const unsigned char* encodedMessage, const int encodedSize, 
  unsigned char* decodedMessage, int *decodedSize)
{
  unsigned int codeTable[256];
  char length;
  int count = 0;
  unsigned int t;
  int pos = 1;
  //for (int i = 0; i < 1025; i++)
   // cout << (int)encodedMessage[i] << endl;
       
  for (int i = 1; i < 1023; i++)
  {
    t = 0;
    length = encodedMessage[i];
    int j = i;
    if (encodedMessage[i] == 32){
      if (encodedMessage[i+1] == 255 && encodedMessage[i+2] == 255 && encodedMessage[i+3] == 255){
        t = -1;
      }
    }
    else{
    while (length > 8)
    {
      t += encodedMessage[i++] << (length - 8);
      length = length - 8;
    }
    i++;
    t +=  encodedMessage[i] >> (8 - length);
    }
    //cout << " t is : " << t << endl;
    codeTable[count] = t;
    count++;
    if (i != j + 3)
      i = j + 3;
  }

  for (int i = 0; i < 256; i++){
    if (codeTable[i] != -1)
    cout << (char)i << " : " << (int)codeTable[i] << endl;
  }
  //BinaryHeap<node *>decodeHuff(256);
  //decodeHuff.read(codeTable);
  //decodeHuff.Htree();

  pos = 0;
  for (int i = 1; i <= 1024; i++)
  {
    if(codeTable[i] != -1)
    {
      pos = i;
      if (codeTable[pos] == 0)
        
        
    }

  }
  //node *min = decodeHuff.findMin(); 
  //i = 1;
  /*for (int i = 0; i < 256; i++){
    while (min->left)
    {
    if (codeTable[i] == 0)
      min = min->left;
    else
     min = min->right;
    }
    decodedMessage[i] = (char)codeTable[i];
  }
  for (int i =0; i < encodedSize; i++)
    cout << (char)decodedMessage[i];*/
 /* for (int i = 0; i < 256; i++)
  {
    codeTable[i] = encodedMessage[i];
    //cout << (char)i << " value " << codeTable[i] << endl;
  }
  for (int i = 0; i < 256; i++)
    tab[codeTable[i]] = i;
  //cout << " hi";
  for (int i = 256; i < encodedSize; i++){
   // cout << "_____________________" << endl;
   // cout << " " << encodedMessage[i] << " " << endl;
  }

  for (int i = 256; i < encodedSize; i++)
  {
    decodedMessage[i - 256] = tab[encodedMessage[i]];
    //cout << decodedMessage[i - 256];
  }*/
  
} // decode()
