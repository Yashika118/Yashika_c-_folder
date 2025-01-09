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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>avg;
        if(root==NULL) return avg;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            double lvlSum=0;

            for(int i=0;i<size;i++){
                TreeNode*node=q.front();
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                lvlSum+=node->val;
            }
            avg.push_back((double)lvlSum / (double)size);
        }

        return avg;
    }
};