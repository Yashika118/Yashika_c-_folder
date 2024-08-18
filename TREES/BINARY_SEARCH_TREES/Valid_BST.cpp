// // leetcode
// class Solution {
//     bool isPossible(TreeNode* root,long long int min,long long int max){
//         if(root==NULL){
//             return true;
//         }

//         if((root->val>min and root->val<max)){
//             return  isPossible(root->left,min,root->val) and isPossible(root->right,root->val,max);
//         }
//         return false;
//     }
// public:
//     bool isValidBST(TreeNode* root) {
//         long long int min=-1000000000000;
//         long long int max=1000000000000;
//         return isPossible(root,min,max);
//     }
// };