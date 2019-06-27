//
// Created by lenovo on 2019/4/3.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H
#include <iostream>
#include "TNode.h"
using namespace std;

struct QueueNode {
    TNode* data;
    QueueNode *next = nullptr;

    QueueNode(TNode* x) {
        data = x;
    }
};

class Queue {
private:
    QueueNode *front;
    QueueNode *rear;
    int size;

public:
    Queue();

    bool isEmpty();

    void EnQueue(TNode* x);

    int Size();

    void DeQueue();

    TNode* GetHead();

    void Clear();
};


#endif //QUEUE_QUEUE_H
