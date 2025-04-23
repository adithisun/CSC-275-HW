//
// Created by Adithi Sunke on 4/22/25.
//

#ifndef ASUNKE_HW5_Q1_MYLIST_H
#define ASUNKE_HW5_Q1_MYLIST_H

#include <iostream>
using namespace std;

template <typename T>
class MyList;  

template <typename T>
class Node {
    T data;
    Node* next;

    Node(T val) : data(val), next(nullptr) {}

    friend class MyList<T>;  
};

template <typename T>
class MyList {
private:
    Node<T>* head;  

public:
    MyList() : head(nullptr) {}

    void insertHead(T theData) {
        Node<T>* newNode = new Node<T>(theData);
        newNode->next = head;
        head = newNode;
    }

    T deleteHead() {
        if (!head) throw runtime_error("List is empty");
        Node<T>* temp = head;
        T val = temp->data;
        head = head->next;
        delete temp;
        return val;
    }

    bool search(T& target) {
        Node<T>* current = head;
        while (current) {
            if (current->data == target) {
                target = current->data;  
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void display() {
        Node<T>* current = head;
        while (current) {
            cout << current->data << endl;
            current = current->next;
        }
    }

    ~MyList() {
        while (head) deleteHead();  
    }
};

#endif //ASUNKE_HW5_Q1_MYLIST_H
