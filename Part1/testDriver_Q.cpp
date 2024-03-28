#include <iostream>
#include "Queue.h"
using std::cout, std::endl;

//* Test suite 1: Queue of int
void testSuite1() {
    Queue<int> IQueue;

    //* Testing edge case of dequeue
    cout << "Case: Dequeuing when Queue is empty" << endl;
    IQueue.dequeue();

    //* Testing enqueue + peek
    cout << "Enqueuing 1, 2, 3" << endl;
    for (int i = 0; i <= 3; i++)
        IQueue.enqueue(i);

    cout << "The first item in the Queue is" << IQueue.peek() << endl;

    //* Testing dequeue + peek + isEmpty
    cout << "Dequeueing 1, 2" << endl;
    IQueue.dequeue();
    IQueue.dequeue();

    cout << "The only item in Queue is" << IQueue.peek() << endl;
    cout << "Testing isEmpty. Should be False:" << IQueue.isEmpty() << endl;

    //* Testing inserting more than initial capacity + print (private)
    cout << "Enqueueing 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14" << endl;
    for (int i = 4; i <= 14; i++)
        IQueue.enqueue(i);
    
    IQueue.print();
}

//* Test suite 2: Queue of float
void testSuite2() {
    Queue<float> IQueue;

    //* Testing edge case of dequeue
    cout << "Case: Dequeuing when Queue is empty" << endl;
    IQueue.dequeue();

    //* Testing enqueue + peek
    cout << "Enqueuing 1.1, 2.1, 3.1" << endl;
    for (float i = 0; i <= 3.3; i += 1)
        IQueue.enqueue(i);

    cout << "The first item in the Queue is" << IQueue.peek() << endl;

    //* Testing dequeue + peek + isEmpty
    cout << "Dequeueing 1.1, 2.2" << endl;
    IQueue.dequeue();
    IQueue.dequeue();

    cout << "The only item in Queue is" << IQueue.peek() << endl;
    cout << "Testing isEmpty. Should be False:" << IQueue.isEmpty() << endl;

    //* Testing inserting more than initial capacity + print (private)
    cout << "Enqueueing 4.1, 5.1, 6.1, 7.1, 8.1, 9.1, 10.1, 11.1, 12.1, 13.1, 14.1" << endl;
    for (float i = 4.1; i <= 14.1; i += 1)
        IQueue.enqueue(i);
    
    IQueue.print();
}



int main() {
    testSuite1();
    testSuite2();
    return 0;
}