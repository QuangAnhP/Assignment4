/* 
 * BinaryHeap.cpp
 *
 * Description: Minimum Binary Heap ADT class.
 *
 * Class Invariant:  Always a minimum Binary Heap.
 * 
 * Author: Quang Anh Pham
 * Last Modification: March 2024
 *
 */

#include <iostream>
#include "BinaryHeap.h"  // Header file

using std::cout;
using std::endl;

//* Constructors and Destructor
template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap() : elementCount(0), capacity(10) {
    elements = new ElementType[capacity];
}

template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap(const BinaryHeap& aBHeap) : elementCount(aBHeap.elementCount), capacity(aBHeap.capacity) {
    elements = new ElementType[capacity];
    for (unsigned int i = 0; i < elementCount; i++)
        elements[i] = aBHeap.elements[i];
}

template <class ElementType>
BinaryHeap<ElementType>::~BinaryHeap() {
    delete[] elements;
    elementCount = 0;
    capacity = 0;
}


// Description: Returns the number of elements in the Binary Heap.
// Postcondition: The Binary Heap is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
unsigned int BinaryHeap<ElementType>::getElementCount() const {
    return (elementCount == 0);
}

// Description: Inserts newElement into the Binary Heap. 
//              It returns true if successful, otherwise false.      
// Time Efficiency: O(log2 n)
template <class ElementType>
bool BinaryHeap<ElementType>::insert(ElementType& newElement) {
    //* Adding the new element at the back of the array, reHeapUp, increase count
    elements[elementCount] = newElement;
    reHeapUp(elementCount);
    elementCount++;
    return true;
} 

// Description: Removes (but does not return) the necessary element.
// Precondition: This Binary Heap is not empty.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void BinaryHeap<ElementType>::remove() {  
    if (elementCount == 0) 
        throw EmptyDataCollectionException("remove() called with an empty BinaryHeap.");

    elements[0] = elements[elementCount - 1];
    elementCount--;

    // No need to call reheapDown() if we have just removed the only element
    if (elementCount > 0) 
        reHeapDown(0);
    return;   
}

// Description: Retrieves (but does not remove) the necessary element.
// Precondition: This Binary Heap is not empty.
// Postcondition: This Binary Heap is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType& BinaryHeap<ElementType>::retrieve() const {
    if (elementCount == 0)
        throw EmptyDataCollectionException("retrieve() called with an empty BinaryHeap.");
    return elements[0];
}


// Utility method
    
    //TODO: revert changes to ~ resize() in A2

template <class ElementType>
void BinaryHeap<ElementType>::resize(unsigned int newCapacity) {
    // Create a new array with the new capacity, copy elements into it
    ElementType* newArray = new ElementType[newCapacity];
    for (unsigned int i = 0; i < elementCount; ++i) 
        newArray[i] = elements[i];
    

    // Delete the old array, update to new array
    delete[] elements;
    elements = newArray;
    capacity = newCapacity;
}

// Description: Recursively put the array back into a minimum Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapDown(unsigned int indexOfRoot) {

    unsigned int indexOfMinChild = indexOfRoot;

    // Find indices of children.
    unsigned int indexOfLeftChild = 2*indexOfRoot + 1;
    unsigned int indexOfRightChild = 2*indexOfRoot + 2;

    // Base case: elements[indexOfRoot] is a leaf as it has no children
    if (indexOfLeftChild > elementCount - 1) 
        return;

    // If we need to swap, select the smallest child
    // If (elements[indexOfRoot] > elements[indexOfLeftChild])
    if (!(elements[indexOfRoot] <= elements[indexOfLeftChild]))
        indexOfMinChild = indexOfLeftChild;

    // Check if there is a right child, is it the smallest?
    if (indexOfRightChild < elementCount) {
    // if (elements[indexOfMinChild] > elements[indexOfRightChild])
        if (!(elements[indexOfMinChild] <= elements[indexOfRightChild]))
            indexOfMinChild = indexOfRightChild;
    }

    // Swap parent with smallest of children.
    if (indexOfMinChild != indexOfRoot) {
        ElementType temp = elements[indexOfRoot];
        elements[indexOfRoot] = elements[indexOfMinChild];
        elements[indexOfMinChild] = temp;
    
        // Recursively put the array back into a heap
        reHeapDown(indexOfMinChild);
    }
    return;
} 

// Description: Make sure the Heap maintains its minimum structure after inserting
template <class ElementType>
void BinaryHeap<ElementType>::reHeapUp(unsigned int indexOfLeaf) {
    while (indexOfLeaf > 0 && elements[indexOfLeaf] <= elements[(indexOfLeaf - 1)/ 2]) {
        swap(indexOfLeaf, (indexOfLeaf - 1) / 2)
        indexOfLeaf = (indexOfLeaf - 1) / 2;
    }
}