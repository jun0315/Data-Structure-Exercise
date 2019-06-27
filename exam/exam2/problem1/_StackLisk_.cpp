//
// Created by lenovo on 2019/3/29.
//
#include "_StackLisk_.h"

//获取栈的元素多少
int GetSize(Stack S) {
    int num = 0;
    while (!IsEmpty(S)) {
        num++;
        S = S->Next;
    }
    return num;
}

//判断栈中是否为空
int IsEmpty(Stack S) {
    return S->Next == NULL;
}

//创建一个栈
Stack CreateStack(void) {
    Stack S;
    S = (Node *) malloc(sizeof(struct Node));
    if (S == NULL) {
        printf("out of the space!!!");
    }
    S->Next = NULL;
    MakeEmpty(S);
    return S;
}

//释放栈
void DisposeStack(Stack S) {
    if (S != NULL) {
        free(S);
    }
}

//清空栈中元素
void MakeEmpty(Stack S) {
    if (S == NULL) {
        printf("Must use CreateStack first!!");
    } else {
        while (!IsEmpty(S)) {
            Pop(S);
        }
    }
}

//把元素x压入栈中
void Push(int x, Stack S) {
    PtrToNode TmpCell;

    TmpCell = (Node *) (malloc(sizeof(Node)));
    if (TmpCell == NULL) {
        printf("out of space!!!");
    } else {
        TmpCell->element = x;
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}

//返回栈顶元素
int Top(Stack S) {
    if (!IsEmpty(S)) {
        return S->Next->element;
    }
    printf("empty stack");
}

//将栈顶元素推出同时返回栈顶元素值
void Pop(Stack S) {
    PtrToNode FirstCell;

    if (IsEmpty(S)) {
        printf("stack empty");
    } else {
        FirstCell = S->Next;
        S->Next = S->Next->Next;
        free(FirstCell);
    }
}