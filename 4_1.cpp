#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node 
{
public:
    Node();
    void addNbr(int nbr);
    bool isNbr(int nbr);
    vector<int> adj_list;
};

Node::Node() {};

void Node::addNbr(int nbr)
{
    if (!isNbr(nbr))
    {
        adj_list.push_back(nbr);
    }
}

bool Node::isNbr(int nbr)
{
    for (int n : adj_list)
    {
        if (n == nbr)
        {
            return true;
        }
    }
    return false;
}

class Graph
{
public:
    Graph();
    void addNode(Node add);
    bool route(int from, int to);
    vector<Node> nodes;
    int size;
};

Graph::Graph() : size(0) {};

void Graph::addNode(Node add) 
{
    nodes.push_back(add);
    size++;
}

bool Graph::route(int from, int to)
{
    vector<int> visited = vector<int>(size,0);
    visited[from] = from;
    queue<int> q = queue<int>();
    q.push(from);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int n : nodes[curr].adj_list)
        {
            if (n == to)
                return true;
            if (visited[n] == 0)
            {
                visited[n] = curr;
                q.push(n);
            }
        }
    }
    return false;

}

int main(int argc, char* argv[])
{
    Graph g = Graph();
    Node a = Node();
    a.addNbr(1);
    Node b = Node();
    b.addNbr(2);
    Node c = Node();
    c.addNbr(3);
    Node d = Node();

    g.addNode(a);
    g.addNode(b);
    g.addNode(c);
    g.addNode(d);

    int res = g.route(0,3);

    return 0;
}