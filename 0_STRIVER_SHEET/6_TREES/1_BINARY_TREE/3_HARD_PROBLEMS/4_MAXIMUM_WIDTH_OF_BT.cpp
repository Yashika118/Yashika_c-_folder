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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;

        queue<pair<TreeNode*,int>>q;     // address,index
        q.push({root,0});
        int ans=1;

        while(!q.empty()){
            int size=q.size();
            // width=lastIndex-firstIndex+1
            ans=max(ans,(q.back().second-q.front().second+1));

            for(int i=0;i<size;i++){
                auto node=q.front();
                long long index=node.second;
                q.pop();
                if(node.first->left) q.push({node.first->left,index*2+1});
                if(node.first->right) q.push({node.first->right,index*2+2});
            }
        }
        return ans;
    }
};