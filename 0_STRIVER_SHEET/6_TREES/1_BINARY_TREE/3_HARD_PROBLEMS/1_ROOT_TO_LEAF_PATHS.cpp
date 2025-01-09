//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    void findAllPaths(Node*root,vector<int>v,vector<vector<int>>&ans){
        if(root==NULL) return;
        
        v.push_back(root->data);
        
        if(root->left==NULL and root->right==NULL){
            ans.push_back(v);
            // return;
        }
        
        findAllPaths(root->left,v,ans);
        findAllPaths(root->right,v,ans);
        v.pop_back();
        
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>>ans;
        vector<int>v;
        findAllPaths(root,v,ans);
        return ans;
    }
};


