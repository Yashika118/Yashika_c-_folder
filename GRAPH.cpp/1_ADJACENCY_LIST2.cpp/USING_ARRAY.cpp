// LS-62
#include <bits/stdc++.h>
using namespace std;
class Graph
{
    list<int> *arr;
    int n;

public:
    Graph(int noofnodes)
    {
        arr = new list<int>[noofnodes];
        n = noofnodes;
    }

    void addedge(int x, int y, bool bidirectional = true)
    {
        arr[x].push_back(y);
        if (bidirectional == true)
        {
            arr[y].push_back(x);
        }
    }

    void printgraph()
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << "-->";
            // for each -->ye loop jb tk kaam krta h jb tk list khtm nhi ho jati
            // synatx: for(type iterator: jispe iterate krana h)
            for (int x : arr[i])
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    Graph g(5);
    g.addedge(0, 1);
    g.addedge(0, 4);
    g.addedge(1, 4);
    g.addedge(1, 3);
    g.addedge(1, 2);
    g.addedge(4, 2);
    g.addedge(3, 2);

    g.printgraph();
}
