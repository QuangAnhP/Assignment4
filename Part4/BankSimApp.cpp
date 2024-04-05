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
#include "EmptyDataCollectionException.h"
#include <sstream>
#include <fstream>


using std::cin;
using std::cout;
using std::ifstream;
using std::nothrow;

int main() {
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
        int dTime;
        cout << "Simulation Begins" << endl;
        while (getline(cin, aLine)){
            pos = aLine.find(delimiter);
            time = aLine.substr(0, pos);
            aLine.erase(0, pos + delimiter.length());
            length = aLine;
            int T = stoi(time);
            int L = stoi(length);
            if (myQueue->isEmpty()){
                dTime = T + L;
            }else{
                if (T < myQueue->peek().getTime() + myQueue->peek().getLength()){
                    dTime = myQueue->peek().getTime() + myQueue->peek().getLength() + L;
                }else{
                    dTime = T + L;
                }
                
            }
            Event newArvl('A', T, L);
            Event newDprt('D', dTime);
            wait += L;
            myQueue->enqueue(newArvl);
            myQueue->enqueue(newDprt); 
            count++;
        }
        while (!myQueue->isEmpty()){
            Event currentE = myQueue->peek();
            if (currentE.getType() == 'A'){
                cout << "Processing an arrival event at time:     " << currentE.getTime() << endl;
            }else{
               
                cout << "Processing a departure event at time:    " << currentE.getTime() << endl;
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
} 