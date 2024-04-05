/* 
 * PriorityQueue.cpp
 *
 * Description: Implemented based on Binary Heap ADT class
 *
 * Class Invariant:  Binary Heap must always be minimum.
 * 
 * Author: Quang Anh Pham + Cole Ackerman
 * Last Modification: March 2024
 *
 */

#include <iostream>
#include "PriorityQueue.h"
#include "EmptyDataCollectionException.h"

using std::cout;
using std::endl;


//* Constructors and Destructor
//constructor
template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue() {
    PQueue = new BinaryHeap<ElementType>();
}

//constructor
template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue(const PriorityQueue& aPQueue){
    PQueue = BinaryHeap(aPQueue);
}

//destructor
template <class ElementType>
PriorityQueue<ElementType>::~PriorityQueue(){
    delete PQueue;
}

// Description: Returns true if this Priority Queue is empty, otherwise false.
        // Postcondition: This Priority Queue is unchanged by this operation.
        // Time Efficiency: O(1)
template <class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const{
    return (PQueue->getElementCount() == 0);
}

 // Description: Inserts newElement in this Priority Queue and 
        //              returns true if successful, otherwise false.
        // Time Efficiency: O(log2 n)
template <class ElementType>
bool PriorityQueue<ElementType>::enqueue(ElementType & newElement){
    return PQueue->insert(newElement);
}

// Description: Removes (but does not return) the element with the next
        //              "highest" priority value from the Priority Queue.
        // Precondition: This Priority Queue is not empty.
        // Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
        // Time Efficiency: O(log2 n)
template <class ElementType>
void PriorityQueue<ElementType>::dequeue(){
    return PQueue->remove();
}

// Description: Returns (but does not remove) the element with the next 
//              "highest" priority value from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType & PriorityQueue<ElementType>::peek() const{
    return PQueue->retrieve();
}
