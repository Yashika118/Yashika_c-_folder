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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;          // x-->y--->{values..}
        queue<pair<TreeNode*,pair<int,int>>>q;      // (val,x,y)
        q.push({root,{0,0}});

        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode*node=p.first;
            int x=p.second.first;
            int y=p.second.second;

            mp[x][y].insert(node->val);

            if(node->left){
                q.push({node->left,{x-1,y+1}});
            }
            if(node->right){
                q.push({node->right,{x+1,y+1}});
            }

        }

        vector<vector<int>>ans;
        for(auto p:mp){
            vector<int>col;
            for(auto q:p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }

        return  ans;
    }
};



// // BRUTE FORCE
// class Solution {
//   public:
//     vector <int> bottomView(Node *root) {
//         map<int,map<int,vector<int>>>mp;   // x-->y-->{value..}
//         queue<pair<Node*,pair<int,int>>>q;
//         q.push({root,{0,0}});
        
//         while(!q.empty()){
//             auto p=q.front();
//             q.pop();
//             Node*node=p.first;
//             int x=p.second.first;
//             int y=p.second.second;
            
//             mp[x][y].push_back(node->data);
            
//             if(node->left) q.push({node->left,{x-1,y+1}});
//             if(node->right) q.push({node->right,{x+1,y+1}});
//         }
        
//         vector<int> ans;
//         for (auto it : mp) {
//             auto innMap = it.second; // Access the inner map

//             if (!innMap.empty()) { // Check if the inner map is not empty
//                 auto lastPair = prev(innMap.end()); // Get the last entry in the inner map
//                 auto lastSet = lastPair->second; // Get the multiset for the last level         if (!lastSet.empty()) { // Check if the multiset is not empty
//                 auto lastEle = *prev(lastSet.end()); // Get the last element in the multiset
//                 ans.push_back(lastEle); // Add the element to the result vector
//              }
//         }

//         return ans;
//     }
// };