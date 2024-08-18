// // BRUTE FORCE  -->TC : O(n1*Logn+n2*Logn)+O(n1+n2)   SC:O(n1+n2)+O(n1+n2)
// #include<bits/stdc++.h>
// using namespace std;
// vector < int > sortedArray(vector < int > a, vector < int > b) {
//     // Write your code here
//     int n=a.size();
//     int m=b.size();
//     set<int>s;

//     for(int i=0;i<n;i++){
//         s.insert(a[i]);
//     }

//     for(int j=0;j<m;j++){
//         s.insert(b[j]);
//     }

//     vector<int>ans;
//     for(auto m:s){
//         ans.push_back(m);
//     }
//     return ans;
// }

// OPTIMAL SOLUTION --> TWO POINTER APPROACH
// TC --> O(N1+N2);
// SC --> O(N1+N2);
#include <bits/stdc++.h>
using namespace std;
vector<int> sortedArray(vector<int> a, vector<int> b)
{
    // Write your code here
    int n1 = a.size();
    int n2 = b.size();
    int i = 0;
    int j = 0;
    vector<int> unionArr;
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            if (unionArr.size() == 0 || unionArr.back() != a[i])
            {
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if (unionArr.size() == 0 || unionArr.back() != b[j])
            {
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }

    while (j < n2)
    {
        if (unionArr.size() == 0 || unionArr.back() != b[j])
        {
            unionArr.push_back(b[j]);
        }
        j++;
    }

    while (i < n1)
    {
        if (unionArr.size() == 0 || unionArr.back() != a[i])
        {
            unionArr.push_back(a[i]);
        }
        i++;
    }

    return unionArr;
}
