#include<bits/stdc++.h>
using namespace std;


// using level order traversal

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        vector<vector<int>>levels;
        if(root==NULL) return 0;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            vector<int>v;
            for(int i=0;i<size;i++){

                TreeNode*n=q.front();
                q.pop();
                if(n->left!=NULL) q.push(n->left);
                if(n->right!=NULL) q.push(n->right);
                v.push_back(n->val);
            }
            levels.push_back(v);
        }
        return levels.size();
    }
};


// using recursion

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;

        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};