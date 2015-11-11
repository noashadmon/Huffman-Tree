        #include <cstdlib>
        #include <cstdio>
        #include <iostream>
        #include "BinaryHeap.h"
        using namespace std; 
        /**
         * Construct the binary heap.
         * capacity is the capacity of the binary heap.
         */
        template <class Comparable>
        BinaryHeap<Comparable>::BinaryHeap( int capacity )
          : currentSize(0), array( capacity + 1 )
        {
        }

        /**
         * Insert item x into the priority queue, maintaining heap order.
         * Duplicates are allowed.
         * Throw Overflow if container is full.
         */
       /* template <class Comparable>

        void BinaryHeap<Comparable>::read(const unsigned char *message, const int size )
        {
          int items[256];
          memset(counts, 0, sizeof(counts));
          node *node1, *node2;
          for (int i = 0; i < size; i++)
            counts[message[i]]++;  
         */ 
          /*for(int i = 0; i < 256; i++)
          {
            node *n = new node(i, item[i], NULL, NULL);
            encodeAr[i] = -1;
            if(item[i] != 0){
              insert(n);
            }
          }
           
         buildHeap();
            //cout<< "fmin" << findMin().freq<< findMin().item<<endl;
            //Htree();   
          */
   /* template <class Comparable>
    void BinaryHeap<Comparable>::read(unsigned item[256])
    {
      for (int i = 0; i < 256; i++)
      {
        node *n = new node (i, item[i], NULL, NULL);
        encodeAr[i] = -1;
        if (item[i] != -1)
          insert(n);
      }
    }
     */   
  /*  template <class Comparable>
    void BinaryHeap<Comparable>::Htree()
    {
      while(currentSize > 1)
      {
        node *min1 = findMin();
           //cout << "min" << min1.item<<endl;
        deleteMin();

	   node *min2 = findMin();
           deleteMin();
            
           int Nfreq = min1->freq + min2->freq;
           node *t = new node(-1, Nfreq, min1, min2);
          // cout << "freq: " << t->freq << " item " << t->item <<endl;
          // cout << " left " << (t->left)->freq<< " item " << (t->left)->item<<endl;
          // cout << " right " << (t->right)->freq<< " item " << (t->right)->item<<endl;
           insert(t);
           
      }
          //search(array[1], 0, 0);
            
         }//creates Huffman Tree
 
  */
  template <class Comparable>
  void BinaryHeap<Comparable>::deleteMin(node **min)
  {
    *min = array[1];
    array[1] = array[currentSize--];
    percolateDown(1);
  }
  template <class Comparable>
  unsigned int * BinaryHeap<Comparable>::getEncode() 
  {
    return encodeAr;
  }
  /* template <class Comparable>
   void BinaryHeap<Comparable>::search(node * root, unsigned int bits, int depth)
   { 
     if (root->item != -1)
     {
       for (int i = 0; i < 4; i++)
       {
         encodings[root->item] = encoding;
         masks[root->item] = mask;
       }
       encodings[root->item].freq = encoding.freq;
      }
      mask |= 0x80000000U >> encoding.freq;
      encoding.freq++;
      if (root->left)
       traverse(node-<left, encoding, mask);
      if (root->right)
      {
        encoding.encoding |= 0x80000000 >> (encoding.freq - 1);
        traverse(root->right, encoding, mask);
      }
   }*/
        //cout << "start value " << (char)(x->item) << endl;
         /* if(root->left)
          {
            search(root->left, bits, depth+1);
            
          }
          if(root->right){
           // cout << " r " << endl;
           bits |= 0x80000000 >> depth;
            //bits = (bits | (1 << depth));
            
            search (root->right, bits, depth+1);
          }
            //PrintTree(x->right);
           // cout << "bits : " << bits << endl;
          
         if (!(root->left) && !(root->right))
         {
           bits >>= 32 - depth;
           encodeAr[root->item] = bits;
         }*/
  // }
	template <class Comparable>
        void BinaryHeap<Comparable>::insert( node* x )
        {
            if( isFull( ) )
                throw Overflow( );

                // Percolate up
            int hole = ++currentSize;
            for( ; hole > 1 && (x->freq) < array[ hole / 2 ]->freq; hole /= 2 )
                array[ hole ] = array[ hole / 2 ];
             (array[ hole ]) = x;
        }
        /**
         * Find the smallest item in the priority queue.
         * Return the smallest item, or throw Underflow if empty.
         */
        template <class Comparable>
        const Comparable & BinaryHeap<Comparable>::findMin( ) const
        {
            if( isEmpty( ) )
                throw Underflow( );
            return (array[ 1 ]);
        }

        /**
         * Remove the smallest item from the priority queue.
         * Throw Underflow if empty.
         */
        template <class Comparable>
        void BinaryHeap<Comparable>::deleteMin( )
        {
            if( isEmpty( ) )
                throw Underflow( );

            array[ 1 ] = array[ currentSize-- ];
            percolateDown( 1 );
        }

        /**
         * Remove the smallest item from the priority queue
         * and place it in minItem. Throw Underflow if empty.
         */
        template <class Comparable>
        void BinaryHeap<Comparable>::deleteMin( Comparable & minItem )
        {
            if( isEmpty( ) )
                throw Underflow( );

            minItem = array[ 1 ];
            array[ 1 ] = array[ currentSize-- ];
            percolateDown( 1 );
        }

        /**
         * Establish heap order property from an arbitrary
         * arrangement of items. Runs in linear time.
         */
        template <class Comparable>
        void BinaryHeap<Comparable>::buildHeap( )
        {
            for( int i = currentSize / 2; i > 0; i-- )
                percolateDown( i );
        }

        /**
         * Test if the priority queue is logically empty.
         * Return true if empty, false otherwise.
         */
        template <class Comparable>
        bool BinaryHeap<Comparable>::isEmpty( ) const
        {
            return currentSize == 0;
        }

        /**
         * Test if the priority queue is logically full.
         * Return true if full, false otherwise.
         */
        template <class Comparable>
        bool BinaryHeap<Comparable>::isFull( ) const
        {
            return currentSize == array.size( ) - 1;
        }

       /**
         * Make the priority queue logically empty.
         */
        template <class Comparable>
        void BinaryHeap<Comparable>::makeEmpty( )
        {
            currentSize = 0;
        }
        /*template <class Comparable>
        char BinaryHeap<Comparable>::find(int x)
        {
          
        }*/

        /**
         * Internal method to percolate down in the heap.
         * hole is the index at which the percolate begins.
         */
        template <class Comparable>
        void BinaryHeap<Comparable>::percolateDown( int hole )
        {
/* 1*/      int child;
/* 2*/      Comparable tmp = array[ hole ];

/* 3*/      for( ; hole * 2 <= currentSize; hole = child )
            {
/* 4*/          child = hole * 2;
/* 5*/          if( child != currentSize && array[ child + 1 ]->freq < array[ child ]->freq )
/* 6*/              child++;
/* 7*/          if( array[ child ]->freq < tmp->freq )
/* 8*/              array[ hole ] = array[ child ];
                else
/* 9*/              break;
            }
/*10*/      array[ hole ] = tmp;
        }
