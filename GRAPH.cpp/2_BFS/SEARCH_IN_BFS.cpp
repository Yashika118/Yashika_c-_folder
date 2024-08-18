// SEARCH IN GRAPH:->
// has two algorithm
// 1. BFS-->Breadth First Search -->level wise search
// 2. DFS-->Depth First Search
// LS-66
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

    void bfs(T start) // bfs print is level wise print
    {
        queue<T> q;
        q.push(start); // 4
        unordered_map<T, bool> visited;
        visited[start] = true;

        while (!q.empty())
        {

            T data = q.front(); // 4
            q.pop();
            cout << data << " ";
            for (auto nei : h[data])
            {
                if (visited[nei] != true)
                {
                    q.push(nei);
                    visited[nei] = true;
                }
            }
        }
        cout << endl;

        // SC: visited+queue=O(2N)=O(N)
        // TC: O(N)+O(2E)
    }

    // find distance from a node to every node
    void bfsdistance(T start)
    {
        queue<T> q;
        q.push(start); // 4
        unordered_map<T, bool> visited;
        visited[start] = true;
        unordered_map<T, int> distance;
        distance[start] = 0;

        while (!q.empty())
        {

            T data = q.front(); // 4
            q.pop();
            for (auto nei : h[data])
            {
                if (visited[nei] != true)
                {
                    q.push(nei);
                    visited[nei] = true;
                    distance[nei] = distance[data] + 1;
                }
            }
        }

        for (auto x : distance)
        {
            cout << "distance of " << start << " to " << x.first << " will be " << x.second << endl;
        }
    }

    // find path from a node to every node
    // sssp-->single source sorted path
    void pathfind(T start, T end)
    {
        queue<T> q;
        q.push(start); // 4
        unordered_map<T, bool> visited;
        visited[start] = true;
        unordered_map<T, int> distance;
        distance[start] = 0;

        unordered_map<T, T> parent;
        parent[start] = start;

        while (!q.empty())
        {

            T data = q.front(); // 4
            q.pop();
            for (auto nei : h[data])
            {
                if (visited[nei] != true)
                {
                    q.push(nei);
                    visited[nei] = true;
                    distance[nei] = distance[data] + 1;
                    parent[nei] = data;
                }
            }
        }

        T temp = end;
        while (temp != start)
        {

            cout << temp << "<--";
            temp = parent[temp];
        }

        cout << temp << endl;
        // return distance[end];
    }
};
int main()
{
    Graph<int> g;
    g.addedge(0, 1);
    g.addedge(0, 3);
    g.addedge(0, 2);
    g.addedge(0, 4);
    g.addedge(3, 4);
    g.addedge(2, 3);
    g.addedge(1, 2);
    g.addedge(2, 3);
    g.addedge(1, 2);
    g.printgraph();

    g.bfs(4);
    g.bfsdistance(4);
    g.pathfind(4, 1);
}
