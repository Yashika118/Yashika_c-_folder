// BALANCED_BT : FOR EVERY NODE --> HEIGHT(LEFT)-HEIGHT(RIGHT) <= 1

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
    int heightOfTree(TreeNode*root){
        if(root==NULL) return 0;

        return 1+max(heightOfTree(root->left),heightOfTree(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        
        int leftHeight=heightOfTree(root->left);
        int rightHeight=heightOfTree(root->right);

        if(abs(leftHeight-rightHeight)>1) return false;

        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);

        if(left and right ) return true;

        return false;


    }
    // TC:O(N^2)
};


// OPTIMAL SOL

class Solution {
public:
    int heightOfTree(TreeNode*root){
        if(root==NULL) return 0;
        
        int lh=heightOfTree(root->left);
        if(lh==-1) return -1;

        int rh=heightOfTree(root->right);
        if(rh==-1) return -1;
        
        if(abs(lh-rh)>1) return -1;

        return max(lh,rh)+1;
    }
    bool isBalanced(TreeNode* root) {
        return heightOfTree(root)!=-1;
    }
    // TC:O(N)
};