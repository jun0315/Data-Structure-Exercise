//
// Created by lenovo on 2019/5/8.
//

#include "TNode.h"

using namespace std;

//传入中序后序数组 重建
void TNode::Construct(int inorder[], int ileft, int iright, int postorder[], int pleft,
                      int pright) {
    value = postorder[pright];
    //TNode *cur = new TNode(postorder[pright]);
    int i = 0;
    for (i = ileft; i <= iright; i++) {
        if (inorder[i] == value) break;
    }
    //由于最后一个是根节点，左右一分为二。
    leftSubT = ConstructByInorderAndPostoreder(inorder, ileft, i - 1, postorder, pleft, pleft + i - ileft - 1);
    rightSubT = ConstructByInorderAndPostoreder(inorder, i + 1, iright, postorder, pleft + i - ileft, pright - 1);

}

TNode *TNode::ConstructByInorderAndPostoreder(int inorder[], int ileft, int iright, int postorder[], int pleft,
                                              int pright) {

    if (ileft > iright || pleft > pright) return nullptr;
    TNode *cur = new TNode(postorder[pright]);
    int i = 0;
    for (i = ileft; i <= iright; i++) {
        if (inorder[i] == cur->value) break;
    }
    cur->leftSubT = ConstructByInorderAndPostoreder(inorder, ileft, i - 1, postorder, pleft, pleft + i - ileft - 1);
    cur->rightSubT = ConstructByInorderAndPostoreder(inorder, i + 1, iright, postorder, pleft + i - ileft, pright - 1);
    return cur;

}

//中序输出用来检验
void TNode::inOrder() {
    inOrderInput(leftSubT);
    cout << value << ",";
    inOrderInput(rightSubT);
}

void TNode::inOrderInput(TNode *p) {
    if (p != NULL) {
        inOrderInput(p->leftSubT);
        cout << p->value << ",";
        inOrderInput(p->rightSubT);
    }
}
//后序输出同样用来检验
void TNode::postOrder() {
    inOrderInput(leftSubT);
    inOrderInput(rightSubT);
    cout<<value<<",";
}

void TNode::postOrderInput(TNode *p) {
    if(p!=NULL)
    {
        inOrderInput(p->leftSubT);
        inOrderInput(p->rightSubT);
        cout<<p->value<<",";
    }

}