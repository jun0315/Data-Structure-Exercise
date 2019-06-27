//
// Created by lenovo on 2019/6/14.
//

#include "Solution.h"
#include <iostream>
using namespace std;

Solution::Solution() {
    Init();
    Insert();
    Output();
}

Solution::~Solution() {
    //dtor
}

void Solution::Init() {
    cout<<"Please input the intervals:"<<endl;
    while (1)
    {
        Interval interval;
        //将所有区间加入容器中
        cin>>interval.left>>interval.right;
        intervals.push_back(interval);
        if(cin.get()=='\n')
        {
            break;
        }
    }
    cout << "Please input the new interval"<<endl;
    cin >> newInterval.left>>newInterval.right;
}

void Solution::Sort() {
    intervals.pop_back();
    //刚开始寻找
    auto it = intervals.begin();
    while (it!=intervals.end() && newInterval.left>it->left)
    {
        it++;
    }
    //找到第一个区间的左边比新区间大的，将其插入
    intervals.insert(it,newInterval);
    //只读
    for(const auto& interval : intervals)
    {
        //如果为空或者新区间的左边比之前的右边大，放入ans中
        if(ans.empty() || interval.left > ans.back().right)
        {
            ans.push_back(interval);
        } else
        {
            //否则寻找最适合的右边的值
            ans.back().right = max(ans.back().right,interval.right);
        }
    }
}

void Solution::Insert() {
    intervals.push_back(newInterval);
    Sort();
}

//输出结果
void Solution::Output() {
    for(int i = 0 ; i< ans.size();i++)
    {
        cout << "[" << ans[i].left << "," << ans[i].right << "] ";
    }

    cout<<endl<<endl;
}
