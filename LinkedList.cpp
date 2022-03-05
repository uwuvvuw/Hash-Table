//class for a linked list as a data structure
#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP

#include <iostream>
using namespace std;
template <typename T>
struct Node { //node connect with another node
  T info; //store key
  Node<T> *next; // pointer to the next node, which stores another key (chaining)
};

template <typename T>
class LinkedList {
    Node<T> *start;
    public:
    LinkedList() { start = NULL; }
    ~LinkedList() { makeEmpty(); }

    // this inserts new node at the beginning of the linked list
    void insertFront (T & element ) {
        Node<T> *newNode = new Node<T>;
        newNode->info = element;
        newNode->next = start;
        start = newNode;
    }

    // returns true if element is found; returns false if element is not found
    bool find (T const& target) {
        bool found = false;
        Node<T> *ptr = start;
        while (ptr != NULL && !found) {
                if (ptr->info == target) {
                    found = true;
        }
        else
            ptr = ptr->next;
        }
        return found;
    }

    // checks whether linked list is empty
    bool isEmpty() { return start == NULL; }

    void makeEmpty() {
        while (start != NULL) {
        Node<T> *ptr  = start;
        start = start->next;
        delete ptr;
        }
    }

    //prints out elements in the linked list
    friend ostream& operator<< (ostream& os, LinkedList<T>& list) {
        Node<T> *ptr = list.start;
        while (ptr != NULL) {
        os << ptr->info << " ";
        ptr = ptr->next;
        }
        return os;
    }
};

#endif
