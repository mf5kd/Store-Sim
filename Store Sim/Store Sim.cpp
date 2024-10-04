// Final_project.cpp : This file contains the 'main' function. Program execution

// main.cpp
#include "linkedlist.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ofstream fout("output.txt");

    Linked list, queue, queue2;
    vector<Customer> CurrentCustomers, NewCustomers;
    int NumOfIds = 1, StoreHours = 100; // time = 720 min

    srand(time(0));

    // Every Minutes in the stores
    for (int time = 1; time <= StoreHours; ++time) {
        // adds to queue
        for (int i = 0; i < CurrentCustomers.size(); ++i) {
            if (list.GetCart(i).TimeInStore == time ||
                list.GetCart(i).TimeInStore < time) {
                if (list.GetCart(i).Id != 0 && time % 2 == 0) {
                    queue.addNode(list.GetCart(i));
                    list.delNode(i);
                }
                else if (list.GetCart(i).Id != 0) {
                    queue2.addNode(list.GetCart(i));
                    list.delNode(i);
                }
            }
        }

        // Gets the Number of Customers that Enter the this Minute
        int NumOfCust = (rand() % 3) + 1;
        // Sets the Number of Customers
        for (int i = 0; i < NumOfCust; ++i) {
            Customer temp;
            temp.Id = NumOfIds;
            NewCustomers.push_back(temp);
            NumOfIds++;
        }
        fout << "Number of Customers added: " << NumOfCust << endl;
        // Set Number of Items
        for (int i = 0; i < NewCustomers.size(); ++i) {
            int PercentOfItems = (rand() % 100) + 1;
            // 10%
            if (PercentOfItems <= 10) {
                int NumOfItems = (rand() % 30) + 31;
                NewCustomers[i].NumOfItems = NumOfItems;
            }
            // 20%
            else if (PercentOfItems <= 30) {
                int NumOfItems = (rand() % 10) + 21;
                NewCustomers[i].NumOfItems = NumOfItems;
            }
            // 30%
            else if (PercentOfItems <= 60) {
                int NumOfItems = (rand() % 10) + 11;
                NewCustomers[i].NumOfItems = NumOfItems;
            }
            // 40%
            else if (PercentOfItems <= 100) {
                int NumOfItems = (rand() % 10) + 1;
                NewCustomers[i].NumOfItems = NumOfItems;
            }
        }
        // Set Number of time in store
        for (int i = 0; i < NewCustomers.size(); ++i) {
            for (int n = 0; n < NewCustomers[i].NumOfItems; ++n) {
                float seconds = 0;
                float NumOfSeconds = (rand() % 31) + 30;
                seconds = (NumOfSeconds / 6) * 0.10;
                NewCustomers[i].TimeInStore =
                    (NewCustomers[i].TimeInStore + seconds) + time;
            }
        }
        // Puts New Customers into Current Customers Vector
        for (int i = 0; i < NewCustomers.size(); ++i) {
            CurrentCustomers.push_back(NewCustomers[i]);
            list.addNode(NewCustomers[i]);
        }
        // Clears New Customers Vecltor
        NewCustomers.clear();
    }
    fout << endl << "number of total:" << CurrentCustomers.size() << endl;

    for (int i = 0; i < CurrentCustomers.size(); ++i) {
        fout << "\nID: " << CurrentCustomers[i].Id << endl
            << "Time In Store: " << CurrentCustomers[i].TimeInStore << endl
            << "Number of Items: " << CurrentCustomers[i].NumOfItems << endl;
    }
    list.printList();
    cout << "========================================================\nQueue\n";
    queue.printList();
    cout << "========================================================\nQueue\n";
    queue2.printList();
    fout.close();
}
// 1-10 = 10% 11-30 = 20% 31-60 = 30% 61-100 = 40%