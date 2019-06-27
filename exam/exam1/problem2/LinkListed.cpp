//
//

#include "LinkListed.h"

void LinkListed::CreateLinkList(int n) {
    if(n <= 0){
        cout<< "error" <<endl;
    }
    else {
        Node* tmp = head;
        int x ;
        while (n){
            Node* pnode = new Node;
            scanf("%d",&x);
            pnode->data = x;
            pnode->next = NULL;
            tmp->next = pnode;
            tmp = tmp->next;
            n--;
        }
    }
}

void LinkListed::DisplayLinkListData() {
    Node* tmp;
    tmp = head->next;
    while (tmp!=NULL){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
}