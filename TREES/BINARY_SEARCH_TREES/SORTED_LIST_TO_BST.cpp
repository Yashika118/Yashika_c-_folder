// #include <bits/stdc++.h>
// using namespace std;
// class Solution
// {
// public:
//     TreeNode *sortedListToBST(ListNode *head)
//     {
//         if (head == NULL)
//         {
//             return NULL;
//         }
//         if (head->next == NULL)
//         {
//             return new TreeNode(head->val);
//         }

//         ListNode *slow = head;
//         ListNode *fast = head;
//         ListNode *prev = NULL;

//         while (fast != NULL and fast->next != NULL)
//         {
//             prev = slow;
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         ListNode *Middle = slow;
//         prev->next = NULL;

//         TreeNode *root = new TreeNode(Middle->val);
//         root->left = sortedListToBST(head);
//         root->right = sortedListToBST(Middle->next);

//         return root;
//     }
// };