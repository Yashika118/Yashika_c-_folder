#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void mark_parent(TreeNode*root,map<TreeNode*,TreeNode*>&parent_track){
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode*node=q.front();
                q.pop();
                if(node->left) {
                    q.push(node->left);
                    parent_track[node->left]=node;
                }
                if(node->right) {
                    q.push(node->right);
                    parent_track[node->right]=node;
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // mark parents
        map<TreeNode*,TreeNode*>parent_track;
        mark_parent(root,parent_track);

        map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
        int cur_level=0;

        while(!q.empty()){
            int size=q.size();
            if(cur_level==k) break;
            for(int i=0;i<size;i++){
                TreeNode*node=q.front();
                q.pop();
                // node->left exist krta h and not visited h
                if(node->left and !vis[node->left]){
                    q.push(node->left);
                    vis[node->left]=true;
                }
                // node->right exist krta h and not visited h
                if(node->right and !vis[node->right]){
                    q.push(node->right);
                    vis[node->right]=true;
                }
                // node ka parent exist krta h and not visited h
                if(parent_track[node] and !vis[parent_track[node]]){
                    q.push(parent_track[node]);
                    vis[parent_track[node]]=true;
                }
            }
            cur_level++;
        }

        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;

    }
};