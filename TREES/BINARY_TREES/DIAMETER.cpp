// class solution{
// public:
//     int func(TreeNode*root, int ans){
//         if(root==NULL){
//             return 0;
//         }

//         int lh=func(root->left,ans);
//         int rh=func(root->right,ans);

//         ans=max(ans,lh+rh);

//         return max(lh,rh)+1;
//     }
//     int diameterofBinaryTree(TreeNode*root){
//         int ans=0;
//         func(root,ans);
//         return ans;
//     }
// };