//
// Created by lenovo on 2019/4/10.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

struct StackNode{
    int element;
    StackNode* next = nullptr;

    StackNode(int x){
        element = x;
    }
};

class Stack {
private:
    StackNode * stackNode;
public:

    Stack();

    ~Stack();

    bool IsEmpty();

    void Push(int x);

    int Pop();

    int Top();

    void Claer();
};


#endif //STACK_STACK_H
