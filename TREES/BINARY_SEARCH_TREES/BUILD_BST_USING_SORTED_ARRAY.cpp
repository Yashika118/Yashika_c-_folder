#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
node *insertinbst(node *root, int data)
{
    if (root == NULL)
    {
        root = new node(data);

        return root;
    }
    else if (data <= root->data)
    {
        root->left = insertinbst(root->left, data);
        return root;
    }
    else
    {
        root->right = insertinbst(root->right, data);
        return root;
    }
}
node *buildbst()
{
    int data;
    node *root = NULL;
    cin >> data;
    while (data != -1)
    {
        root = insertinbst(root, data);
        cin >> data;
    }
    return root;
}

void printlevelorder(node *root)
{
    queue<node *> q;
    // step 1  push root and then NULL
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *x = q.front();
        q.pop();
        if (x == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << x->data << " ";
            // if left child is not NULL push in queue
            if (x->left != NULL)
            {
                q.push(x->left);
            }
            // if right child is not NULL push in queue
            if (x->right != NULL)
            {
                q.push(x->right);
            }
        }
    }
}
int arr[] = {2, 3, 6, 9, 13, 14, 16, 19};
node *buildbstusingsortedarr(int s, int e)
{
    // base case
    if (s > e)
    {
        return NULL;
    }

    // recursive case
    int mid = (s + e) / 2;
    node *root = new node(arr[mid]);
    root->left = buildbstusingsortedarr(s, mid - 1);
    root->right = buildbstusingsortedarr(mid + 1, e);
    return root;
}
int main()
{
    int n = sizeof(arr) / sizeof(int);
    node *root = buildbstusingsortedarr(0, n - 1);
    printlevelorder(root);
}