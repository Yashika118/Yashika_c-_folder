// // BINARY TREE FROM PREORDER AND INORDER TRAVERSAL
// class Solution{
// public:
//         map<int,int>m;
//         vector<int>preorder;
//         vector<int>inorder;

//         TreeNode* func(int start, int end,int &pre_index){
//             // base case
//             if(start>end){
//                 return NULL;
//             }

//             // recursive case
//             TreeNode*root=new TreeNode(preorder[pre_index]);

//             int index=m[preorder[pre_index]];
//             pre_index+=1;

//             root->left=func(start,index-1,pre_index);
//             root->right=func(index+1,end,pre_index);

//             return root;
//         }

//         TreeNode*buildTree(vector<int>&preorder, vector<int>&inorder){
//             this->preorder=preorder;
//             this->inorder=inorder;

//             for(int i=0;i<inorder.size();i++){
//                 m[inorder[i]]=i;
//             }

//             int pre_index=0;
//             return func(0,inorder.size()-1,pre_index);

//         }
// };