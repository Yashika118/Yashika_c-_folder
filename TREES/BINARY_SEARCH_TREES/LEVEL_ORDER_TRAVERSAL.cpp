/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;

        if (root == NULL)
        {
            return ans;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            vector<int> v;
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                TreeNode *x = q.front();
                q.pop();

                if (x->left != NULL)
                {
                    q.push(x->left);
                }

                if (x->right != NULL)
                {
                    q.push(x->right);
                }

                v.push_back(x->val);
            }

            ans.push_back(v);
        }
        return ans;
    }
};