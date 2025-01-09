// SEARCH IN GRAPH:->
// has two algorithm
// 1. BFS-->Breadth First Search
// 2. DFS-->Depth First Search
// LS-67
#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Graph
{

    unordered_map<T, list<T>> h;

public:
    void addedge(T x, T y, bool bidirectional = true)
    {
        h[x].push_back(y);
        if (bidirectional)
        {
            h[y].push_back(x);
        }
    }

    void printgraph()
    {
        for (auto p : h)
        {
            cout << p.first << "-->";
            for (auto nei : p.second)
            {
                cout << nei << " ";
            }
            cout << endl;
        }
    }

    void dfs(T start, unordered_map<T, bool> &visited)
    {
        cout << start << " ";
        visited[start] = true;
        for (auto x : h[start])
        {
            if (!visited[x])
            {
                dfs(x, visited);
            }
        }
        // SC:visited+n nodes(loop)+recursion stack space=O(N)+O(N)+O(N)=O(N)
        // TC:O(N)+2E
    }

    void totalnoofcomponents(T start)
    {
        int comp = 1;
        unordered_map<int, bool> visited;
        dfs(start, visited);
        for (auto x : h)
        {
            if (!visited[x.first])
            {
                comp++;
                dfs(x.first, visited);
            }
        }

        cout << endl;
        cout << "total no. of components are" << comp << endl;
    }
};
int main()
{
    Graph<int> g;
    // 1st graph
    g.addedge(0, 1);
    g.addedge(0, 3);
    g.addedge(0, 2);
    g.addedge(0, 4);
    g.addedge(3, 4);
    g.addedge(2, 3);
    g.addedge(1, 2);

    // 2nd graph
    g.addedge(11, 12);
    g.addedge(12, 10);
    g.addedge(10, 11);

    // 3rd graph
    g.addedge(100, 101);
    g.addedge(101, 102);

    // g.printgraph();

    // unordered_map<int, bool> visited;
    // g.dfs(4, visited);
    // cout << endl;

    g.totalnoofcomponents(4);
}
