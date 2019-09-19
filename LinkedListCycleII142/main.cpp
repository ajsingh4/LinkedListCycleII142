//
//  main.cpp
//  LinkedLinkCycle141
//
//  Created by Aj Gill on 8/18/19.
//  Copyright © 2019 Aj Gill. All rights reserved.
//

#include <iostream>
#include <stdio.h>

using namespace std;

class LList{
private:
    //Represents each node in the LL
    struct ListNode{
        int data;
        ListNode* next;
    };
    typedef struct ListNode* nodePtr;
    nodePtr head, current, temp;
    
public:
    LList(){
        head = NULL;
        current = NULL;
        temp = NULL;
    };
    void Insert(int addData) {
        nodePtr n = new ListNode;
        n->next = NULL;
        n->data = addData;
        if(head != NULL){
            current = head;
            while(current->next != NULL){
                current = current->next;
            }
            current->next = n;
        }
        else{
            head = n;
        }
    };
    
    void Remove(int removeData) {
        nodePtr delPtr = NULL;
        temp = head;
        current = head;
        while(current != NULL && current->data != removeData){
            temp = current;
            current = current->next;
        }
        if(current == NULL){
            cout << removeData << " was not in the list\n";
            delete delPtr;
        }
        else{
            delPtr = current;
            current = current->next;
            temp->next = current;
            if(delPtr == head){
                head = head->next;
                temp = NULL;
            }
            delete delPtr;
            cout << "The value " << removeData << " was deleted\n";
        }
    };
    
    void printList() {
        current = head;
        while(current != NULL){
            cout << current->data << " - ";
            current = current->next;
        }
        cout << "\n";
    };
    
    void printCycleStatus() {
        cout << "Does this linkedlist have a cycle: " << detectCycle(head) << "\n";
    };
    
    ListNode *detectCycle(ListNode *head) {
        bool hasCycle = false;
        ListNode *fastPtr = head;
        ListNode *slowPtr = head;
        //Using 2 pointer approach detect if there is a cycle
        while(fastPtr && fastPtr->next){
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
            if(fastPtr == slowPtr){
                hasCycle = true;
                break;
            }
        }
        //If there isn't a cycle, return null
        if(!hasCycle){
            return NULL;
        }
        //Essentially, the distance from the beginning to the first node of the cycle
        //is equivalent to the distance from the meeting point to the first node of the cycle
        //Using this logic, the slowPtr is reset and each Ptr is incremented by 1 until they meet
        slowPtr = head;
        while(fastPtr && slowPtr != fastPtr){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }
        return slowPtr;
    }
};


int main() {
    LList Aj;
    Aj.Insert(3);
    Aj.Insert(2);
    Aj.Insert(0);
    Aj.Insert(-4);
    Aj.printCycleStatus();
    Aj.printList();
}
