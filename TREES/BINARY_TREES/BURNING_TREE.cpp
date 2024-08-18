// class Solution
// {
// public:
//     vector<Node *> path;
//     bool dfs(Node *root, int target)
//     {
//         if (!root)
//         {
//             return false;
//         }
//         if (root->data == target)
//         {
//             path.push_back(root);
//             return true;
//         }

//         path.push_back(root);
//         bool left = dfs(root->left, target);
//         bool right = dfs(root->right, target);

//         if (left == false and right == false)
//         {
//             path.pop_back();
//         }
//         return left or right;
//     }

//     int height(Node *root, Node *blocked)
//     {

//         if (!root or root == blocked)
//         {
//             return 0;
//         }

//         int leftH = height(root->left, blocked);
//         int rightH = height(root->right, blocked);

//         return max(leftH, rightH) + 1;
//     }

//     int minTime(Node *root, int target)
//     {
//         dfs(root, target);
//         reverse(path.begin(), path.end());

//         int ans = 0;

//         for (int i = 0; i < path.size(); i++)
//         {
//             ans = max(ans, (i - 1) + height(path[i], i - 1 >= 0 ? path[i - 1] : NULL));
//         }

//         return ans;
//     }
// };