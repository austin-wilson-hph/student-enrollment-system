// File Name: StringQueue.h
// Author: Austin Wilson
// Date: 11/19/2024

#ifndef STRINGQUEUE_H
#define STRINGQUEUE_H
#include <string>
#include <iostream>

class StringQueue
{
private:
    
    int maxSize;
    std::string* queueArray;
    int front;
    int rear;
    int numItems;
    
public:
    // Constructor
    StringQueue(int);
    ~StringQueue();
    
    // Queue operations
    int enqueue(std::string);  //returns position where inserted, front is 1
    std::string dequeue();
    bool isEmpty();
    bool isFull();
    void display(std::ostream& out);
};

#endif