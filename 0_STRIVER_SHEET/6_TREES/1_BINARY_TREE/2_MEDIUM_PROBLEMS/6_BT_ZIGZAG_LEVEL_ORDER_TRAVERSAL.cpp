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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>zigzag;
        if(root==NULL) return zigzag;

        int flag=true; // l --> r

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            vector<int>v(size);

            for(int i=0;i<size;i++){
                TreeNode*node=q.front();
                q.pop();

                int index=(flag) ? i : (size-1-i);
                
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                
                v[index]=node->val;
            }
            flag=!flag;
            zigzag.push_back(v);
            
        }

        return zigzag;
    }
};





// my sol


// class Solution {
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         vector<vector<int>>ans;

//         if(root==NULL){
//             return ans;
//         }

//             queue<TreeNode*>q;
//             q.push(root);
//             int count=1;

//         while(!q.empty()){
//             vector<int>v;
//             int size=q.size();

//             for(int i=0;i<size;i++){
//                 TreeNode*x=q.front();
//                 q.pop();

//                 if(x->left!=NULL){
//                     q.push(x->left);
//                 }

//                 if(x->right!=NULL){
//                     q.push(x->right);
//                 }

//                 v.push_back(x->val);
//             }

//             if(count%2!=0){
//                 ans.push_back(v);
//             }

//             // if(count%2!=0 and v.size()!=1){
//             //     swap(v[0],v[1]);
//             //     ans.push_back(v);
//             // }

//             if(count%2==0 and v.size()==1){
//                 ans.push_back(v);
//             }

//             if(count%2==0 and v.size()!=1){
//                 int i=0;
//                 int j=v.size()-1;
//                 while(i!=j and i<j){
//                     swap(v[i],v[j]);
//                     i++;
//                     j--;
//                 }
                
//                 ans.push_back(v);
//             }

//             count++;
        
//         }
//         return ans;
        
//     }
// };