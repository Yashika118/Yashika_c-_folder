// LS-62
#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
class Graph
{
    unordered_map<string, list<string>> h;

public:
    void addedge(string x, string y, bool bidirectional = false)
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
        { // p means pair-->(key-->value)
            cout << p.first << "-->";
            for (auto x : p.second)
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    Graph g;
    g.addedge("putin", "trump");
    g.addedge("putin", "modi");
    g.addedge("putin", "pope");
    g.addedge("trump", "modi", true);
    g.addedge("pope", "");
    g.addedge("prabhu", "modi");
    g.addedge("yogi", "modi", true);
    g.addedge("yogi", "prabhu");
    g.printgraph();
}