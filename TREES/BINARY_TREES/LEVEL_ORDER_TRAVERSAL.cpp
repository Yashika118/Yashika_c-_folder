#include <bits/stdc++.h>
// #include<iostream>
// #include <queue>
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

void levelordertraversal(node *root)
{
    queue<node *> q;
    q.push(root);

    int level = 1;
    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            node *root = q.front();
            q.pop();
            cout << root->data << " ";
            if (root->left)
            {
                q.push(root->left);
            }
            if (root->right)
            {
                q.push(root->right);
            }
        }
        level += 1;
        cout << endl;
    }
}
int main()
{
    node *root = buildtree();
    levelordertraversal(root);
}