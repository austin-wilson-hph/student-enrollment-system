// File Name: SortedList.cpp
// Author: Austin Wilson
// Date: 11/19/2024

#include "SortedList.h"
#include <iostream>
#include <cassert>
using namespace std;

//***********************************************
//SortedList(): constructor which takes an integer
//argument from main.cpp and assigns it to maxSize
//and makes head null and count = 0
//***********************************************
SortedList::SortedList(int size) {
    maxSize = size;
    head = nullptr;
    count = 0;
}

//***********************************************
//isEmpty(): checks if the linked list is empty
//***********************************************
bool SortedList::isEmpty() {
    return (head==nullptr);
}

//***********************************************
//isFull(): checks if linked list is full
//***********************************************
bool SortedList::isFull() {
    return (count == maxSize);
}

//***********************************************
//~SortedList(): destructor which deallocates all
//memory allocated in the private member linked
//list
//***********************************************
SortedList::~SortedList() {
    
    ListNode *p;
    while (!isEmpty()) {
        // deletes the first node
        p = head;
        head = head->next;
        delete p;
    }
}

//***********************************************
//increaseMaxSize(): takes an integer argument to
//increase the max size that the linked list can have
//***********************************************
void SortedList::increaseMaxSize(int increase) {
    // increase the maxSize of the list by the specified amount
    maxSize = maxSize + increase;
}

//***********************************************
//displayList(): takes the various values of the
//linked list and sends them pass by reference
//to output to the screen
//***********************************************
void SortedList::displayList(ostream& out) {
    //add the numbers!
    ListNode *p = head;
    int position = 1;
    while (p!=nullptr) {
        out << position << " " << p->value  << endl;
        p = p->next;
        position++;
    }
}

//***********************************************
//remove(): takes a string argument from main.cpp
//and finds where that string is located in the linked
//list and removes it and then deallocates it
//***********************************************
bool SortedList::remove(string val) {
    
    ListNode *p = head;      // to traverse the list
    ListNode *n = nullptr;   // trailing node pointer
    
    // skip nodes not equal to val, stop at last
    while (p && p->value!=val) {
        n = p;        // save it!
        p = p->next;  // advance it
    }
    
    // p not null: val is found, set links + delete
    if (p) {
        if (n==nullptr) {   // p points to the first elem.
            head = p->next;
        } else {            // n points to the predecessor
            n->next = p->next;
        }
        delete p;
        count--;
        return true;
    }
    return false; 
}

//***********************************************
//insert(): takes a string argument and finds
//its location in the linked list and sorts it
//alphabetically
//***********************************************
void SortedList::insert(string val) {
    
    assert(!isFull());

    // insert val into the list, keeping it always sorted in increasing order
    ListNode *newNode = new ListNode;
    newNode->value = val;
    newNode->next = nullptr;
    
    if (head == nullptr || val < head->value) {
        newNode->next = head;
        head = newNode;
    }
    else {
        ListNode* current = head;
        
        while (current->next != nullptr && current->next->value < val) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    count++;
}
