#include<bits/stdc++.h>
using namespace std;

// USING TRAVERSAL 
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
    void leftTree(TreeNode*root,vector<int>&left){   // ROOT LEFT RIGHT
        if(root==NULL){
            left.push_back(INT_MIN);
            return;
        }

        left.push_back(root->val);
        
        leftTree(root->left,left);
        leftTree(root->right,left);
    }
    void rightTree(TreeNode*root,vector<int>&right){  // ROOT RIGHT LEFT
        if(root==NULL){
            right.push_back(INT_MIN);
            return;
        }

        right.push_back(root->val);
        
        rightTree(root->right,right);
        rightTree(root->left,right);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        if(root->left==NULL and root->right==NULL) return true;
        if(root->left==NULL) return false;
        if(root->right==NULL) return false;

        vector<int>left;
        vector<int>right;
        leftTree(root->left,left);
        rightTree(root->right,right);

        for(int i=0;i<left.size();i++){
            if(left[i]!=right[i]) return false;
        }

        return true;
    }
};


// OPTIMAL SOL
// RECURSION SOL

class Solution {
public:
    bool check(TreeNode*p,TreeNode*q){
        if(p==NULL and q==NULL) return true;
        if(p==NULL and q!=NULL) return false;
        if(p!=NULL and q==NULL) return false;
        if(p->val!=q->val) return false;

        bool c1=check(p->left,q->right);
        bool c2=check(p->right,q->left);

        return (c1 and c2);
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode*p=root;
        TreeNode*q=root;
        if(check(p,q)) return true;
        return false;
    }
};