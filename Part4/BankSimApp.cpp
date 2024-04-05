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
    }
    //Event loop
    while (!myQueue->isEmpty()){
        Event newEvent = myQueue->peek();
        myQueue->dequeue();
        int currentTime = newEvent.getTime();

        if (newEvent.getType() == 'A'){
            if (bankLine->isEmpty() && tellerAvailable == true){
                cout << "Processing an arrival event at time:     " << currentTime << endl;
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
                Event Cdprt('D', currentTime + C.getLength());
                myQueue->enqueue(Cdprt);
                cout << "Processing a departure event at time:    " << currentTime + C.getLength() << endl;
            }else{
                tellerAvailable = true;
            }
        }
    }
}

/*int main() {
    PriorityQueue<Event>* myQueue = new PriorityQueue<Event>();
    

    if (myQueue != nullptr){
        string aLine = "";
        string time = "";
        string length = "";
        string filename = "";  
        string delimiter = " ";
        size_t pos = 0;
        int count = 0;
        int wait = 0;
        cout << "Simulation Begins" << endl;
        while (getline(cin, aLine)){
            pos = aLine.find(delimiter);
            time = aLine.substr(0, pos);
            aLine.erase(0, pos + delimiter.length());
            length = aLine;
            int T = stoi(time);
            int L = stoi(length);
            Event newArvl('A', T, L);
            myQueue->enqueue(newArvl);
            count++;
        }
        
        while (!myQueue->isEmpty()){
            Event currentE = myQueue->peek();
            if (currentE.getType() == 'A'){
                cout << "Processing an arrival event at time:     " << currentE.getTime() << endl;
                wait += currentE.getLength();
                int T = currentE.getTime();
                Event dprt('D', T + currentE.getLength());
                myQueue->enqueue(dprt);
            }else{
                cout << "Processing a departure event at time:    " << currentE.getTime() << endl;
                wait -= currentE.getLength();
            }
            myQueue->dequeue();
        }
        cout << "Simulation Ends" << endl;
        cout << endl;
        cout << "Final Statistics:" << endl;
        cout << endl;
        cout << "	Total number of people processed: " << count << endl;
        cout << "	Average amount of time spent waiting: " << endl;}
    myQueue->~PriorityQueue();
    delete[] myQueue;
    return 0;	   
} */