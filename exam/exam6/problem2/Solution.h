//
// Created by lenovo on 2019/6/14.
//

#ifndef PROBLEM2_SOLUTION_H
#define PROBLEM2_SOLUTION_H
#include "vector"
#include "Interval.h"
using namespace std;
class Solution {
public:
    Solution();
    virtual ~Solution();

protected:
private:
    //初始化
    void Init();
    //将新的区间插入vector中
    void Insert();
    //排序
    void  Sort();
    //输出结果
    void Output();

    Interval newInterval;
    vector<Interval> intervals;
    vector<Interval> ans;
};


#endif //PROBLEM2_SOLUTION_H
