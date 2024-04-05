/* 
 * Queue.h - recycled from Assignment 2
 *
 * Description: Array-based implementation of Queue as an ADT class
 * Class Invariant: Queue maintained in FIFO order
 *
 * Author: Quang Anh Pham
 * Date: March 2024
 */

#ifndef QUEUE_H
#define QUEUE_H

template <typename ElementType>
class Queue {	
    private:
        ElementType* elements;                
        unsigned int elementCount;
        unsigned int capacity;
        unsigned int frontindex;
        unsigned int backindex;

        void resize(unsigned int newCap);

    public:
        //* Constructors and Destructor
        Queue();
        Queue(const Queue& aQueue);
        ~Queue();
        
/******* Start of Queue Public Interface *******/
		
    // Class Invariant:  FIFO or LILO order

    // Description: Returns true if this Queue is empty, otherwise false.
    // Postcondition: This Queue is unchanged by this operation.
    // Time Efficiency: O(1)
    bool isEmpty() const;

    // Description: Inserts newElement at the "back" of this Queue 
    //              (not necessarily the "back" of this Queue's data structure) 
    //              and returns true if successful, otherwise false.
    // Time Efficiency: O(1)
    bool enqueue(ElementType & newElement);

    // Description: Removes (but does not return) the element at the "front" of this Queue 
    //              (not necessarily the "front" of this Queue's data structure).
    // Precondition: This Queue is not empty.
    // Exception: Throws EmptyDataCollectionException if this Queue is empty.   
    // Time Efficiency: O(1)
    void dequeue(); 

    // Description: Returns (but does not remove) the element at the "front" of this Queue
    //              (not necessarily the "front" of this Queue's data structure).
    // Precondition: This Queue is not empty.
    // Postcondition: This Queue is unchanged by this operation.
    // Exception: Throws EmptyDataCollectionException if this Queue is empty.
    // Time Efficiency: O(1)
    ElementType& peek() const;

    // Description: Print the Queue. If Queue is empty, print empty brackets: []
    // Postcondition: This Queue is unchanged by this operation.
    // Time Efficiency O(n)
    void print() const;

/******* End of Queue Public Interface *******/
};
#include "Queue.cpp"

#endif