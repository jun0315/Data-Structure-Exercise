// Created by lenovo on 2019/3/27.
//code in GBK
/**part 1 question 4
����һ���������� L ���������� a��b����Ԫ��ֵ���� a С�� b ������������
        ����������
        ���룺L = [-2,2,5,8,6]��a = 1��b = 6
�����[2,5]��1
*/

#include <iostream>

/***********************************************************************************************************
* �������ã��ҵ���������������������������
* �������������1����������ĵ�ַ ������2�����ڼ�¼ÿ��������Ŀ�ʼ�±�����3�����ڼ�¼ÿ��������Ľ����±�
*         ����4����������ĳ��� ������5�������л���Ҫ���ڵ��� �� ����6����������ҪС�ڵ���
* ʵ�ַ�����ͨ�����������һ��ɨ�裬�ֱ��¼��ʼ�ͽ�������������±꣬����״̬����joining�����ж��Ƿ�ǰ������������������
* �����������
* ����ֵ  ������������������ĸ���
* ������ڣ�2019.03.27
***********************************************************************************************************/
int FindArray(int *L, int *start, int *end, int n, int a, int b) {
    bool joining = false; //�Ƿ��ڵ�ǰ������ҵ�����״̬
    int j = 0;
    for (int i = 0; i < n; i++) {
        //δ����״̬ʱ
        if (!joining) {
            if (L[i] > a && L[i] < b) {
                joining = true;
                j++;
                start[j] = i;
            }//�����������������״̬���Ҽ�¼��ʼ�±�
        } else {
            if (L[i] <= a || L[i] >= b) {
                joining = false;
                end[j] = i - 1;
            }//����״̬ʱ�������ֲ��������ʱ�����˳�״̬���Ҽ�¼��һ���±�
            if (i == n - 1) {
                if (joining) {
                    end[j] = i;
                }
            }//��������£������һ������ʱ����Ȼ�����������򱣴沢����
        }
    }
    return j;
}

//���ڲ�������
void test() {
    int L[] ={-2,2,5,8,6};
    int start[5];
    int end[5];
    int n = 5;
    int a = 1 , b = 6;
    int j = FindArray(L, start, end, n, a, b);
    if(L[start[1]]==2&&L[end[1]]==5&&j==1){
        printf("test successfully!!\n");
    } else{
        printf("test failed!!!\n");
    }
}

int main() {
    int L[1000];

    test();

    printf("input the length of the array\n");
    int n;
    scanf("%d", &n);

    printf("Enter the values of all arrays in turn\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &L[i]);
    }

    int a, b;
    printf("input a and b\n");
    scanf("%d %d", &a, &b);

    int start[1000];//���ڱ���ÿ�������鿪ʼ���±�
    int end[1000];//���ڱ���ÿ��������������±�

    int j = FindArray(L, start, end, n, a, b);

    printf("have %d arrays of meet the conditions\n", j);

    for (int i = 1; i <= j; i++) {
        for (int k = start[i]; k <= end[i]; k++) {
            printf("%d ", L[k]);
        }
        printf("\n");
    }
}