#include <iostream>
#include <climits>
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

node *buildtree()
{
    int data;
    cin >> data; // 8

    if (data == -1)
    {
        return NULL;
    }
    else
    {
        node *root = new node(data);
        root->left = buildtree();
        root->right = buildtree();

        return root;
    }
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
// print nodes between k1 and k2 in sorted order (we use inorder for bst so it will be sorted)
void nodebtwk1andk2(node *root, int k1, int k2) //--->today
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // recursive case
    nodebtwk1andk2(root->left, k1, k2);
    if ((root->data >= k1) and (root->data <= k2))
    {
        cout << root->data << " ";
    }
    nodebtwk1andk2(root->right, k1, k2);
}

int main()
{
    node *root = buildbst(); // INPUT: 8 3 10 1 6 14 4 7 13 -1
    printlevelorder(root);

    int k1, k2;
    cin >> k1 >> k2;
    nodebtwk1andk2(root, k1, k2);
}