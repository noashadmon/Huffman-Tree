#include <cstdlib>
#include <iostream>
#include <ostream>
#include <cstring>
#include "encoder.h"
#include "BinaryHeap.h"
using namespace std;

Encoder::Encoder(): heap(257)
{
} // Encoder()


Encoder::~Encoder()
{
} // ~Encoder()
 void Encoder::search(node * root, Encoding encoding, unsigned mask)
   { 
     if (root->item != -1)
     {
       for (int i = 0; i < 4; i++)
       {
         encodings[root->item] = encoding;
         masks[root->item] = mask;
       }
       encodings[root->item].count = encoding.count;
      }
      mask |= 0x80000000U >> encoding.count;
      encoding.count++;
      if (root->left)
       search(root->left, encoding, mask);
      if (root->right)
      {
        encoding.encoding |= 0x80000000 >> (encoding.count - 1);
        search(root->right, encoding, mask);
      }
   }
void Encoder::createTree(const unsigned char *m, const int size)
{
  int counts[256];
  memset(counts, 0, sizeof(counts));
  node * n1, *n2;
  for (int i = 0; i < size; i++)
    counts[m[i]]++;
  heap.currentSize = 0;
  for (int i = 0; i < 256; i++)
    if (counts[i] >0)
     heap.array[++heap.currentSize] = new node(counts[i], NULL, NULL, i);
  heap.buildHeap();
  while (heap.currentSize > 1)
  {
    heap.deleteMin(&n1);
    heap.deleteMin(&n2);
    heap.insert(new node(n1->freq + n2->freq, n1, n2));
  }
  root = heap.array[1];
  Encoding encoding(0, 0);
  search(root, encoding, 0);
}
void Encoder::encode(const unsigned char *message, const int size, 
  unsigned char *encodedMessage, 
    int *encodedSize)
{
  /*unsigned int temp[256] = {0};
  unsigned int *newTable;
  //int enSize = 0;
  BinaryHeap<node * > huffTree(256);

  for(unsigned int i = 0; i < size; i++)
  {
    temp[message[i]]++;
  }*/
  //for(int i = 0; i < 256; i++)
  //if(temp[i] != 0)
   //cout << (char)i << " has freq of " << temp[i] << endl;

//return;
  //cout << endl;
  //huffTree.read(message, size);
  //huffTree.Htree(); //Creates real Huffman Tree and stores encoding in unsigned int []
  //eewTable = huffTree.getEncode();
  //for(int i = 0; i <256; i++)
   // if(newTable[i] != -1)
     //  cout << (char)i << " is " << newTable[i] << endl;
 //cout << "******************************************" << endl;
  /*int pos = 1;
  for(unsigned int i = 0; i < 256; i++) //final length of table will be stored at encodedMessage[0];
  {     unsigned int t = getDepth(temp[i]);
        encodedMessage[pos++]   = (unsigned char)t;
        temp[i] <<= (32 - t);
     	encodedMessage[pos++] = (temp[i] >> 24);
     	encodedMessage[pos++] = (temp[i] >> 16);
     	encodedMessage[pos++] = (temp[i] >> 8);
        temp[i] >>= (32 - t);
  }
  unsigned int full = pos; //1025 is always the end/the start of something else
  pos = 1025;*/
  /*while(pos < full)
  {
   }*/
    //int * leadZeros;
    //leadZeros = huffTree.getZeros();
    unsigned pos = 1, posBits = 0, code, letterWord;
    createTree(message,size);
    for(unsigned int i = 0; i < 256; i++)
    {
      //unsigned int en = (newTable[message[i]]);
     // unsigned int len = getDepth(en);
  /*    if(leadZeros[i] != len)
      {
          len = leadZeros[i];
      }*/
      encodings[i].encoding |= encodings[i].count;
      memcpy(&encodedMessage[pos], &encodings[i].encoding, sizeof(unsigned));
      pos += sizeof(unsigned);
    }
    for (int i = 0; i < size; i++)
    {
      letterWord = encodings[message[i]].encoding;
      code = (code & ~(masks[message[i]] >> posBits)) | (letterWord >> posBits);
      posBits += encodings[message[i]].count;
    
      while(posBits >= 8)
      {       
     //put 4 bytes into encodedMessage!!!
          encodedMessage[pos++] = code >> 24;
      /*   for (int j = 0x80; j > 0; j>>=1)
           if (encodedMessage[pos - 1]&j)
             cout << '1';
           else
            cout << '0';
        */
          //reset crap
          code <<= 8;
          posBits -= 8;
          
      }
    }
    //for (int i = 0; i < posBits; i++){
   // for (int j = 0x80; j > 0; j >>= 1){
     // if (encodedMessage[pos] & j) 
      //  cout << '1';
      //else
       // cout << '0';
   // }
   ///}
    encodedMessage[pos] = code >> 24;
    encodedMessage[0] = (char)posBits;

    //for(int i = 1025; i < pos; i++)
     //cout << (int)encodedMessage[i] << " ";
    //cout << "code is " << code << endl;
    //encodedMessage[pos++] = (en >> 16);
    //encodedMessage[pos++] = (en >> 8);//(newTable[message[i - 1025]]);
 // }
  /*for(int i = 1025; i < pos; i++)
    cout << (int)encodedMessage[i] << " ";*/
  //int count = 0;
  *encodedSize = pos;
//  cout << endl << *encodedSize;
 // cout << endl << *encodedSize;
 // cout << endl << endl;
}  // encode()

int Encoder::getDepth( unsigned int x )
{
  unsigned int i = 0;
  do
  {
     x /= 2;
     i++;
  } while(x != 0);

  return i;
}
