#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class Solution{
    public:

    int check(Node*root){
        if(root==NULL) return 0;
        if(root->left==NULL and root->right==NULL) return root->data;
        
        int left=check(root->left);
        int right=check(root->right);
        
        if(left==-1 || right==-1) return -1;
        if(left+right==root->data) return root->data;
        
        return -1;
    }
    int isSumProperty(Node *root)
    {
        if(check(root)==-1) return 0;
        return 1;
    }
};

