//
// Created by lenovo on 2019/4/10.
//

#include <iostream>
#include "Stack.h"

using namespace std;

//完成栈的初始化
Stack::Stack() {
    stackNode = nullptr;
}

//栈的析构函数
Stack::~Stack() {
    delete stackNode;
}

//判断栈是否为空
bool Stack::IsEmpty() {
    if (stackNode == nullptr){
        return true;
    } else return false;
}

//把x压入栈中
void Stack::Push(int x) {
    StackNode* newNode = new StackNode(x);
    newNode->next = stackNode;
    stackNode = newNode;
}

//将栈顶Pop出，同时取出栈顶的element
int Stack::Pop() {
    if(IsEmpty()){
        cout << "Stack is empty" << endl;
        return -1;
    }
    int element = stackNode->element;
    StackNode* oldPtr = stackNode;
    stackNode = stackNode->next;
    delete oldPtr;
    return element;
}

//返回栈顶的元素值
int Stack::Top() {
    if(IsEmpty()){
        cout << "Stack is empty" << endl;
        return -1;
    }
    return stackNode->element;
}

//清空栈中元素
void Stack::Claer() {
    while (!IsEmpty()){
        Pop();
    }
}
