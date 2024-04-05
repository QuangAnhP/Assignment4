/* 
 * BinaryHeap.h
 *
 * Description: Minimum Binary Heap ADT class.
 *
 * Class Invariant:  Always a minimum Binary Heap.
 * 
 * Author: Quang Anh Pham
 * Last Modification: March 2024
 *
 */

#ifndef BHEAP_H
#define BHEAP_H

#include "Event.h"

template <class ElementType>
class BinaryHeap {
	private:
		ElementType* elements;
		unsigned int elementCount;
        unsigned int capacity;

        void resize(unsigned int newCap);
		void reHeapDown(unsigned int indexOfRoot);
        void reHeapUp(unsigned int indexOfLeaf);
	
	public:
		//* Constructors and Destructor
		BinaryHeap();
		BinaryHeap(const BinaryHeap& aBHeap);
		~BinaryHeap();

/******* Start of Binary Heap  Public Interface *******/	

    // Description: Returns the number of elements in the Binary Heap.
    // Postcondition: The Binary Heap is unchanged by this operation.
    // Time Efficiency: O(1)
    unsigned int getElementCount() const; 

    // Description: Inserts newElement into the Binary Heap. 
    //              It returns true if successful, otherwise false.      
    // Time Efficiency: O(log2 n)
    bool insert(ElementType & newElement);

    // Description: Removes (but does not return) the necessary element.
    // Precondition: This Binary Heap is not empty.
    // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
    // Time Efficiency: O(log2 n)
    void remove();

    // Description: Retrieves (but does not remove) the necessary element.
    // Precondition: This Binary Heap is not empty.
    // Postcondition: This Binary Heap is unchanged.
    // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
    // Time Efficiency: O(1) 
    ElementType & retrieve() const;

    // Description: Print the Binary Heap. If Binary Heap is empty, print empty brackets: []
    // Postcondition: This Binary Heap is unchanged by this operation.
    // Time Efficiency O(n)
    void print() const;

/******* End of Binary Heap Public Interface *******/
};
#include "BinaryHeap.cpp"

#endif