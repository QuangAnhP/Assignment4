/* 
 * PriorityQueue.cpp
 *
 * Description: Implemented based on Binary Heap ADT class
 *
 * Class Invariant:  Binary Heap must always be minimum.
 * 
 * Author: Quang Anh Pham
 * Last Modification: March 2024
 *
 */

#include <iostream>
#include "PriorityQueue.h"
#include "EmptyDataCollectionException.h"

using std::cout;
using std::endl;


//* Constructors and Destructor
template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue() {
    PQueue->elementCount = 0;
    PQueue->capacity = 10;
    PQueue->elements = new ElementType[PQueue.capacity];
}

template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue(const PriorityQueue& aPQueue){
    this = BinaryHeap(aPQueue);
}

template <class ElementType>
PriorityQueue<ElementType>::~PriorityQueue(){
    delete[] PQueue->elements;
}

template <class ElementType>
bool PriorityQueue<ElementType>::isEmpty(){
    if (this->elementCount() == 0){
        return true;
    }
    return false;
}

template <class ElementType>
bool PriorityQueue<ElementType>::enqueue(ElementType & newElement){
    return this->insert(newElement);
}

template <class ElementType>
void PriorityQueue<ElementType>::dequeue(){
    if (this->isEmpty == true){
        throw EmptyDataCollectionException("Cannot remove from empty queue");
    }else{
        
    }
}

template <class ElementType>
ElementType & PriorityQueue<ElementType>::peek() const{

}



