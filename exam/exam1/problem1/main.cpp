// Created by lenovo on 2019/3/27.
//code in GBK
/**part 1 question 4
输入一个整数数组 L 和两个整数 a、b，求元素值大于 a 小于 b 的所有子数组
        和数量。如
        输入：L = [-2,2,5,8,6]，a = 1，b = 6
输出：[2,5]，1
*/

#include <iostream>

/***********************************************************************************************************
* 函数作用：找到数组中所有满足条件的子数组
* 输入参数：参数1：待查数组的地址 ；参数2：用于记录每个子数组的开始下表，参数3：用于记录每个子数组的结束下标
*         参数4：待查数组的长度 ；参数5：条件中华需要大于的数 ； 参数6：条件中需要小于的数
* 实现方法：通过对数组进行一遍扫描，分别记录开始和结束的子数组的下标，引入状态变量joining进行判断是否当前正在有数组满足条件
* 输出参数：无
* 返回值  ：满足条件的子数组的个数
* 完成日期：2019.03.27
***********************************************************************************************************/
int FindArray(int *L, int *start, int *end, int n, int a, int b) {
    bool joining = false; //是否在当前情况下找到数组状态
    int j = 0;
    for (int i = 0; i < n; i++) {
        //未进入状态时
        if (!joining) {
            if (L[i] > a && L[i] < b) {
                joining = true;
                j++;
                start[j] = i;
            }//若满足条件，则进入状态，且记录开始下标
        } else {
            if (L[i] <= a || L[i] >= b) {
                joining = false;
                end[j] = i - 1;
            }//若在状态时，但出现不满足情况时，则退出状态，且记录上一个下标
            if (i == n - 1) {
                if (joining) {
                    end[j] = i;
                }
            }//特殊情况下，到最后一个数组时，仍然满足条件，则保存并结束
        }
    }
    return j;
}

//用于测试样例
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

    int start[1000];//用于保存每个子数组开始的下标
    int end[1000];//用于保存每个子数组结束的下标

    int j = FindArray(L, start, end, n, a, b);

    printf("have %d arrays of meet the conditions\n", j);

    for (int i = 1; i <= j; i++) {
        for (int k = start[i]; k <= end[i]; k++) {
            printf("%d ", L[k]);
        }
        printf("\n");
    }
}