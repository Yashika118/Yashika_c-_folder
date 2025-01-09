// left boundary excluding leaf nodes
// leaf nodes using inorder
// right boundary excluding leaf nodes

#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE


struct Node
{
    int data;
    Node* left, * right;
}; 

class Solution {
  public:
    vector<int>temp;
    vector<int>v;
    bool isLeaf(Node*root){
        if(root->left==NULL and root->right==NULL) return true;
        return false;
    }
    void addLeftBoundary(Node*root,vector<int>&ans){
        Node*cur=root;
        while(cur){
            if(isLeaf(cur)) break;
            else ans.push_back(cur->data);
            if(cur->left) cur=cur->left;
            else cur=cur->right;
        }
        // tc:O(H)
    }
    void addRightBoundary(Node*root,vector<int>&ans){
        Node*cur=root;
        while(cur){
            if(isLeaf(cur)) break;
            else temp.push_back(cur->data);
            if(cur->right) cur=cur->right;
            else cur=cur->left;
        }
        
        // TC:O(H)
    }
    void addLeaf(Node*root,vector<int>&ans){
        if(root==NULL) return;
        
        if(isLeaf(root)) v.push_back(root->data);
        addLeaf(root->left,ans);
        addLeaf(root->right,ans);
        // O(N)
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>ans;
        if(isLeaf(root)==false) ans.push_back(root->data);
        addLeftBoundary(root->left,ans);
        addRightBoundary(root->right,ans);
        addLeaf(root,ans);
        
        for(int i=0;i<v.size();i++){
            ans.push_back(v[i]);
        }
        
        for(int i=temp.size()-1;i>=0;i--){
            ans.push_back(temp[i]);
        }
        
        return ans;
        
    }
};
// TC:O(H)+O(H)+O(N)=O(N)
// SC:O(N)