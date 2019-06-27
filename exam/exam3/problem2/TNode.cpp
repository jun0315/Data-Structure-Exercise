//
// Created by lenovo on 2019/5/8.
//

#include "TNode.h"
#include "queue"
#include <iostream>
using namespace std;
TNode::TNode()
{
    value = 0;
    leftSubT = NULL;
    rightSubT = NULL;
};
TNode::TNode(int x)
{
    value = x;
    leftSubT = NULL;
    rightSubT = NULL;
}

//寻找结果
int TNode::findBottomLeftValue() {
    int result = value;
    queue<TNode*> q;
    TNode *tem;
    q.push(this);
    //每次更新最大深度为当前深度
    while (!q.empty()) {
        int size = q.size();
        //先保存结果
        result = q.front()->value;
        while (size--) {
            tem = q.front();
            q.pop();
            //如果有节点，将其入队
            if (tem->leftSubT != NULL) q.push(tem->leftSubT);
            if (tem->rightSubT != NULL) q.push(tem->rightSubT);
        }
    }//保存每层第一次出现的数值
    return result;

}

//传入中序后序数组 重建
void TNode::Construct(int inorder[], int ileft, int iright, int postorder[], int pleft,
                      int pright) {
    value = postorder[pright];
    //TNode *cur = new TNode(postorder[pright]);
    int i = 0;
    for (i = ileft; i <= iright; i++) {
        if (inorder[i] == value) break;
    }
    leftSubT = ConstructByInorderAndPostoreder(inorder, ileft, i - 1, postorder, pleft, pleft + i - ileft - 1);
    rightSubT = ConstructByInorderAndPostoreder(inorder, i + 1, iright, postorder, pleft + i - ileft, pright - 1);

}

//传入中序后序数组
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

//用来输出中序结果，便于自测函数
void TNode::inOrder() {
    inOrderInput(leftSubT);
    cout<<value<<endl;
    inOrderInput(rightSubT);
}

void TNode::inOrderInput(TNode *p) {
    if(p!=NULL)
    {
        inOrderInput(p->leftSubT);
        cout<<p->value<<endl;
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
