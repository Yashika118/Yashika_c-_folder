//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int>topo(int K,vector<int>adj[]){
        vector<int>indegree(K,0);
        for(int i=0;i<K;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<K;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        return ans;
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int>adj[K];
        
        for(int i=0;i<N-1;i++){
            string s1=dict[i];
            string s2=dict[i+1];
            int len=min(s1.size(),s2.size());
            
            for(int ch=0; ch<len; ch++){
                if(s1[ch]!=s2[ch]){
                    adj[s1[ch]-'a'].push_back(s2[ch]-'a');
                    break;
                }
            }
        }
        
        vector<int>ans=topo(K,adj);
        
        string str="";
        
        for(auto it:ans){
            // char temp=ans[i]+'a';
            str=str+char(it+'a');
        }
        
        
        return str;
    }
};

// Dictionary is wrong when
// the order is not possible when larger string is before smaller string
//      for example : a b c d
//                    a b c
// when cyclic dependency exist
//      for example a is before b is before a