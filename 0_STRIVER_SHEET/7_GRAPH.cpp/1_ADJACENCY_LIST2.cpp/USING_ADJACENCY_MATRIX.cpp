// STRIVER
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m; // n--> no.of nodes   m-->no. of edges
    cin >> n >> m;
    int adj[n + 1][n + 1] = {0};

    for (int i = 0; i < m; i++) // input for m lines
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    } // O(N)

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    } // O(N^2)

    // TC: O(n)+O(n^2)
    // SC: O(n^2)
    return 0;
}