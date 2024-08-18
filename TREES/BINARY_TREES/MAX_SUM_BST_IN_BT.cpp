// #include<bits/stdc++.h>
// using namespace std;
// struct Node{
//     int maxi;
//     int mini;
//     int sum;
//     bool isBst;
//     Node(int maxi, int mini, int sum, bool isBst){
//         this->maxi=maxi;
//         this->mini=mini;
//         this->sum=sum;
//         this->isBst=isBst;
//     }
// };
// class Solution{
//     private:
//     int ans;
//     public:
//     Node func(TreeNode*root){
//         if(!root){
//             return Node({INT_MIN, INT_MAX,0,true});
//         }
//         if(!root->left and !root->right){
//             ans=max(ans,root->val);
//             return Node({root->val,root->val,root->val,true});
//         }

//         Node left=func(root->left);
//         Node right=func(root->right);

//         int curr_max=max({left.maxi,right.maxi,root->val});
//         int curr_min=min({left.mini,right.mini,root->val});
//         int sum=root->val+left.sum+right.sum;
//         bool flag=false;

//         if(left.isBst and right.isBst){
//             if(left.maxi<root->val and right.maxi>root->val){
//                 ans=max(ans,sum);
//                 flag=true;
//             }
//         }
//         return Node(curr_max,curr_min,sum,flag);
//     }

//     int maxSumBST(TreeNode*root){
//         ans=0;
//         func(root);
//         return ans==INT_MIN ? 0:ans;
//     }
// };