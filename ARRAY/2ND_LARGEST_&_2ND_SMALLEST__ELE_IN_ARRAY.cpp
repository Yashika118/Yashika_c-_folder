// OPTIMAL SOLTUION  (TC-->O(N))
#include <bits/stdc++.h>
using namespace std;
int secondlargest(vector<int> &a, int n)
{
    int largest = a[0];
    int slargest = -1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > largest)
        {
            slargest = largest;
            largest = a[i];
        }
        else if (a[i] < largest and a[i] > slargest)
        {
            slargest = a[i];
        }
    }
    return slargest;
}

int secondsmallest(vector<int> &a, int n)
{
    int smallest = a[0];
    int ssmallest = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < smallest)
        {
            ssmallest = smallest;
            smallest = a[i];
        }
        else if (a[i] != smallest and a[i] < ssmallest)
        {
            ssmallest = a[i];
        }
    }
    return ssmallest;
}
vector<int> getSecondOrderElements(int n, vector<int> a)
{
    int slargest = secondlargest(a, n);
    int ssmallest = secondsmallest(a, n);

    return {slargest, ssmallest};
}
