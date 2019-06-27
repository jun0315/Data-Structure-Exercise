#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

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

    void num_of_buses_get();
    int edgeSum;
    int nodeSum;
    //CreateGraph();


protected:

private:
    std::vector<std::vector<int> >routs;
    int S;
    int T;

};

#endif // GRAPH_H
