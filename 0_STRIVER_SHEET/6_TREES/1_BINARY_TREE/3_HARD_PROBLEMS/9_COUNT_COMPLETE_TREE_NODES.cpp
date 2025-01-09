#include<bits/stdc++.h>
using namespace std;

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
    void numOfNodes(TreeNode*root,int &ans){
        if(root==NULL) return;

        ans=ans+1;
        numOfNodes(root->left,ans);
        numOfNodes(root->right,ans);
    }
    int countNodes(TreeNode* root) {
        int ans=0;
        numOfNodes(root,ans);
        return ans;
    }
};