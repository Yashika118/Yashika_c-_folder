// Amount of Time for Binary Tree to Be Infected

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution {
  public:
    void keepParentTrack(Node*root,map<Node*,Node*>&track_parent){
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            int size=q.size();
            
            for(int i=0;i<size;i++){
                Node*node=q.front();
                q.pop();
                
               if(node->left){
                   track_parent[node->left]=node;
                   q.push(node->left);
               }
               if(node->right){
                   track_parent[node->right]=node;
                   q.push(node->right);
               }
            }
        }
    }
    Node* findTargetAddress(Node*root,int target){
        if(root==NULL) return NULL;
        if(root->data==target) return root;
        
        
        Node*l=findTargetAddress(root->left,target);
        if(l) return l;
        
        Node*r=findTargetAddress(root->right,target);
        if(r) return r;
        
        return NULL;
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node*,Node*>track_parent;
        keepParentTrack(root,track_parent);
        
        Node*tar=findTargetAddress(root,target);
        
        map<Node*,int>vis;       //  node ,1
        queue<pair<Node*,int>>q;  // node, time
        q.push({tar,0});
        vis[tar]=1;
        
        int time=0;
        
        while(!q.empty()){
           
                auto p=q.front();
                q.pop();
                
                Node*node=p.first;
                int t=p.second;
                
                time=t;
                
                if(node->left and !vis[node->left]){
                    q.push({node->left,t+1});
                    vis[node->left]=1;
                }
                if(node->right and !vis[node->right]){
                    q.push({node->right,t+1});
                    vis[node->right]=1;
                }
                if(track_parent[node] and !vis[track_parent[node]]){
                    q.push({track_parent[node],t+1});
                    vis[track_parent[node]]=1;
                }
            
        }
        
        return time;
        
    }
};
