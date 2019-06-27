// Created by lenovo on 2019/3/27.
//code in GBK
/**part 2 question 4
输入整数链表 L 和正整数 a，对链表 L 按每 a 个结点颠倒，并输出操作后的
链表。如
输入：5->3->1->2->4，3
输出：1->3->5->2->4
*/
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

};

/*****************************************************
* 函数作用：创建结点为n的链表
* 实现方法：链表的创建方法
* 输入参数：参数1：输入结点个数
* 输出参数：无
* 返回值  ：链表头结点的地址
* 完成日期：2019.03.27
******************************************************/
ListNode *CreateLinklist(int n) {
    ListNode *p = new ListNode;
    p->val = 0;
    p->next = NULL;
    ListNode *p1 = p;
    printf("Enter the values of all arrays in turn\n");
    while (n--) {
        ListNode *tmp = new ListNode;
        scanf("%d", &tmp->val);
        tmp->next = NULL;
        p1->next = tmp;
        p1 = p1->next;
    }
    return p;
}//创建n个结点的链表

/*****************************************************
* 函数作用：展示链表中所有的数据
* 实现方法：链表的展示方法
* 输入参数：参数1：链表的头结点地址
* 输出参数：链表中依次节点的数值
* 返回值  ：无
* 完成日期：2019.03.27
******************************************************/
void DisplayData(ListNode *p) {
    ListNode *tmp = p;
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}//展示数据

/*****************************************************
* 函数作用：判断链表中是否还有超过k个节点
* 输入参数：参数1：链表的头结点地址 ；参数2：判断值k
* 输出参数：无
* 返回值  ：flase或者true
* 完成日期：2019.03.27
******************************************************/
bool JudgeNodeNum(ListNode *cur, int k) {
    while (k) {
        if (cur == NULL) {
            return false;
        }
        cur = cur->next;
        k--;
    }
    return true;
}

/*****************************************************
* 函数作用：翻转链表中以k个节点为界限，进行翻转，最后不足k个不进行翻转
* 输入参数：参数1：链表的头结点地址 ；参数2：判断值k
* 输出参数：无
* 返回值  ：翻转完成后的链表头结点的地址
* 完成日期：2019.03.27
******************************************************/
ListNode *reverseAGroup(ListNode *head, int k) {
    ListNode *prev = NULL, *next = NULL, *cur = head;
    ListNode *ret = head;
    ListNode *pre_end = NULL, *cur_end = NULL;
    int count = k;
    if (cur == NULL || k == 1) {
        return cur;
    }//特殊情况，直接返回
    while (JudgeNodeNum(cur, k)) {
        count = k;
        pre_end = cur_end;
        cur_end = cur;
        while (count--) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }//k个进行翻转链表
        if(ret == head){
            ret = prev;
        }//若刚开始第一次情况，则ret转换
        if(pre_end != NULL){
            pre_end->next = prev;
        }//连续两组进行接上。
        prev = NULL ;
    }
    if(cur_end!=NULL){
        cur_end->next = cur;
    }//最后若还剩余不足k个，则进行直接连上
    return  ret;
}

int main() {
    printf("input the length of array\n");
    int n;
    scanf("%d", &n);
    ListNode *p = CreateLinklist(n);
    printf("input number of the need to reverseAGroup\n");
    int k;
    scanf("%d", &k);
    DisplayData(reverseAGroup(p->next, k));
}