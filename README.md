# Student Enrollment System (C++)

A multi-module enrollment management system that demonstrates advanced Data Structures and Object-Oriented Programming (OOP) in C++. This project manages class rosters using a sorted linked list and handles overflow via a circular waitlist queue.

## Key Technical Features
- **Sorted Linked List:** Implemented custom insertion and removal logic to maintain an alphabetical student roster.
- **Circular Queue:** Developed a waitlist buffer using a queue data structure to manage students when class capacity is reached.
- **Memory Management:** Utilizes dynamic memory allocation for roster scaling and includes proper cleanup to prevent memory leaks.
- **Multi-Module Architecture:** Organized into discrete header (`.h`) and implementation (`.cpp`) files for improved maintainability and encapsulation.

## Logic Overview
1. **Add Command:** Attempts to insert a student into the `SortedList`. If full, the system prompts to join the `StringQueue` waitlist.
2. **Drop Command:** Removes a student from the roster and automatically prompts to fill the vacancy from the front of the waitlist.
3. **Dynamic Scaling:** Includes logic to increase maximum class size mid-session, triggering an automatic processing of the waitlist.

## How to Compile
Compile all modules together using g++:
```bash
g++ main.cpp SortedList.cpp StringQueue.cpp -o EnrollmentSystem
./EnrollmentSystem
