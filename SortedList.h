// File Name: SortedList.h
// Author: Austin Wilson
// Date: 11/19/2024

#ifndef SORTEDLIST_H
#define SORTEDLIST_H
#include <string>
#include <iostream>

class SortedList
{ 
   private:
      struct ListNode      // the node data type
      {
         std::string value;     // data
         ListNode *next;   // ptr to next node
      };
      ListNode *head;      // the list head
      int maxSize;         // max list size
      int count;           // current size

   public:
      SortedList(int);     // creates an empty list of a given max size
      ~SortedList();

      void insert(std::string);
      bool remove(std::string);
      bool isEmpty();
      bool isFull();
      void displayList(std::ostream& out);
      void increaseMaxSize(int increase);
};

#endif
