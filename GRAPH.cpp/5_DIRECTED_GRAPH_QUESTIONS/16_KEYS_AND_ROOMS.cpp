#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(int node,vector<int>&visited,vector<vector<int>>rooms){
        int n=rooms.size();
        visited[node]=1;
        for(auto it:rooms[node]){
            if(!visited[it]){
                check(it,visited,rooms);
            }
        }
        for(int i=0;i<n;i++){
            if(visited[i]==0) return false;
        }
        return true;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>visited(n,0);
        if(check(0,visited,rooms)==true){
            return true;
        }
        return false;
    }
};