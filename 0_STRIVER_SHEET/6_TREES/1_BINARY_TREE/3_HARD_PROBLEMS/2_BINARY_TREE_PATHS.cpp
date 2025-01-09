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
    void findAllPath(TreeNode*root,string s, vector<string>&ans){
        if(root==NULL) return;

        cout<<s<<endl;

        s+= to_string(root->val);
        if(root->left==NULL and root->right==NULL){
            ans.push_back(s);
        }
        s+="->";
        findAllPath(root->left,s,ans);
        findAllPath(root->right,s,ans);
        // s.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string s="";
        findAllPath(root,s,ans);
        return ans;
    }
};