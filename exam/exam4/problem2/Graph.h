#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class GraphNode
{
public:
    std::string id;

    std::vector<GraphNode*> neighborNodes;

    GraphNode(std::string label)
    {
        id = label;
    }

};

class Graph
{
    public:
        Graph();
        virtual ~Graph();

        std::vector<std::pair<std::pair<std::string,std::string>,int> >edges;

        int edgeSum;
        int nodeSum;

        //寻找形成安排
        void find_the_Itinerary();
        //深度优先搜索
        void Dfs(string start,vector<string>&result,map<string,multiset<string>>&myMap );

    protected:

    private:
        std::vector<std::pair<std::string, std::string> > tickets;
};

#endif // GRAPH_H
