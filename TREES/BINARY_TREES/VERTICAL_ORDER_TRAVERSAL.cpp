
// class Solution {
// public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         map<int,map<int,multiset<int>>>mp;
//         queue<pair<TreeNode*,pair<int,int>>>q;

//         q.push({root,{0,0}});

//         while(!q.empty()){
//             auto p=q.front();
//             q.pop();

//             TreeNode*node=p.first; //root address
//             int x=p.second.first;  //row
//             int y=p.second.second; //col

//             mp[x][y].insert(node->val);

//             if(node->left){
//                 q.push({node->left,{x-1,y+1}});
//             }

//             if(node->right){
//                 q.push({node->right,{x+1,y+1}});
//             }
//         }

//         vector<vector<int>>ans;

//                 for(auto it:mp){
//                     vector<int>col;

//                     for(auto p:it.second){
//                         // col.push_back(p->val);
//                         col.insert(col.end(),p.second.begin(),p.second.end());
//                     }

//                     ans.push_back(col);
//                 }

//                 // for(auto it:mp){
//                 //     cout<<it.first<<" ";
//                 //     for(auto i:it.second){
//                 //         cout<<i.first<<" ";
//                 //         for(auto x:i.second){
//                 //             cout<<x<<" ";
//                 //         }
//                 //     }
//                 //     cout<<endl;
//                 // }

//                 return ans;
//     }
// };