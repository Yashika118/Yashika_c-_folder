#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// BRUTE FORCE

class Solution {
public:
    void findPathOfNode(TreeNode*root,TreeNode*p,vector<TreeNode*>v,vector<TreeNode*>&ans){
        if(root==NULL) return;
        v.push_back(root);
        if(root==p){
            ans=v;
            return;
        }

        findPathOfNode(root->left,p,v,ans);
         findPathOfNode(root->right,p,v,ans);
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode*lca=NULL;
        vector<TreeNode*>v;
        vector<TreeNode*>v1;
        vector<TreeNode*>v2;
        findPathOfNode(root,p,v,v1);
        findPathOfNode(root,q,v,v2);

        int Size=min(v1.size(),v2.size());

        for(int i=0;i<Size;i++){
            if(v1[i]==v2[i]){
                lca=v1[i];
            }
        }

        return lca;
    }
};


// BETTER SOL
// CHAT GPT SOL

// bool findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
//     if (root == nullptr) return false;

//     // Add the current node to the path
//     path.push_back(root);

//     // If the current node is the target node, return true
//     if (root == target) return true;

//     // Recur for left and right subtrees
//     if ((root->left && findPath(root->left, target, path)) ||
//         (root->right && findPath(root->right, target, path))) {
//         return true;
//     }

//     // If the target is not found, remove the current node from the path
//     path.pop_back();
//     return false;
// }

// vector<TreeNode*> getPath(TreeNode* root, TreeNode* target) {
//     vector<TreeNode*> path;
//     findPath(root, target, path);
//     return path;
// }



// OPTIMAL SOL
class Solution {
public:
    TreeNode*findLca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL) return NULL;
        if(root==p) return p;
        if(root==q) return q;

        TreeNode*a=findLca(root->left,p,q);
        TreeNode*b=findLca(root->right,p,q);

        if(a==NULL and b==NULL) return NULL;
        if(a==NULL and b!=NULL) return b;
        if(a!=NULL and b==NULL) return a;

        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findLca(root,p,q);
    }
};