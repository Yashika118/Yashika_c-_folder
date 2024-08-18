#include <bits/stdc++.h>
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

void rightview(node *root, int cl, int &ml)
{ // cl--> current level   ,ml-->maximum level
    // base case
    if (root == NULL)
    {
        return;
    }

    // recursive case
    if (cl > ml)
    {
        cout << root->data << " ";
        ml++;
    }
    rightview(root->right, cl + 1, ml);
    rightview(root->left, cl + 1, ml);
}

void leftview(node *root, int cl, int &ml)
{ // cl--> current level   ,ml-->maximum level
    // base case
    if (root == NULL)
    {
        return;
    }

    // recursive case
    if (cl > ml)
    {
        cout << root->data << " ";
        ml++;
    }
    leftview(root->left, cl + 1, ml);
    leftview(root->right, cl + 1, ml);
}

int main()
{
    node *root = buildbst(); // INPUT: 8 3 10 1 6 14 4 7 13 -1
    printlevelorder(root);
    int k = 0;

    // cout << "right view is " << endl;
    // rightview(root, 1, k);
    // cout << endl;

    cout << "left view is " << endl;
    leftview(root, 1, k);
    cout << endl;
}