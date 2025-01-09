#include<bits/stdc++.h>
using namespace std;

// DIAMETER OF BT IS
// LONGEST PATH BETWEEN TWO NODES
// PATH DOES NOT NEED TO PASS VIA ROOT

// BRUTE FORCE


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
    int maxi=0;
    int findHeight(TreeNode*root){
        if(root==NULL) return 0;

        return 1+max(findHeight(root->left),findHeight(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;

        int lh=findHeight(root->left);
        int rh=findHeight(root->right);

        maxi=max(maxi,(lh+rh));

        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);

        return maxi;
    }
    // TC:O(N^2)
};


// OPTIMAL SOL
// MY SOL
class Solution {
public:
    int heightOfTree(TreeNode*root,int &maxi){
        if(root==NULL) return 0;

        int lh=heightOfTree(root->left,maxi);
        int rh=heightOfTree(root->right,maxi);

        maxi=max(maxi,(lh+rh));
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        heightOfTree(root,maxi);
        return maxi;
    }
    // TC:O(N)
};