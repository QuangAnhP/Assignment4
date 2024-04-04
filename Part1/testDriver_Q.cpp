#include <iostream>
#include "Queue.h"
using std::cout, std::endl;

//* Test suite 1: Queue of int
void testSuite1() {
    Queue<int> IQueue;

    //* Testing edge case of dequeue
    // cout << "Case: Dequeuing when Queue is empty" << endl;
    // IQueue.dequeue();

    //* Testing enqueue + peek
    cout << "Enqueuing 1, 2, 3" << endl;
    for (int i = 1; i <= 3; i++)
        IQueue.enqueue(i);

    cout << "The first item in the Queue is: " << IQueue.peek() << endl;

    //* Testing copy constructor + print
    Queue<int> IQueue2(IQueue);
    cout << "After copying into another Queue, the new Queue is: ";
    IQueue2.print();

    //* Testing dequeue + print + isEmpty
    cout << "Dequeueing 1, 2" << endl;
    IQueue.dequeue();
    IQueue.dequeue();

    cout << "After dequeueing, the Queue is: ";
    IQueue.print();
    cout << "Testing isEmpty. Should be False(0): " << IQueue.isEmpty() << endl;
    cout << "Copied Queue is still: ";
    IQueue2.print();

    //* Testing inserting more than initial capacity + print (private)
    cout << "Enqueueing 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14" << endl;
    for (int i = 4; i <= 14; i++)
        IQueue.enqueue(i);
    
    IQueue.print();
}

//* Test suite 2: Queue of float
void testSuite2() {
    Queue<float> FQueue;

    // //* Testing edge case of dequeue
    // cout << "Case: Dequeuing when Queue is empty" << endl;
    // FQueue.dequeue();

    //* Testing enqueue + peek
    cout << "Enqueuing 1.1, 2.1, 3.1" << endl;
    for (float i = 1.1; i <= 3.3; i += 1)
        FQueue.enqueue(i);

    cout << "The first item in the Queue is " << FQueue.peek() << endl;

    //* Testing copy constructor + print
    Queue<float> FQueue2(FQueue);
    cout << "After copying into another Queue, the new Queue is: ";
    FQueue2.print();

    //* Testing dequeue + peek + isEmpty
    cout << "Dequeueing 1.1, 2.2" << endl;
    FQueue.dequeue();
    FQueue.dequeue();

    cout << "After dequeueing, the Queue is: ";
    FQueue.print();
    cout << "Testing isEmpty. Should be False(0): " << FQueue.isEmpty() << endl;
    cout << "Copied Queue is still: ";
    FQueue2.print();

    //* Testing inserting more than initial capacity + print (private)
    cout << "Enqueueing 4.1, 5.1, 6.1, 7.1, 8.1, 9.1, 10.1, 11.1, 12.1, 13.1, 14.1" << endl;
    for (float i = 4.1; i <= 15; i += 1)
        FQueue.enqueue(i);
    
    FQueue.print();
}

int main() {
    testSuite1();
    cout << endl << endl;
    testSuite2();
    return 0;
}