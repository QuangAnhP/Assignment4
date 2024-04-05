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


using std::cin;
using std::cout;
using std::ifstream;
using std::nothrow;

int main() {
    Queue<Event>* bankLine = new Queue<Event>();
    PriorityQueue<Event>* myQueue = new PriorityQueue<Event>();

    bool tellerAvailable = true;

    string aLine = "";
    string time = "";
    string length = "";
    string filename = "";  
    string delimiter = " ";
    size_t pos = 0;
    float count = 0;
    float Twaiting = 0;
    
    //Add arrival events to event queue
    while (getline(cin, aLine)){
        pos = aLine.find(delimiter);
        time = aLine.substr(0, pos);
        aLine.erase(0, pos + delimiter.length());
        length = aLine;
        int T = stoi(time);
        int L = stoi(length);
        Event newArrivalEvent('A', T, L);
        myQueue->enqueue(newArrivalEvent);
        count++;
    }
    //Event loop
    cout << "Simulation Begins" << endl;
    while (!myQueue->isEmpty()){
        Event newEvent = myQueue->peek();
        myQueue->dequeue();
        int currentTime = newEvent.getTime();

        if (newEvent.getType() == 'A'){
            cout << "Processing an arrival event at time:     " << currentTime << endl;
            if (bankLine->isEmpty() && tellerAvailable == true){
                Event dprt('D', currentTime + newEvent.getLength());
                myQueue->enqueue(dprt);
                tellerAvailable = false;
            }else{
                bankLine->enqueue(newEvent);
            }
        }else{
            cout << "Processing a departure event at time:    " << currentTime << endl;
            if (!bankLine->isEmpty()){
                Event C = bankLine->peek();
                bankLine->dequeue();
                Twaiting += currentTime - C.getTime();
                Event Cdprt('D', currentTime + C.getLength());
                myQueue->enqueue(Cdprt);
            }else{
                tellerAvailable = true;
            }
        }
    }
    cout << "Simulation Ends" << endl;
    cout << endl;
    cout << "Final Statistics:" << endl;
    cout << endl;
    cout << "	Total number of people processed: " << count << endl;
    cout << "	Average amount of time spent waiting: " << Twaiting/count << endl;

    delete bankLine;
    delete myQueue;
    return 0;
}