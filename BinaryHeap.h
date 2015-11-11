        #ifndef _BINARY_HEAP_H_
        #define _BINARY_HEAP_H_

        #include "dsexceptions.h"
        #include "vector.h"

class node{

public:
  /*Comparable*/ int item;
  int freq;
  node* left;
  node* right;
  //node(){};
  node(int f, node* l = NULL, node* r = NULL, int ch = -1)
  {
   item = ch;
   freq = f;
   left = l;
   right = r;
  }//constructor 
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
            //void search(node *r, unsigned int data, int depth);
            void insert( node* x );
            void deleteMin( );
            unsigned int *getEncode();
            void deleteMin( Comparable & minItem );
            void makeEmpty( );
            //void PrintTree(const node *x);
            void read(int item[256]);
            void read(unsigned item[256]);
            void deleteMin(node **min);
            //int getDepth(unsigned int d);
            //unsigned int reverse(unsigned int x, int depth);
            void Htree(); 
            //int                currentSize;  // Number of elements in heap
            //vector<Comparable*>array;
            //private:
            int currentSize;
            vector<Comparable> array;        // The heap array
            //int currentSize;
            void buildHeap( );
            int depth;
            int *leadZeros; 
            void percolateDown( int hole );
            unsigned encodeAr[256];
        };

        #include "BinaryHeap.cpp"
        #endif
