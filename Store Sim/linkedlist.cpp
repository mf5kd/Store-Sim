// linkedlist.cpp
#include "linkedlist.h"

Linked::Linked() { headPtr = nullptr; }
Linked::Linked(Customer d) {
    Node* tempPtr = new Node;
    tempPtr->Cart = d;
    tempPtr->nextPtr = nullptr;
}

void Linked::addNode(Customer d) {
    // create a new node and putting in the data
    Node* newNode = new Node;
    newNode->Cart = d;
    newNode->nextPtr = nullptr;

    // if list is empty, the new node is top of list
    if (headPtr == nullptr) {
        headPtr = newNode;
    }
    // if what we are adding needs to go first
    // set next pointer to point to header
    // reset head node to point to the new 'top'
    else if (headPtr->Cart.Id > newNode->Cart.Id) {
        newNode->nextPtr = headPtr;
        headPtr = newNode;
    }
    // start at the top of the list
    // advance the tempPtr to the spot right before insertion
    else {
        Node* tempPtr = headPtr;
        while (tempPtr != nullptr && tempPtr->nextPtr != nullptr &&
            newNode->Cart.Id > tempPtr->nextPtr->Cart.Id) {
            tempPtr = tempPtr->nextPtr;
        }
        // adjust the pointers
        newNode->nextPtr = tempPtr->nextPtr;
        tempPtr->nextPtr = newNode;
    }
}

void Linked::delNode(int id) {
    if (headPtr == nullptr) {
        cout << "Can not delete from an empty list\n";
        return;
    }
    if (headPtr->Cart.Id == id) {
        Node* delNode = headPtr;
        headPtr = headPtr->nextPtr;
        delete delNode;
        delNode = nullptr;
        return;
    }
    Node* tempPtr = headPtr;
    while (tempPtr != nullptr && tempPtr->nextPtr != nullptr &&
        tempPtr->nextPtr->Cart.Id < id)
        tempPtr = tempPtr->nextPtr;
    if (tempPtr->nextPtr->Cart.Id == id) {
        Node* delNode = tempPtr->nextPtr;
        tempPtr->nextPtr = tempPtr->nextPtr->nextPtr;
        delete delNode;
        delNode = nullptr;
        return;
    }
    cout << "Item not found\n";
}

void Linked::PrintCart(int id) {
    if (headPtr == nullptr) {
        cout << "Can not get from an empty list\n";
        return;
    }
    if (headPtr->Cart.Id == id) {
        cout << "ID: " << headPtr->Cart.Id
            << " ; Number of Items: " << headPtr->Cart.NumOfItems
            << " ; Time in Store: " << headPtr->Cart.TimeInStore << endl;
        return;
    }
    Node* tempPtr = headPtr;
    while (tempPtr != nullptr && tempPtr->nextPtr != nullptr &&
        tempPtr->nextPtr->Cart.Id < id)
        tempPtr = tempPtr->nextPtr;
    if (tempPtr->nextPtr->Cart.Id == id) {
        cout << "ID: " << tempPtr->nextPtr->Cart.Id
            << " ; Number of Items: " << tempPtr->nextPtr->Cart.NumOfItems
            << " ; Time in Store: " << tempPtr->nextPtr->Cart.TimeInStore << endl;
        return;
    }
    cout << "Item not found\n";
}

void Linked::printList() {
    Node* tempPtr = headPtr;
    while (tempPtr != nullptr) {
        cout << "ID: " << tempPtr->Cart.Id
            << " ; Number of Items: " << tempPtr->Cart.NumOfItems
            << " ; Time in Store: " << tempPtr->Cart.TimeInStore << endl;
        tempPtr = tempPtr->nextPtr;
    }
}

Customer Linked::GetCart(int id) {
    Node* tempPtr = headPtr;
    while (tempPtr != nullptr) {
        if (tempPtr->Cart.Id == id) {
            return tempPtr->Cart;
        }
        tempPtr = tempPtr->nextPtr;
    }
    return error;
}