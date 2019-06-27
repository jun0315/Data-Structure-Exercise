//
// Created by lenovo on 2019/6/12.
//

#include "Solution.h"
Solution::Solution(){
    Input();
    GetResult();
    Output();
}

void Solution::Input() {
    cout<<"input the array:"<<endl;
    while (1)
    {
        int t ;
        cin>>t;
        array.push_back(t);
        if(cin.get() == '\n')
            break;
    }
}

int Solution::GetResult(){
    BSTree t;
    for(int i = 0 ; i <array.size();i++)
    {
        t.insert(array[i],i);
    }
    for(int i = 0 ;i<array.size();i++)
    {
        ans+=t.findNeedNumber(t.root,array[i],i);
    }
    return t.reverse1(array);
}

void Solution::Output() {
    cout<<"the answer is:"<<endl;
    cout<<GetResult();
}