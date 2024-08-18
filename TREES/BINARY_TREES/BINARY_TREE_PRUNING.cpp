// class Solution {
// public:

//     bool func(TreeNode*root){
//         // base case
//         if(root==NULL){
//             return true;
//         }

//         // recursive case
//         bool left_decision= func(root->left);
//         bool right_decision= func(root->right);

//         if(left_decision){
//             root->left=NULL;
//         }
//         if(right_decision){
//             root->right=NULL;
//         }

//         // agr l->true , r->true, node->0  : true
//         if(left_decision and right_decision and root->val==0){
//             return true;
//         }
//         return false;
//     }
//     TreeNode* pruneTree(TreeNode* root) {

//         bool ok=func(root);
//         if(ok==true){
//             return NULL;
//         }

//         return root;
//     }
// };