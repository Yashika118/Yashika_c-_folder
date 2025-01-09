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
    int findMaxSum(TreeNode*root,int &sum){
        if(root==NULL) return 0;

        int lsum=max(0,findMaxSum(root->left,sum));
        int rsum=max(0,findMaxSum(root->right,sum));

        int newSum=root->val+lsum+rsum;
        sum=max(sum,newSum);
        
        return root->val + max(lsum,rsum);

    }
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        findMaxSum(root,sum);
        return sum;
        
    }
    // TC:O(N)
};