#include <iostream>
#include "MinStack.h"
#include <cstdio>

/**测试样例为
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); --> Returns -3.
minStack.pop();
minStack.top(); --> Returns 0.
minStack.getMin(); --> Returns -2.
 */

void test() {
    MinStack minStack =  MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    if(minStack.getMin()!=-3){
        printf("test failed1");
        return;
    }
    minStack.pop();
    if(minStack.top()!=0){
        printf("test failed2");
        return;
    }
    if(minStack.getMin()!=-2){
        printf("test failed3");
        return;
    }
    printf("test successfully\n");
}

/**测试样例为
MinStack minStack = new MinStack();
minStack.push(0);
minStack.top(); --> Returns 0.
 */

void test1(){
    MinStack minStack = MinStack();
    minStack.push(0);
    if(minStack.top()!=0){
        printf("test1 failed1");
        return;
    }
    if(minStack.getMin()!=0){
        printf("test1 failed2");
        return;
    }
    printf("test2 successfully");
}

int main() {
    test();//测试函数
    test1();//测试函数
}