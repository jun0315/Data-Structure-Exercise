//
// Created by lenovo on 2019/6/12.
//

#ifndef PROBLEM1_SOLUTION_H
#define PROBLEM1_SOLUTION_H
#include "string"
#include "iostream"
#include <unordered_map>
#include "vector"
#include<algorithm>
using namespace std;

class Solution {
public:
    Solution();
    void Input();
    //序列搜索排序
    void FrequencySort();
    void Output();

protected:

private:
    string s;
    string ans;
};


#endif //PROBLEM1_SOLUTION_H
