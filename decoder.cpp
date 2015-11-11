//  Author: Sean Davis
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include "decoder.h"
#include "BinaryHeap.h"

using namespace std;

Decoder::Decoder()

{ 
} // Decoder()

Decoder::~Decoder()

{ 

} // ~Decoder()

void Decoder::construct(const unsigned char *encodedMessage)
{
  unsigned mask, code;
  int j, count;
  treenode *ptr;
  for (int i = 0; i < 256; i++)
  {
    memcpy(&code, &encodedMessage[i*sizeof(unsigned) + 1], sizeof(unsigned));
    count = code & 0x1f;
    ptr = &root;
    for (j = 0, mask = 0x80000000; j < count;j++, mask >>=1)
    {
      if(code & mask)
      {
        if (!ptr->right)
            ptr->right = new treenode();
        ptr = ptr->right;
      }
      else{
        if(!ptr->left)
         ptr->left = new treenode();
        ptr = ptr->left;
    }
   }
   ptr->item = i;
}
}

void Decoder::decode(const unsigned char* encodedMessage, const int encodedSize,

  unsigned char* decodedMessage, int *decodedSize)

{

  //unsigned int codeTable[256];
  //unsigned int reverse[99999];
  //unsigned char l;
  unsigned char count = encodedMessage[0];
  unsigned decodePos = 0;
  int  pos = 256 * sizeof(unsigned)+1;
  unsigned bitPos = 0;
  construct(encodedMessage);
  while (pos < encodedSize || bitPos != count)
  {
    treenode *ptr = &root;
    while(ptr->left || ptr->right)
    {
      if(encodedMessage[pos] & (0x80 >> bitPos))
        ptr = ptr->right;
      else
       ptr = ptr->left;
     if (++bitPos == 8)
     {
        bitPos = 0;
       pos++;
    }
    }
   decodedMessage[decodePos++] = ptr->item;
  }
  *decodedSize = decodePos;
  //int j;
 /* for(int i = 1; i < 1025; i++)
  { 
    trythis = 0;
    l = encodedMessage[i];
    int j = i;
      while(l > 8)
      {
        i++;
        trythis += encodedMessage[i] << (l - 8);
        l = l - 8;
      }
      i++;
      trythis += encodedMessage[i] >> (8 - l);
   // }

   //cout << "t is " << t << endl;

    codeTable[count] = trythis;

    count++;

    if(i != j + 3)

      i = j + 3;

  }
  BinaryHeap<node *> newTree(256);

  newTree.read(codeTable);

  //cout << "idk life" << endl;

  newTree.Htree();
  node * root = newTree.findMin();
  //cout << "min is : " << root->left->item;
  
  pos = encodedSize;
  int p = 0;
  int j = 1025;//encodedSize - 1;
  count = 0;
  //int temp = encodedMessage[j]; //encodedSize];// >> encodedMessage[0];
  while (j != encodedSize) //count != (8-encodedMessage[0]))
  {
    count = 0;
    unsigned int temp = encodedMessage[j];
    while (count != 8)
    {
      if (0x80 & temp)
      {
      if (root->right){
        root = root->right;
        count++;
        temp <<= 1;
      }
      else
      {
        decodedMessage[p++] = root->item;
        //p++;
        root = newTree.findMin();
      }
      }
    else
    {
      if (root->left){
        root = root->left;
        count++;
        temp <<= 1;
      }
      else
      {
        decodedMessage[p++] = root->item;
        //p++;
        root = newTree.findMin();
      }
    }
   }
  j++;
  }
  //cout << "p is " << p;
  *decodedSize = p;*/
} 
  //count = 0;
  /*while (j != 1024)
  {
    count = 0;
    temp = encodedMessage[j]; 
  while (count != 8)
  {
   if (0x80 & temp)
    {
      if (root->right){
        root = root->right;
        count++;
        temp >>= 1;
      }
      else
      {
        decodedMessage[p] = root->item;
        p++;
        root = newTree.findMin();
      }
    }
    else
    {
      if (root->left) {root = root->left;
        count++;
        temp >>= 1;
      }
      else
      {
        decodedMessage[p] = root->item;
        p++;
        root = newTree.findMin();
      }
    }
  }
  j--;
  }
  cout << " p is " << p << endl;     
  cout << " count is " << count << endl;
  cout << " j is " << j << endl;
  while (j != 1024){
    temp >>= 1;
  while (count != 8)
  {
    if (0x1 & temp){//encodedMessage[j] >> --shifter){
      if (root->right){
        count++;
        root = root->right;
      }
      else{
        decodedMessage[p] = root->item;
        p++;
        root = newTree.findMin();
      }
    }
    else{
      if (root->left){
        count++;
        root = root->left;
      }
      else{
        decodedMessage[p] = root->item;
        p++;
        root = newTree.findMin();
      }
    }
  }
  j--;
  }
  cout << "p is " << p; 
  for (int i = 0; i < p; i++)
    cout << endl << decodedMessage[i];
  }*/
  //if (root->right)
   // cout << "hi noa";
 //cout << "encoded size is : " << encodedSize << endl;
 /* for (int i = 1025; i < 1025+ encodedSize; i++){
    //cout << "hi me" << endl;
  while (root->left || root->right)
  {
    cout << "bit pattern: " << (0x1 & encodedMessage[pos]) << endl;
    if ((0x1 & (encodedMessage[pos++])) == 0)
    {
      root = root->left;
      cout << "item left =  " << root->item << endl;
      count++;
   //   cout << "hi";
    }
    else{
      root = root->right;
     // cout << "item right = " << root->item << endl;
      count++;
    }
  }
     ///cout << (int)root->item << " "; 
    decodedMessage[i - 1025] = root->item;
  }
  cout << count;
 // cout <<  "hello";
  //for (int i = 0; i < encodedSize; i++)
  */// cout << decodedMessage[i];
  /*int shifter = 8;
  if (1x0 & (encodedMessage[pos] << --shifter)
  {
    if (shifter != 0)
    {
      if (root-> left)
        root = root->left;
      if (root->right)
        root = root->right;
    } 
    e
 */
 /* for (int i = 1025; i < encodedSize; i++)
  {
    while (root->left != NULL){
      for (int j = 0x80; j > 0; j >>= 1){
        cout << "message is : " << (encodedMessage[pos] & j) << endl;
        if (encodedMessage[pos] & j){
          root = root->right;
        }
        else
           root = root->left;   
        }
     }
     decodedMessage[i] = root->item;
  }  
*/

 // decode()
