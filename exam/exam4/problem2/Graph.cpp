#include "Graph.h"
#include <iostream>

using namespace std;

Graph::Graph()
{
    //ctor
    while(1)
    {
        string place1, place2;
        cin >> place1 >> place2;

        pair<string,string> oneWay(place1,place2);
        tickets.push_back(oneWay);

        if(cin.get() == '\n')
        {
            break;
        }
    }
    find_the_Itinerary();
}


void Graph::Dfs(string start, vector<string> &result, map<string, multiset<string>> &myMap) {
    //直到为空时，返回上一个
    while(!myMap[start].empty())
    {
        string next=*myMap[start].begin();
        myMap[start].erase(myMap[start].begin());
        Dfs(next,result,myMap);
    }
    //当一个深度搜索完成后，将其push入vector中
    result.push_back(start);
}

void Graph::find_the_Itinerary()
{
    vector<string> ans;
    //multiset默认排序，同时允许元素重复
    map<string, multiset<string> > graph;

    if (tickets.empty())
    {
        cout << "Error!!!" <<endl;
    }

    string from = "JFK";
    for (pair<string,string> i : tickets)
    {
        graph[i.first].insert(i.second);
    }
    Dfs(from,ans,graph);

    reverse(ans.begin(),ans.end());

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans.at(i)<<" ";
    }
    cout<<endl;
}

Graph::~Graph()
{
    //dtor
}
