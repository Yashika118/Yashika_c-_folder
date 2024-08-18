// STRIVER
// adjancency list
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    } // TC:O(N)
      // SC: O(2* no. of edges)
    for (int i = 0; i <= n; i++)
    {
        cout << i << " -->";
        for (auto x : adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}