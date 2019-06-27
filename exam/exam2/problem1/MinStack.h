//
// Created by lenovo on 2019/4/10.
//
#ifndef PROBLEM1_MINSTACK_H
#define PROBLEM1_MINSTACK_H

#include "_StackLisk_.h"
using namespace std;


class MinStack {
private:
    Stack NormalStack;
    Stack MinNumStack;

public:
    MinStack();
    ~MinStack();
    void push(int x);

    void pop();

    int top();

    int getMin();


};
#endif //PROBLEM1_MINSTACK_H
