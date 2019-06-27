//
// Created by lenovo on 2019/5/8.
//

#ifndef PROBLEM2_TNODE_H
#define PROBLEM2_TNODE_H


class TNode {
public:
    int value;
    TNode *leftSubT;
    TNode *rightSubT;

    TNode();

    TNode(int x);

    int findBottomLeftValue();


    //以下函数是用来测验函数，通过中序和后序来构建树，再来检验是否正确
    void Construct(int inorder[] , int ileft , int iright , int postorder[] , int pleft , int pright);
    void inOrder();
    void postOrder();

private:
    TNode* ConstructByInorderAndPostoreder(int inorder[] , int ileft , int iright , int postorder[] , int pleft , int pright);
    void inOrderInput(TNode* p);
    void postOrderInput(TNode* p);

};


#endif //PROBLEM2_TNODE_H
