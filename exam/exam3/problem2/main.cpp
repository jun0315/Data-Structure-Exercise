//given a binary tree ,find the leftmost value in the last row of the tree
#include <iostream>
#include "TNode.h"
using namespace std;
void test()
{
    int inorder[3] = {1,2,3};
    int postorder[3] = {1,3,2};
    TNode tNode;
    tNode.Construct(inorder,0,2,postorder,0,2);
    //tNode.inOrder();
    cout<<"result :"<<tNode.findBottomLeftValue()<<endl;
    if(tNode.findBottomLeftValue()==1){
        cout<<"test successfully"<<endl;
    } else cout <<"test failed"<<endl;
}

void test1()
{
    int inorder[7]={4,2,1,7,5,3,6};
    int postorder[7] ={4,2,7,5,6,3,1};
    TNode tNode;
    tNode.Construct(inorder,0,6,postorder,0,6);
    //tNode.inOrder();
    cout<<"result:"<<tNode.findBottomLeftValue()<<endl;
    if(tNode.findBottomLeftValue()==7){
        cout<<"test1 successfully"<<endl;
    } else cout <<"test1 failed"<<endl;
}

int main() {
    test();
    test1();
}