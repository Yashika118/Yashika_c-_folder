#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>inDegree(n+1,0);
        vector<int>outDegree(n+1,0);

        for(auto it:trust){
            inDegree[it[1]]++;
            outDegree[it[0]]++;
        }

        for(int i=1;i<=n;i++){
            if(outDegree[i]==0 and inDegree[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};