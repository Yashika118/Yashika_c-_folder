//  CamerChahiye 1
//  nhiChahiye 0
//  CameraInstalled 2
// class Solution {
// public:
//     int ans;
//     int func(TreeNode*root){
//         if(root==NULL){
//             return 0;
//         }

//         int l=func(root->left);
//         int r=func(root->right);

//         if(l==1 or r==1){
//             ans+=1;
//             return 2;
//         }

//         if(l==2 or r==2){
//             return 0;
//         }
//         return 1;
//     }
//     int minCameraCover(TreeNode* root) {
//         ans=0;
//         int ok=func(root);
//         if(ok==1){
//             ans+=1;
//         }

//      return ans;
//     }
// };