#include<bits/stdc++.h>
using namespace std;

// USING LEVEL ORDER TRAVERSAL

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            vector<int>v;

            for(int i=0;i<size;i++){
                TreeNode*node=q.front();
                q.pop();
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                v.push_back(node->val);
            }
            ans.push_back(v[size-1]);
        }

        return ans;
    }
};

// BETTER SOL
// USING LEVEL ORDER
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            int num;
            for(int i=0;i<size;i++){
                TreeNode*node=q.front();
                q.pop();
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                num=node->val;
            }
            ans.push_back(num);
        }

        return ans;
    }
};


// OPTIMAL SOL
// USING RECURSION   

class Solution {
public:
    void rightViewFunc(TreeNode*root,int level,vector<int>&ans){
        if(root==NULL) return;

        if(level==ans.size()) ans.push_back(root->val);
        rightViewFunc(root->right,level+1,ans);
        rightViewFunc(root->left,level+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        rightViewFunc(root,0,ans);
        return ans;
    }
};
