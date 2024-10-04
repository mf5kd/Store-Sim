// linkedlist.h
#pragma once
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct Customer {
	int Id = 0;
	float TimeInStore = 0;
	int NumOfItems = 0;
};

struct Node {
	Customer Cart;
	Node* nextPtr;
};

class Linked {
private:
	Node* headPtr;

public:
	Customer error = { 0, 0, 0 };
	Linked();
	Linked(Customer d);
	Customer GetCart(int id);
	void PrintCart(int id);
	void addNode(Customer d);
	void delNode(int id);
	void printList();
};