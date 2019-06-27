//
// Created by lenovo on 2019/6/12.
//

#include "Solution.h"
Solution::Solution()
{
    Input();
    FrequencySort();
    Output();
}

void Solution::Input() {
    cout<<"input the string:"<<endl;
    cin >> s;
}

bool cmp(pair<char, int> a, pair<char, int> b) {
    if(a.second >= b.second)
    {
        return true;
    }
    return false;
}

void Solution::FrequencySort() {
    //建立一个hash表
    unordered_map<char, int> hash;
    for (int i = 0; i < s.size(); i++) {
        if (hash.count(s[i]) == 0)
            hash[s[i]] = 1;
        else
            hash[s[i]]++;
    }
    //创建对应的结果
    vector<pair<char, int>> count;

    //生成迭代器
    for (unordered_map<char, int>::iterator it = hash.begin(); it != hash.end(); it++)
        count.push_back(pair<char, int>((*it).first, (*it).second));
    //放入vector种
    //进行排序
    sort(count.begin(),count.end(),cmp);
    for(int i = 0 ; i<count.size();i++)
    {
        for(int j = 0 ;j<count[i].second;j++)
            ans += count[i].first;
    }
    //输出结果
}

void Solution::Output()
{
    cout<<"the answer is :"<<endl;
    cout<<ans;
}

