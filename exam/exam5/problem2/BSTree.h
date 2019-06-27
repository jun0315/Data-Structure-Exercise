//
// Created by lenovo on 2019/4/16.
//

#ifndef BSTREE_BSTREE_H
#define BSTREE_BSTREE_H

#include "iostream"
#include <vector>

using namespace std;

struct BSNode {
    BSNode *lchild;
    BSNode *rchild;
    BSNode *parent;
    int value;
    int seq;

    BSNode(int t, int s) {
        value = t;
        seq = s;
        lchild = nullptr;
        rchild = nullptr;
    };

    BSNode() = default;
};

class BSTree {
public:
    BSTree();

    ~BSTree();

    void preOrder();//前序遍历二叉树
    void inOrder();//中序遍历二叉树
    void postOrder();//后序遍历 二叉树
    void layerOrder();//层次遍历二叉树

    BSNode *successor(BSNode *x);//查找指定结点的后继结点
    BSNode *predecessor(BSNode *x);//查找指定节点的前驱节点

    BSNode *search_recursion(int key);//递归进行查找
    BSNode *search_Iterator(int key);//迭代进行查找


    int search_minimun();//查找最小元素
    int search_maxinum();//查找最大元素
    int reverse1(vector<int> &nums);

    void insert(int key, int seq);//插入指定值节点,建立一个平衡二叉树
    void remove(int key);//删除指定值节点
    void destory();//销毁二叉树
    void print();//打印二叉树
    int findNeedNumber(BSNode *node, int key, int seq);

    BSNode *root;//根节点
private:
    BSNode *search(BSNode *&p, int key);

    void remove(BSNode *p, int key);

    void preOrder(BSNode *p);

    void inOrder(BSNode *p);

    void postOrder(BSNode *p);

    int search_mininum(BSNode *p);

    int search_maxinum(BSNode *p);

    void destroy(BSNode *&p);


};//操作的外部接口与内部实现接口，private中函数为类内部递归操作所使用的接口

#endif //BSTREE_BSTREE_H
