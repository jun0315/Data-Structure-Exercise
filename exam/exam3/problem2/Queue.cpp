//
// Created by lenovo on 2019/4/3.
//

#include "Queue.h"

Queue::Queue() {
    front = nullptr;
    rear = nullptr;
    size = 0;
}

bool Queue::isEmpty() {
    if (front == nullptr && rear == nullptr) {
        return true;
    } else return false;
}

int Queue::Size() {
    return size;
}

void Queue::EnQueue(TNode *x) {
    QueueNode *newNode = new QueueNode(x);
    newNode->next = nullptr;
    if (rear == nullptr) {
        front = newNode;
        rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
    size++;

}

void Queue::DeQueue() {

    QueueNode *oldNode = front;
    TNode *element = oldNode->data;
    front = front->next;
    delete oldNode;
    size--;
}

TNode *Queue::GetHead() {

    return front->data;
}

void Queue::Clear() {
    while (!isEmpty()) {
        DeQueue();
    }
}