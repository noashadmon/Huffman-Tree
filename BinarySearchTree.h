#ifndef _BINARY_HEAP_H_
        #define _BINARY_HEAP_H_

        #include "dsexceptions.h"
        #include "vector.h"

//template <class Comparable>        
class node{

public:
  /*Comparable*/ char item;
  int freq;
  node* left;
  node* right;
  node(){};
  node(/*Comparable*/char ch, int f, node* l, node* r)
  {
   item = ch;
   freq = f;
   left = l;
   right = r;
  }//constructor
 int isLeaf(node* root)
 {
    return !(root->left) && !(root->right) ;
 }
 };//node to create huffman tree
  

        // BinaryHeap class
        //
        // CONSTRUCTION: with a negative infinity sentinel and
        //               optional capacity (that defaults to 100)
        //
        // ******************PUBLIC OPERATIONS*********************
        // void insert( x )       --> Insert x
        // deleteMin( minItem )   --> Remove (and optionally return) smallest item
        // Comparable findMin( )  --> Return smallest item
        // bool isEmpty( )        --> Return true if empty; else false
        // bool isFull( )         --> Return true if full; else false
        // void makeEmpty( )      --> Remove all items
        // ******************ERRORS********************************
        // Throws Underflow and Overflow as warranted

        template <class Comparable>
        class BinaryHeap
        {
          public:
            explicit BinaryHeap( int capacity = 100 );

            bool isEmpty( ) const;
            bool isFull( ) const;
            const Comparable & findMin( ) const;
            void print();   
            void insert( const /*Comparable*/ node & x );
            void deleteMin( );
            void deleteMin( Comparable & minItem );
            void makeEmpty( );
            void read(int item[256]);
            void Htree();
            void PrintTree(node* x);
            void printInter(node *n);
           // void FillTable(int codeTable[], node *root, int Code);
          private:
            int                currentSize;  // Number of elements in heap
            vector<Comparable> array;        // The heap array

            void buildHeap( );
            void percolateDown( int hole );
        };

        #include "BinaryHeap.cpp"
        #endif
