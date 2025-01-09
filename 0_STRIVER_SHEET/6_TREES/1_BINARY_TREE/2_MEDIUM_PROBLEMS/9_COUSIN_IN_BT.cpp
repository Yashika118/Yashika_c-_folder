#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};

// BRUTE FORCE  / MY SOLUTION 
// DONT USE THIS AGAIN IT IS VERY COMPLEX

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == NULL)
            return false;
        queue<pair<TreeNode*, TreeNode*>> q;
        
        q.push({root, NULL});

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            map<int, TreeNode*> mp;
            bool xx = false, yy = false;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                TreeNode* parent = q.front().second;
                q.pop();

                if (node->left)
                    q.push({node->left, node});
                if (node->right)
                    q.push({node->right, node});

                level.push_back(node->val);
                mp[node->val] = parent;
            }

            if (level.size() > 1) {
                if (mp[x] != mp[y]) {

                    for (int j = 0; j < level.size(); j++) {
                        if (level[j] == x)
                            xx = true;
                    }
                    for (int k = 0; k < level.size(); k++) {
                        if (level[k] == y)
                            yy = true;
                    }

                    if (xx == true and yy == true)
                        return true;
                }
            }

        }

        return false;
    }
};


// OPTIMAL SOL

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        if(root) q.push(root);

        while(!q.empty()){
            int size=q.size();

            bool forx=false;
            bool fory=false;

            while(size--){
                //check for same parent
                bool xx=false;
                bool yy=false;
                //

                TreeNode*node=q.front();
                q.pop();
                if(node->val==x) forx=true;
                if(node->val==y) fory=true;


                if(node->left){
                    q.push(node->left);
                    if(node->left->val==x) xx=true;
                    if(node->left->val==y) yy=true;
                } 
                if(node->right){
                    q.push(node->right);
                    if(node->right->val==x) xx=true;
                    if(node->right->val==y) yy=true;
                }

                if(xx and yy) return false; //same parent
                
            }
            if(forx and fory) return true;
        }
        return false;
    }
};