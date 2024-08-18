// // BINARY SEARCH TREE TO GREATER SUM TREE
// class Solution {
// public:
//     void func(TreeNode*root,int &sum){
//         if(root==NULL){
//             return ;
//         }
//         func(root->right,sum);
//         root->val=sum+root->val;
//         sum=root->val;
//         func(root->left,sum);
//     }
//     TreeNode* bstToGst(TreeNode* root) {
//         int sum=0;
//         func(root,sum);
//         return root;

//     }
// };