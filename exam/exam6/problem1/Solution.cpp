//
// Created by lenovo on 2019/6/14.
//

#include "Solution.h"
using namespace std;
Solution::Solution() {
    Input();
    CheckArgument();
    Output();
}

Solution::~Solution() {
    //dtor
}

//输入两个字符串
void Solution::Input() {
    s.Init();
    t.Init();
}

bool Solution::CheckArgument(){
    //先进行排序
    s.quickSort(0,s.len-1);
    t.ShellSort();
    //逐个比较
    if(s.len != t.len)
        return false;
    for(int i = 0 ; i < s.len ; i++)
    {
        if(s.Array[i] != t.Array[i])
            return false;
    }
    return true;
}

//输出结果
void Solution::Output() {
    if(CheckArgument())
    {
        cout<<"the answer is true\n";
    } else
        cout<<"the answer is flase\n";
}
