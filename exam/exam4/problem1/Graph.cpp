//
// Created by lenovo on 2019/5/22.
//

#include "Graph.h"
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_map>

using namespace std;

Graph::Graph()
{
    cout<<"Please input the number of buses:"<<endl;
    int nums_of_buses;
    cin>>nums_of_buses;

    for(int i=0; i<nums_of_buses; i++)
    {
        vector<int> newbus;
        cout << "Please input the routs of the "<<i+1<<"th bus:"<<endl;
        while(1)
        {
            int rout;
            cin >> rout;
            newbus.push_back(rout);
            if(cin.get() == '\n')
            {
                break;
            }
        }
        routs.push_back(newbus);
    }

    cout <<"Please input S and T:" << endl;
    cin >> S >> T;

    num_of_buses_get();

}

Graph::~Graph()
{
    //dtor
}


void Graph::num_of_buses_get()
{
    //初始两个相等
    if(S == T)
    {
        cout <<"0" << endl<<endl;
    }
    //构建一个内部无序的map
    unordered_map<int, vector<int> >m;
    //记录站点有哪几个路线经过
    for(int i=0;i<routs.size();i++)
    {
        for(int stop : routs[i])
        {
            m[stop].push_back(i);
        }
    }
    //经过的公交
    vector<int> visited(routs.size(), 0);
    queue<int> q;
    //把起始点压入
    q.push(S);
    int buses = 0;

    while (!q.empty())
    {
        int size_=q.size();
        buses++;
        while(size_--)
        {
            //当前的站点
            int curr=q.front();
            q.pop();
            //寻找经过当前站点的所有公交车
            for(int bus:m[curr])
            {
                //如果公交车已经坐过，则跳过
                if(visited[bus])continue;

                visited[bus]=1;
                //对所有的站进行寻找，如果等于T
                for(int stop:routs[bus])
                {
                    if(stop==T)
                    {
                        cout << "ans:" << buses<<endl<<endl;
                        return;
                    }
                    q.push(stop);
                }
            }
        }
    }
    //未找到为-1
    cout<<"-1"<<endl<<endl;

}

