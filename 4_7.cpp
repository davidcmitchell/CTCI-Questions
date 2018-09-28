#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*from is row, to is col. to is dep on from*/

class Graph 
{
public:
    Graph(int num);
    void addEdge(int from, int to);
    void removeEdge(int from, int to);
    void removeAllEdges(int node);
    bool isDependent(int node);
    void print();
    vector<int> build();
    int num_nodes;
    vector< vector<int> > adj_mat;
    vector<bool> built;
};

Graph::Graph(int num) : num_nodes(num), 
                        adj_mat(vector<vector <int> >(num,vector<int> (num,0))) ,
                        built(vector<bool>(num,false))
{
}

void Graph::addEdge (int from, int to)
{
    adj_mat[from][to] = 1;
}

void Graph::removeEdge (int from, int to)
{
    adj_mat[from][to] = 0;
}

void Graph::removeAllEdges (int node)
{
    for (int i = 0; i < num_nodes; i++)
    {
        removeEdge(node,i);
    }
}

bool Graph::isDependent (int node)
{
    for (int i = 0; i < num_nodes; i++)
    {
        if (adj_mat[i][node] != 0)
            return true;
    }
    return false;
}

void Graph::print()
{
    for (int i = 0; i < num_nodes; i++)
    {
        for (int j = 0; j < num_nodes; j++)
        {
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }
}

vector<int> Graph::build()
{
    vector<int> build_order;
    queue<int> q;
    for (int i = 0; i < num_nodes; i++)
    {
        if (!isDependent(i))
        {
            q.push(i);
            built[i] = true;
        }
    }
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        removeAllEdges(curr);
        build_order.push_back(curr);
        for (int i = 0; i < num_nodes; i++)
        {
            if (!built[i] && !isDependent(i))
            {
                q.push(i);
                built[i] = true;
            }
        }
    }
    return build_order;
}

int main(int argc, char* argv[])
{
    Graph g = Graph(6);
    g.addEdge(0,3);
    g.addEdge(5,1);
    g.addEdge(1,3);
    g.addEdge(5,0);
    g.addEdge(3,2);
    g.print();
    vector<int> build_order = g.build();
    for (int i = 0; i < build_order.size(); i++)
    {
        cout << build_order[i] << " ";
    }
    cout << endl;

    return 0;

}