//
// Created by lenovo on 2019/4/10.
//
#include "_StackLisk_.h"
#include "MinStack.h"


//最小栈的构造函数
MinStack::MinStack() {
    NormalStack = CreateStack();
    MinNumStack = CreateStack();
}

//析构函数
MinStack::~MinStack() {
    delete NormalStack;
    delete MinNumStack;
}

//将元素压入栈中，并看是否为最小值决定是否压入另一个栈中
void MinStack::push(int x) {
    if(IsEmpty(MinNumStack) || x< Top(MinNumStack)){
        Push(x,MinNumStack);
    }//寻找是否比MinNumStack栈顶中的元素小，将其压入
    Push(x,NormalStack);
}

//将NormalStack栈顶元素推出，并看该元素是否为最小值同时也推出
void MinStack::pop() {
    if(Top(NormalStack)==Top(MinNumStack)){
        Pop(MinNumStack);
    }//如果恰好在MinNumStack栈顶的话，将其均pop出
    Pop(NormalStack);
}

//返回NormalStack的栈顶元素
int MinStack::top() {
    return Top(NormalStack);
}

//取所有栈中最小的元素
int MinStack::getMin() {
    return Top(MinNumStack);
}