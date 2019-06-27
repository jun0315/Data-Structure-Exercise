//
// Created by lenovo on 2019/3/27.
//
#include "iostream"
using namespace std;
#ifndef PROBLEM2_LINKEDLIST_H
#define PROBLEM2_LINKEDLIST_H

class Node{
public:
    int data;
    Node* next;
};

class LinkListed {
public:
    LinkListed(){
        head = new Node;
        head->data=0;
        head->next=NULL;
    }
    ~LinkListed(){
        delete(head);
    }

    void CreateLinkList(int n);//创建一个节点数为n的链表

    void DisplayLinkListData();//展示该链表的数据

    bool JudgeNodeNum();
private:
    Node* head;
};

#endif //PROBLEM2_LINKEDLIST_H
