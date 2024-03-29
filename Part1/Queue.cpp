/* 
 * Queue.cpp - recycled from Assignment 2
 *
 * Description: Array-based implementation of Queue as an ADT class
 * Class Invariant: Queue maintained in FIFO order
 *
 * Author: Quang Anh Pham
 * Date: March 2024
 */

#include "Queue.h"
#include "EmptyDataCollectionException.h"
#include <iostream>
using std::cout, std::endl;

template<typename ElementType>
Queue<ElementType>::Queue() : elementCount(0), capacity(10), frontindex(0), backindex(0) {
    elements = new ElementType[capacity];         //! arbitrary value
}

template<typename ElementType>
Queue<ElementType>::Queue(const Queue& aQueue) : elementCount(aQueue.elementCount), capacity(aQueue.capacity), frontindex(aQueue.frontindex), backindex(aQueue.backindex) {
    elements = new ElementType[capacity];
    for (unsigned int i = 0; i < elementCount; i++) 
        elements[i] = aQueue.elements[i];
}

template<typename ElementType>
Queue<ElementType>::~Queue() {
    delete[] elements;
    elementCount = 0;
    capacity = 0;
    frontindex = 0;
    backindex = 0;
}

template<typename ElementType>
bool Queue<ElementType>::isEmpty() const {
    return (elementCount == 0);
}

template<typename ElementType>
void Queue<ElementType>::resize() {
    //* Create bigger array and copy elements there for more space
    ElementType* newEle = new ElementType[capacity*2];

    for (unsigned int i = 0; i < elementCount; i++) 
        newEle[i] = elements[(frontindex + i) % capacity];

    //* Delete old array, assign new array, reset front and back indexes
    delete[] elements;
    elements = newEle;
    this->capacity *= 2;
    frontindex = 0;
    backindex = elementCount;
}

template<typename ElementType>
bool Queue<ElementType>::enqueue(ElementType& newElement) {
    if (frontindex == backindex && elementCount != 0)
        resize();

    elements[backindex] = newElement;
    backindex = (backindex + 1) % capacity;
    elementCount++;
    return true;
}

template<typename ElementType>
void Queue<ElementType>::dequeue() {
    if (elementCount == 0)
        throw EmptyDataCollectionException("Queue is empty, dequeue fail.");

    frontindex = (frontindex + 1) % capacity;
    elementCount--;
}

template<typename ElementType>
ElementType& Queue<ElementType>::peek() const {
    return elements[frontindex];    
}

template<typename ElementType>
void Queue<ElementType>::print() const {
    cout << "[";
    if (!isEmpty()) {
        //* Start from the front index
        unsigned int index = frontindex;
        unsigned int counter = 0;
        
        while (counter < elementCount - 1) {
            cout << elements[index] << ", ";
            index = (index + 1) % capacity;
            counter++;
        }
        cout << elements[index];
    }
    cout << "]" << endl;
}