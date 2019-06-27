//
// Created by lenovo on 2019/6/14.
//
#include "iostream"
#include "Sort.h"
using namespace std;
Sort::Sort() {
    Init();
}

void Sort::Init() {
    cout << "input the length of the array:\n" ;
    cin >> len;
    cout << "in order to enter the char of the array:\n";
    for(int i = 0 ; i<len;i++)
    {
        cin>>Array[i];
    }
}

void Sort::quickSort(int l, int r) {
    if (l >= r)     //先检查左右条件
        return;
    int i = l, j = r, x = Array[l];
    while (i < j) {
        while (i < j && Array[j] >= x)//从右向左找到第一个小于x的
            j--;
        if (i < j)
            Array[i++] = Array[j];//填坑之后i++
        while (i < j && Array[i] <= x)//从左向右找第一个大于x的数
            i++;
        if (i < j)
            Array[j--] = Array[i];
    }
    Array[i] = x;     //把最开始取出来的x放到i处
    quickSort(l, i - 1);//以i为中间值，分左右两部分递归调用
    quickSort(i + 1, r);
}


void Sort::ShellSort() {
    int i , j , gap;
    for(gap = len/2;gap>0;gap/=2)
        for(i = gap ;i<len;i++)
            for(j = i -gap ;j>=0&&Array[j]>Array[j+gap];j-=gap)
                swap(Array[j],Array[j+gap]);

}

void Sort::BigHeadjust(int idex, int length) {
    int lchild = 2 * idex + 1;
    int rchild = 2 * idex + 2;
    int max = idex;
    if(lchild < length &&  Array[lchild] > Array[max])
        max = lchild;
    if(rchild < length && Array[rchild] > Array[max])
        max = rchild;
    if(max != idex)
    {
        swap(Array[max],Array[idex]);
        BigHeadjust(max,length);
    }
}

void Sort::HeapSort() {
    for(int i = len/2-1;i>=0;i--)
    {
        BigHeadjust(i,len);
    }
    for(int i = len-1;i>=0;i--)
    {
        swap(Array[0],Array[i]);
        BigHeadjust(0,i);
    }
}

void Sort::OutputArray() {
    for (int i = 0; i < len; i++) {
        cout << Array[i] << " ";
    }
    cout << endl;
}