// Created by lenovo on 2019/3/27.
//code in GBK
/**part 2 question 4
������������ L �������� a�������� L ��ÿ a �����ߵ���������������
������
���룺5->3->1->2->4��3
�����1->3->5->2->4
*/
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

};

/*****************************************************
* �������ã��������Ϊn������
* ʵ�ַ���������Ĵ�������
* �������������1�����������
* �����������
* ����ֵ  ������ͷ���ĵ�ַ
* ������ڣ�2019.03.27
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
}//����n����������

/*****************************************************
* �������ã�չʾ���������е�����
* ʵ�ַ����������չʾ����
* �������������1�������ͷ����ַ
* ������������������νڵ����ֵ
* ����ֵ  ����
* ������ڣ�2019.03.27
******************************************************/
void DisplayData(ListNode *p) {
    ListNode *tmp = p;
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}//չʾ����

/*****************************************************
* �������ã��ж��������Ƿ��г���k���ڵ�
* �������������1�������ͷ����ַ ������2���ж�ֵk
* �����������
* ����ֵ  ��flase����true
* ������ڣ�2019.03.27
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
* �������ã���ת��������k���ڵ�Ϊ���ޣ����з�ת�������k�������з�ת
* �������������1�������ͷ����ַ ������2���ж�ֵk
* �����������
* ����ֵ  ����ת��ɺ������ͷ���ĵ�ַ
* ������ڣ�2019.03.27
******************************************************/
ListNode *reverseAGroup(ListNode *head, int k) {
    ListNode *prev = NULL, *next = NULL, *cur = head;
    ListNode *ret = head;
    ListNode *pre_end = NULL, *cur_end = NULL;
    int count = k;
    if (cur == NULL || k == 1) {
        return cur;
    }//���������ֱ�ӷ���
    while (JudgeNodeNum(cur, k)) {
        count = k;
        pre_end = cur_end;
        cur_end = cur;
        while (count--) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }//k�����з�ת����
        if(ret == head){
            ret = prev;
        }//���տ�ʼ��һ���������retת��
        if(pre_end != NULL){
            pre_end->next = prev;
        }//����������н��ϡ�
        prev = NULL ;
    }
    if(cur_end!=NULL){
        cur_end->next = cur;
    }//�������ʣ�಻��k���������ֱ������
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