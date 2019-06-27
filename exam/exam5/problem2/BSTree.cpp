//
// Created by lenovo on 2019/4/16.
//

#include "BsTree.h"
#include <iostream>
#include "vector"
#include "BSTree.h"

using namespace std;

BSTree::BSTree() {
    root = nullptr;
}

BSTree::~BSTree() {
    delete root;
}

void BSTree::insert(int key,int seq) {
    BSNode *pparent = nullptr;
    BSNode *pnode = root;

    while (pnode != nullptr) {
        pparent = pnode;
        if (key > pnode->value) {
            pnode = pnode->rchild;
        } else if (key < pnode->value) {
            pnode = pnode->lchild;
        } else
            break;
    }

    pnode = new BSNode(key,seq);

    if (pparent == nullptr) {
        root = pnode;
    } else {
        if (key > pparent->value) {
            pparent->rchild = pnode;
        } else {
            pparent->lchild = pnode;
        }
    }
    pnode->parent = pparent;
}

void BSTree::preOrder() {
    preOrder(root);
}

void BSTree::preOrder(BSNode *p) {
    if(p!= nullptr)
    {
        cout << p->value <<endl;
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

void BSTree::inOrder() {
    inOrder(root);
}

void BSTree::inOrder(BSNode *p) {
    if(p!= nullptr)
    {
        inOrder(p->lchild);
        cout<<p->value<<p->seq<<endl;
        inOrder(p->rchild);
    }
}

void BSTree::postOrder()  {
    inOrder(root);
}

void BSTree::postOrder(BSNode *p) {
    if(p!= nullptr)
    {
        postOrder(p->lchild);
        postOrder(p->rchild);
        cout<<p->value<<endl;
    }
}

/*思路如下
 * 寻找前驱节点
 * 1.若有左子树，前驱为左子树中的最后一个找到的节点
 * 2.若无左子树，且自身为右子树，前驱为父节点
 * 3.若无左子树，且自身为左子树，前驱为往上寻找自身这类子树在右侧的情况的父节点
 */
BSNode* BSTree::predecessor(BSNode *pnode) {
    if(pnode->lchild!=nullptr)
    {
        pnode = pnode->lchild;
        while (pnode->rchild!= nullptr)
        {
            pnode = pnode->rchild;
        }
        return  pnode;
    }

    BSNode* pparent = pnode->parent;
    while (pparent!= nullptr && pparent->lchild == pnode)//进入循环，是第三种情况，否则为第二种情况
    {
        pnode = pparent;
        pparent = pparent->parent;
    }
    return pparent;//***
}

/*思路如下
 * 寻找后继节点
 * 1.若有右子树，后继为右子树中的第一个找到的节点
 * 2.若无右子树，且自身为左子树，后继为父节点
 * 3.若无右子树，且自身为右子树，后继为往上寻找自身这类子树在左侧的情况的父节点
 */
BSNode* BSTree::successor(BSNode *pnode) {
    if(pnode->rchild!=nullptr)
    {
        pnode = pnode->rchild;
        while (pnode->lchild!= nullptr)
        {
            pnode = pnode->rchild;
        }
        return  pnode;
    }

    BSNode* pparent = pnode->parent;
    while (pparent!=nullptr && pparent->rchild == pnode)
    {
        pnode = pparent;
        pparent = pparent->parent;
    }
    return  pparent;
}

void BSTree::remove(int key) {
    remove(root,key);
}

void BSTree::remove(BSNode *pnode, int key) {
    if(pnode!=nullptr)
    {
        if(pnode->value == key)
        {
            BSNode * pdel = nullptr;
            //被删节点只有左子树或右子树或者没有子树
            if(pnode->lchild == nullptr || pnode->rchild == nullptr)
                pdel = pnode;
            else
                pdel = predecessor(pnode);

            BSNode * pchild = nullptr;
            if(pdel->lchild!= nullptr)
                pchild = pdel->lchild;
            else
                pchild = pdel->rchild;

            //让孩子指向被删除节点的父节点
            if(pchild!= nullptr)
                pchild->parent = pdel->parent;

            //如果删除的节点是头节点
            if(pdel->parent == nullptr)
                root = pchild;

            if(pdel->parent->lchild == pdel)
                pdel->parent->lchild = pchild;
            else
                pdel->parent->rchild = pchild;

            if(pnode->value != pdel->value)
                pnode->value = pdel->value;
            delete pdel;
        }
        else if(key>pnode->value)
            remove(pnode->rchild,key);
        else
            remove(pnode->lchild,key);
    }
}

/*查找指定元素的节点（非递归）*/
BSNode* BSTree::search_Iterator(int key)
{
    BSNode* pnode = root;
    while (pnode!=nullptr)
    {
        if(key == pnode->value)
        {
            return pnode;
        }
        if(key > pnode->value)  //在右节点查找
        {
            pnode = pnode->rchild;
        } else {                //在左节点查找
            pnode = pnode->lchild;
        }
    }
    return nullptr;
}

/*查找指定元素的节点（递归）*/
BSNode* BSTree::search_recursion(int key)
{
    return search(root,key);
}

/*private:search()*/
/*递归查找的类内部实现*/
BSNode* BSTree::search(BSNode *&pnode, int key) {
    if(pnode == nullptr)
        return nullptr;
    if(pnode->value==key){
        return pnode;
    }
    if(key>pnode->value)
        return search(pnode->rchild,key);
    return search(pnode->lchild,key);
}

int BSTree::findNeedNumber(BSNode* node,int key,int seq) {
    int cnt = 0;
    if(node!= nullptr)
    {
        if((node->value)*2<key&&node->seq>seq)
            cnt++;
        cnt += findNeedNumber(node->lchild,key,seq) + findNeedNumber(node->rchild,key,seq);
    }
    return cnt;
}

int BSTree::reverse1(vector<int> &nums) {
    long cnt = 0;
    vector<long> trans;
    if (nums.size() == 0)
        return cnt;
    trans.push_back((long)2 * nums[nums.size() - 1]);
    for (int i = nums.size() - 2; i >= 0; i--) {
        auto it = lower_bound(trans.begin(), trans.end(), nums[i]);
        cnt += it - trans.begin();
        it = lower_bound(trans.begin(), trans.end(), (long)2 * nums[i]);
        trans.insert(it, (long)2 * nums[i]);
    }
    return cnt;
}

