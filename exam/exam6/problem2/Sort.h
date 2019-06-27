//
// Created by lenovo on 2019/6/14.
//

#ifndef SORT_SORT_H
#define SORT_SORT_H
#define MAX_LEN 1000

class Sort {
public:
    Sort();
    //初始化数组
    void Init();
    //快排
    void quickSort(int left,int right);
    //希尔排序
    void ShellSort();
    //堆排序
    void HeapSort();
    //构建最大堆
    void BigHeadjust(int idex,int length);

    void OutputArray();

    int Array[MAX_LEN];
    int len;

private:

};


#endif //SORT_SORT_H
