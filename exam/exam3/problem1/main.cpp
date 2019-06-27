#include <iostream>
#include "TNode.h"
using namespace std;
/// given inorder and postorder traversal of a tree , construct the binary tree.
/// note:you may assume that duplicates do not exist in the tree

void test()
{
    int inorder[5] = {9,3,15,20,7};
    int postorder[5] = {9,15,7,20,3};
    TNode tNode;
    tNode.Construct(inorder,0,4,postorder,0,4);
    cout<<"inorder:";
    tNode.inOrder();
    cout<<endl<<"postorder:";
    tNode.postOrder();
    return;
}

void test1()
{
    cout<<endl;
    int inorder[7]={4,2,1,7,5,3,6};
    int postorder[7] ={4,2,7,5,6,3,1};
    TNode tNode;
    tNode.Construct(inorder,0,6,postorder,0,6);
    cout<<"inorder:";
    tNode.inOrder();
    cout<<endl<<"postorder:";
    tNode.postOrder();
    return;
}

int main() {
    test();
    test1();
}

