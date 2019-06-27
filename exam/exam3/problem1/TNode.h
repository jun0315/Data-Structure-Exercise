//
// Created by lenovo on 2019/5/8.
//

#ifndef PROBLEM1_TNODE_H
#define PROBLEM1_TNODE_H
#include <iostream>


class TNode {
public:
    int value;
    TNode *leftSubT;
    TNode *rightSubT;

    TNode()
    {
        value = 0;
        leftSubT = NULL;
        rightSubT = NULL;
    };

    TNode(int x)
    {
        value = x;
        leftSubT = NULL;
        rightSubT = NULL;
    }

    //对外提供的接口，类的接口为public类型
    void Construct(int inorder[] , int ileft , int iright , int postorder[] , int pleft , int pright);
    //输出中序结果，用于检验正确与否
    void inOrder();
    //输出后序结果，用于检验正确与否
    void postOrder();

private:
    void inOrderInput(TNode* p);
    void postOrderInput(TNode* p);
    //内部使用的函数，来完成相应的操作
    TNode* ConstructByInorderAndPostoreder(int inorder[] , int ileft , int iright , int postorder[] , int pleft , int pright);

};


#endif //PROBLEM1_TNODE_H
