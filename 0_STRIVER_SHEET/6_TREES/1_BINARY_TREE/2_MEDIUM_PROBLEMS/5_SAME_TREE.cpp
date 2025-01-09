#include<bits/stdc++.h>
using namespace std;



// also do it using traversals

// using recursion
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
    bool check(TreeNode* p, TreeNode* q){
        if(p==NULL and q==NULL) return true;
        if(p==NULL and q!=NULL) return false;
        if(p!=NULL and q==NULL) return false;
        if(p->val!=q->val) return false;

        bool c1=check(p->left,q->left);
        bool c2=check(p->right,q->right);

        return (c1 and c2);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(check(p,q)) return true;
        return false;
    }
};