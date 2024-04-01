#include <iostream>
#include "BinaryHeap.h"
#include "BinaryHeap.cpp"
using std::cout, std::endl;

//* Test suite 1: BHeap of int
void testSuite1() {
    BinaryHeap<int> IBHeap;

    //* Testing edge case of remove (!WILL TERMINATE PROGRAM!)
    // cout << "Case: Removing when BHeap is empty" << endl;
    // IBHeap.remove();

    //* Testing insert + retrieve
    cout << "Inserting 1, 2, 3, 4, 5" << endl;
    for (int i = 1; i <= 5; i++)
        IBHeap.insert(i);

    cout << "The first item in the BHeap is: " << IBHeap.retrieve() << endl;

    //* Testing copy constructor + print
    BinaryHeap<int> IBHeap2(IBHeap);
    cout << "After copying into another BHeap, the new BHeap is: ";
    IBHeap2.print();

    //* Testing remove + print + getElementCount
    cout << "Removing 1, 2" << endl;
    IBHeap.remove();
    IBHeap.remove();

    cout << "After removing, the BHeap is: ";
    IBHeap.print();
    cout << "Testing getElementCount. Should be False(0): " << (IBHeap.getElementCount() == 0) << endl;
    cout << "Copied BHeap is still: ";
    IBHeap2.print();

    //* Testing inserting more than initial capacity + print (private)
    cout << "inserting 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14" << endl;
    for (int i = 4; i <= 14; i++)
        IBHeap.insert(i);
    
    IBHeap.print();
}

//* Test suite 2: BHeap of float
void testSuite2() {
    BinaryHeap<float> FBHeap;

    // //* Testing edge case of remove
    // cout << "Case: Removing when BHeap is empty" << endl;
    // FBHeap.remove();

    //* Testing insert + retrieve
    cout << "Inserting 1.1, 2.1, 3.1" << endl;
    for (float i = 1.1; i <= 3.3; i += 1)
        FBHeap.insert(i);

    cout << "The first item in the BHeap is " << FBHeap.retrieve() << endl;

    //* Testing copy constructor + print
    BinaryHeap<float> FBHeap2(FBHeap);
    cout << "After copying into another BHeap, the new BHeap is: ";
    FBHeap2.print();

    //* Testing remove + retrieve + getElementCount
    cout << "Removing 1.1, 2.2, 3.3" << endl;
    FBHeap.remove();
    FBHeap.remove();
    FBHeap.remove();

    cout << "After removing, the BHeap is: ";
    FBHeap.print();
    cout << "Testing getElementCount. Should be True(1): " << (FBHeap.getElementCount() == 0) << endl;
    cout << "Copied BHeap is still: ";
    FBHeap2.print();

    //* Testing inserting more than initial capacity + print (private)
    cout << "inserting 4.1, 5.1, 6.1, 7.1, 8.1, 9.1, 10.1, 11.1, 12.1, 13.1, 14.1" << endl;
    for (float i = 4.1; i <= 15; i += 1)
        FBHeap.insert(i);
    
    FBHeap.print();
}

int main() {
    testSuite1();
    cout << endl << endl;
    testSuite2();
    return 0;
}