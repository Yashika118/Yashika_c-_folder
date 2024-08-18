// LS-67
#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Graph
{

    unordered_map<T, list<T>> h;

public:
    void addedge(T x, T y, bool bidirectional = false)
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

    // find path from a node to every node
    // sssp-->single source sorted path
    int pathfind(T start, T end)
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
        return distance[end];
    }
};
int main()
{
    Graph<int> g;
    int board[50] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = -10;
    board[32] = -2;
    board[34] = -22;

    for (int u = 0; u < 36; u++)
    {
        for (int dice = 1; dice <= 6; dice++)
        {
            int v = u + dice + board[u + dice]; // 0+1+board[1]
            g.addedge(u, v);
        }
    }
    cout << g.pathfind(0, 36) << endl;
}