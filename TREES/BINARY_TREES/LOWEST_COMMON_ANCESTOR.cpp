// BRUTFORCE SOL OF O(n^2);
class Solution
{
public:
    vector<TreeNode *> a;
    bool path(TreeNode *root, TreeNode *Q)
    {

        if (root == NULL)
        {
            return false;
        }
        if (root == Q)
        {
            a.push_back(root);
            return true;
        }
        a.push_back(root);
        bool left = path(root->left, Q); // false
        bool right = path(root->right, Q);
        if (left == false and right == false)
        {
            a.pop_back();
        }
        return (left || right);
    }

    TreeNode *lca(TreeNode *qq, TreeNode *pp)
    {
        int vsize = 0;

        if (pp.size() < qq.size();)
        {
            vsize = pp.size();
        }
        else
        {
            vsize = qq.size();
        }

        int i = 0;
        TreeNode *val = 0;
        while (i < vsize)
        {
            if (qq[i] != pp[i])
            {
                break;
            }
            val = qq[i];
            i++;
        }
        return val;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        path(root, q);
        vector<TreeNode *> qq = a;
        path(root, p);
        vector<TreeNode *> pp = a;

        Treenode *ans = lca(TreeNode * qq, TreeNode * pp);
        return ans;
    }
};

// SOL OF O(n);
// class Solution {
// public:
//     TreeNode* lca(TreeNode*root,TreeNode*p,TreeNode*q){
//         if(root==NULL){
//             return NULL;
//         }
//         if(root==p or root==q){
//             return root;
//         }
//         TreeNode* l1=lca(root->left,p,q);
//         TreeNode* r1=lca(root->right,p,q);

//         if(l1 and r1){     //--> agr l1 and r1 dono hi exist krte h toh return krna h root;
//             return root;
//         }
//         return l1==NULL ? r1:l1;

//     }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         return lca(root,p,q);
//     }
// };