//
// Created by admin on 2022/2/3.
//

#include "OrdersList.h"
#include <iostream>

using namespace std;


/*    struct Node {
        string orderName;
        bool isValidate;
        int orderID;
        Node *next;
    };*/

    void OrdersList::initNode(struct Node *head, string n, bool isValidate, int orderID) {
        head->orderName = n;
        head->isValidate = isValidate;
        head->orderID = orderID;
        head->next = NULL;
    }

    void OrdersList::addNode(struct Node *head, string n, bool isValidate, int orderID) {
        Node *newNode = new Node;
        newNode->orderName = n;
        newNode->isValidate = isValidate;
        newNode->orderID = orderID;
        newNode->next = NULL;

        Node *cur = head;
        while (cur) {
            if (cur->next == NULL) {
                cur->next = newNode;
                return;
            }
            cur = cur->next;
        }
    }


    void OrdersList::insertFront(struct Node **head, string n,bool isValidate,int orderID) {
        Node *newNode = new Node;
        newNode->orderName = n;
        newNode->isValidate = isValidate;
        newNode->orderID = orderID ;
        newNode->next = *head;
        *head = newNode;
    }


      struct Node* OrdersList::searchNode(struct Node *head, int n) {
        Node *cur = head;
        while(cur) {
            if(cur->orderID == n ) return cur;
            cur = cur->next;
        }
        cout << "Cannot Find Order " << n << " in list.\n";
    }






    bool OrdersList::deleteNode(struct Node **head, Node *ptrDel) {
        Node *cur = *head;
        if (ptrDel == *head) {
            *head = cur->next;
            delete ptrDel;
            return true;
        }

        while (cur) {
            if (cur->next == ptrDel) {
                cur->next = ptrDel->next;
                delete ptrDel;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    bool OrdersList::remove(struct Node **head, int orderID) {
        int index = 0;
        Node *cur = *head;


        while (cur) {

            if (orderID == index) {
                return deleteNode(head, cur);
            }
            cur = cur->next;
            index++;
        }
        return false;

    }


    void OrdersList::deleteLinkedList(struct Node **node) {
        struct Node *tmpNode;
        while (*node) {
            tmpNode = *node;
            *node = tmpNode->next;
            delete tmpNode;
        }
    }

    void OrdersList::display(struct Node *head) {
        Node *list = head;
        while (list) {
            cout << list->orderName << " ";
            cout << list->isValidate <<" ";
            cout << list->orderID <<" ";
            list = list->next;
        }
        cout << endl;
        cout << endl;
    }

    //Todo:
    //  这个写的有问题， 输入 head, 4   output: Bomb 1 1 Deploy 1 2 Advance 1 3 blockade 1 4
    struct Node* OrdersList::findPreTargetNode(struct Node *head,int n){
        int num = 0;
        Node *cur = head;
        while(cur) {
            if(num = n-1 ) return cur;
            cur = cur->next;
            num++;
        }
        cout << "Cannot Find Node at Target Place" << n << " in list.\n";
    };


    //Todo:  思路应该没问题，还没尝试
    void OrdersList::move(struct Node **head, int index,int targetPlace ) {
        Node *cur = *head;
        Node *n1 = searchNode(*head,index);
        Node *preTarget = findPreTargetNode(*head,targetPlace);
        Node *temp;

        if(n1 == *head){
            n1 = n1->next;
            return;
        }
        while(cur){
            if(cur->next=n1){
                temp = n1;
                cur->next = n1->next;
                temp->next = preTarget ->next->next;
                preTarget->next = temp;
            }
            cur = cur->next;
        }
       /* int index=0;
        Node *cur=*head;
        if(n1==*head){
            n1 = n1->next;
            cout << "has excuted" <<endl;
            return;
        }
        while(cur){
            if(cur->next==n1){
                cur->next=cur->next->next;
                break;
            }
            cur=cur->next;
        }

        cur=*head;
        if(targetPlace==0){
            n1->next=*head;
            return;
        }
        while(index==targetPlace-1){

            index++;
            cur=cur->next;
        }
        Node* temp=cur->next;
        cout << "X" << endl;
        cur->next=n1;
        n1->next=temp;*/



    }

