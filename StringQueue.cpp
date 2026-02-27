// File Name: StringQueue.cpp
// Author: Austin Wilson
// Date: 11/19/2024

#include "StringQueue.h"
#include <cassert>
#include <iostream>

//***********************************************
//StringQueue(): constructor which takes an integer
//argument and assigns it to the maxSize and assigns
//minimum values to each private member variable
//and initializes the queueArray pointer
//***********************************************
StringQueue::StringQueue(int n) {
    maxSize = n;
    queueArray = new string[maxSize]; // Dynamically allocate the array
    front = 0;
    rear = -1;
    numItems = 0;
}

//***********************************************
//~StringQueue(): destructor which takes deallocates
//any memory still stored in the pointer array
//***********************************************
StringQueue::~StringQueue() {
    delete[] queueArray;
}

//***********************************************
//enqueue(): takes an string argument and adds it
//to the last spot in the array, if its available
//***********************************************
int StringQueue::enqueue(string s) {
    assert (!isFull());

    rear = (rear + 1) % maxSize;
    queueArray[rear] = s;
    numItems++;
    
    return numItems;
}

//***********************************************
//dequeue(): removes the first item in the array
//and sends it to main.cpp
//***********************************************
string StringQueue::dequeue() {
    assert(!isEmpty()); // Prevent removing if empty

    string item = queueArray[front]; // Get the front item
    front = (front + 1) % maxSize;   // Increment front (circularly)
    numItems--;                      // Decrement count

    return item; // Return the dequeued item
}

//***********************************************
//isEmpty(): checks if there is room in
//the array
//***********************************************
bool StringQueue::isEmpty() {
    return (numItems == 0);
}

//***********************************************
//isFull(): checks if there is no room in
//the array
//***********************************************
bool StringQueue::isFull() {
    return (numItems == maxSize);
}

//***********************************************
//display(): adds various string values from the
//array pointer and sends them pass by reference
//to main.cpp
//***********************************************
void StringQueue::display(ostream& out) {
    if (isEmpty()) { // Use isEmpty() for readability
        return;
    }

    int i = front;
    for (int c = 0; c < numItems; c++) {
        out << (c + 1) << " " << queueArray[i] << endl; // Numbered output
        i = (i + 1) % maxSize; // Circular increment
    }
}
