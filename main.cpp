// File Name: main.cpp
// Author: Austin Wilson
// Date: 11/19/2024

#include "SortedList.h"
#include "StringQueue.h"
#include <iostream>

//***********************************************
//int main(): initializes SortedList and
//StringQueue to be able to call their various
//functions. These functions are called to add or
//drop names from SortedList's various string values
//and if the linked list in SortedList is full
//main.cpp calls upon StringQueue to add or drop
//names from user input to add them to a waiting
//list
//***********************************************
int main() {
    
    int classSize, waitListSize;
    
    cout << "Enter class size: ";
    cin >> classSize;
    
    cout << "Enter wait list size: ";
    cin >> waitListSize;
    
    SortedList classRoster(classSize);
    StringQueue waitList(waitListSize);
    
    string command;
    char choice;
    string studentName;
    int studentsWaitlist = 0;
    int studentsProcessed = 0;
    
    cout << "Enter the commands:" << endl;
    do {
        cin >> command;

        if (command == "add") {
            cin >> studentName;
            
            if (!classRoster.isFull()) {
                classRoster.insert(studentName);
                
            } else {
                cout << ">Class is full, join the wait list (y/n)?" << endl;
                cin >> choice;
                
                if (!waitList.isFull() && choice == 'y') {
                         
                    int position = waitList.enqueue(studentName);
                    cout << ">Added at position " << position << endl;
                    studentsWaitlist++;
                        
                } else if (waitList.isFull()) {
                    cout << ">Wait List is also full. Sorry." << endl;
                }
            }
        }
            
        else if (command == "drop") {
            cin >> studentName;
            if (classRoster.remove(studentName)) {
                
                bool studentAdded = false;
                    
                while (!waitList.isEmpty() && studentsProcessed
                           < studentsWaitlist && !classRoster.isFull()) {
                    
                    string nextStudent = waitList.dequeue();
                    cout << ">Add " << nextStudent << " to the class (y/n)?" << endl;
                    cin >> choice;
                    
                    if (choice == 'y') {
                        classRoster.insert(nextStudent);
                        studentAdded = true;
                        break;
                    }
                    
                    if (choice == 'n') {
                        studentAdded = true;
                        }
                    
                        studentsProcessed++;
                        
                }
                
                if (!studentAdded) {
                    cout << ">No one added to the roster. Wait list is empty." << endl;
                }
            }
        }
            
        else if (command == "pr") {
            cout << ">Roster:" << endl;
            classRoster.displayList(cout);
        }
            
        else if (command == "pwl") {
            cout << ">Wait list:" << endl;
            waitList.display(cout);
        }
            
        else if (command == "incr") {
            int sizeIncrease;
            cin >> sizeIncrease;
            classRoster.increaseMaxSize(sizeIncrease);
            
            bool studentAdded = false;
                
            while (!waitList.isEmpty() && studentsProcessed
                       < studentsWaitlist && !classRoster.isFull()) {
                
                string nextStudent = waitList.dequeue();
                cout << ">Add " << nextStudent << " to the class (y/n)?" << endl;
                cin >> choice;
                if (choice == 'y') {
                    classRoster.insert(nextStudent);
                    studentAdded = true;
                }
                    
                studentsProcessed++;
                    
            }
            
            if (!studentAdded && waitList.isEmpty()) {
                    cout << ">No one added to the roster. Wait list is empty." << endl;
                }
        }
            
        } while (command != "quit");

        return 0;
    }
