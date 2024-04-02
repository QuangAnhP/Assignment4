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