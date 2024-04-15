#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

// Forward declaration of MyList class
template<typename T>
class MyList;

// Node class template definiton
template<typename T>
class Node{
    friend class MyList<T>; // Allow MyList class to access private members of Node

private:
    T data; // Data stored in the node
    Node<T>* next;  // Pointer to the next node in the list

public:
    Node(T newData) : data(newData), next(nullptr){}    // Constructor initializing data and next
};

// MyList class template definition
template<typename T>
class MyList{
private:
    Node<T>* head;  // Pointer to the head of the list

public:
    MyList(): head(nullptr){}   // Constructor initializing head to nullptr
    ~MyList();  // Destructor to free memory allocated for nodes

    void insertHead(T theData); // Function to insert data at the head of the list
    T deleteHead(); // Function to delete the node at the head of the list
    bool search(T& target); // Function to search for a specific data element in the list
    void display(); // Function to display all elements in the list
};

// Destructor definition for MyList class
template<typename T>
MyList<T>::~MyList(){
    Node<T>* current = head;
    while (current != nullptr){
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}

// Function to insert data at the head of the list
template<typename T>
void MyList<T>::insertHead(T theData){
    Node<T>* newNode = new Node<T>(theData);
    newNode->next = head;
    head = newNode;
}

// Function to delete the node at the head of the list
template<typename T>
T MyList<T>::deleteHead(){
    if (head == nullptr) {
        throw runtime_error("List is empty");
    }
    T data = head->data;
    Node<T>* temp = head;
    head = head->next;
    delete temp;
    return data;
}

// Function to search for a specific data element in the list
template<typename T>
bool MyList<T>::search(T& target){
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->data == target){
            return true;
        }
        current = current->next;
    }
    return false;
}

// Function to display all elements in the list
template<typename T>
void MyList<T>::display(){
    Node<T>* current = head;
    while (current != nullptr){
        cout<<current->data << " ";
        current = current->next;
    }
    cout<<endl;
}

#endif
