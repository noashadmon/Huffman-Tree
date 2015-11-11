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
  /*node *r = new node;
  node *pos = r;
  unsigned char tempcode, bit;
  int length = 0; 
  int done = 0; 
  int index = 0;
  cout << "hi";
  for (int i = 0; i < 256; i++)
  {
    length = (int)encodedMessage[index];
    for (int j = 1; j < 4; j++)
    {
      unsigned char mask = 1 << 7;
      tempcode = (encodedMessage[index + j]);
      for (int k = 0; k < 8; k++)
      {
        if (length <= 0)
        {
          unsigned char element = i;
          pos->item = element;
          pos = r;
          done = 1;
          break;
        }
        bit = tempcode & mask;
        mask >>= 1;
        if (bit == 0)
        {
          if (pos->left == NULL)
          {
            node *newNode = new node;
            pos->left = newNode;
          }
          pos = pos->left;
         }
         else
         {
           if (pos->right == NULL)
           {
             node *n = new node;
             pos->right = n;
           }
           pos = pos->right;
         }
         length--;
       }
       if (done)
       {
         done = 0;
         break;
       }
     }
     index += 5;
   }
  cout << "hi";
  node *ptr = r;
  int count = 0;
  done = 0;
  int pos1 = encodedMessage[encodedSize - 1];
  for (int l = 1280; l < encodedSize - 1; l++)
  {
    unsigned char mask = 1 << 7;
    tempcode = encodedMessage[l];
    for (int i = 0; i < 8; i++)
    {
      bit = tempcode & mask;
      mask >>= 1;
      if (ptr->left == NULL && ptr->right == NULL)
      {
        decodedMessage[count] = ptr->item;
        count++;
        ptr = r;
        if (l == encodedSize - 2 && (pos1 == i ||pos1 == i-1 || pos1 == i+ 1))
        {
          done = 1;
          break;
        }
       if (bit == 0)
         ptr = ptr->left;
       else
        ptr = ptr->right;
      } 
    }
   if (done)
     break;
  }
  *decodedSize = count;
  for (int i = 0; i < count; i++)
    cout << decodedMessage[i];*/
 /* unsigned int codeTable[256];
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

  }*/
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
