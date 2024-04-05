 /* 
 * BankSimApp.cpp
 *
 * Description: A bank teller simulation with priority queue & binary heap class
 *
 * 
 * Author: Cole Ackerman
 * Last Modification: April 2024
 *
 */

#include <iostream>
#include <string>
#include "PriorityQueue.h"
#include "PriorityQueue.cpp"
#include "Queue.h"
#include "EmptyDataCollectionException.h"
#include <sstream>
#include <fstream>
#include <iomanip>
//! iomanip to get std::right and std::setw for setting right-justified and setting fixed width

using std::cin;
using std::cout;
using std::ifstream;
using std::nothrow;

int main() {
    Queue<Event>* bankLine = new Queue<Event>();
    PriorityQueue<Event>* myPQueue = new PriorityQueue<Event>();
    bool tellerAvailable = true;

    //* Variables to handle inputs
    string aLine = "";
    string time = "";
    string length = "";
    string delimiter = " ";

    size_t pos = 0;
    int count = 0;
    float waitTime = 0;
    
    //* Add arrival events to Event queue
    while (getline(cin, aLine)){
        //* Receiving info from input file
        pos = aLine.find(delimiter);
        time = aLine.substr(0, pos);
        aLine.erase(0, pos + delimiter.length());
        length = aLine;

        //* Changing data type to work with integers
        int T = stoi(time);
        int L = stoi(length);
        Event newArrivalEvent('A', T, L);
        myPQueue->enqueue(newArrivalEvent);
        count++;
    }

    //* Starting Process
    cout << "Simulation Begins" << endl;
    while (!myPQueue->isEmpty()){
        //* Get new Event
        Event newEvent = myPQueue->peek();
        myPQueue->dequeue();
        int currentTime = newEvent.getTime();

        if (newEvent.getType() == 'A'){             //* Arrival
            cout << "Processing an arrival event at time: " << std::right << std::setw(4) << currentTime << endl;
            
            //* If no one in line or at counter, process current customer; else enqueue into bankLine
            if (bankLine->isEmpty() && tellerAvailable == true){
                Event departureA('D', currentTime + newEvent.getLength());
                myPQueue->enqueue(departureA);
                tellerAvailable = false;
            }
            else
                bankLine->enqueue(newEvent);
        }
        else {                                      //* Departure
            cout << "Processing a departure event at time: " << std::right << std::setw(3) << currentTime << endl;
            
            //* If bankLine not empty, process first customer in Line, enqueue into PQueue for later discharge
            if (!bankLine->isEmpty()){
                Event customerInLine = bankLine->peek();
                bankLine->dequeue();

                Event departureD('D', currentTime + customerInLine.getLength());
                myPQueue->enqueue(departureD);
                waitTime += currentTime - customerInLine.getTime();
            }
            else
                tellerAvailable = true;
        }
    }
    cout << "Simulation Ends" << endl << endl;
    cout << "Final Statistics:" << endl << endl;
    cout << "   Total number of people processed: " << count << endl;
    cout << "   Average amount of time spent waiting: " << waitTime/count << endl;

    delete bankLine;
    delete myPQueue;
    return 0;
}