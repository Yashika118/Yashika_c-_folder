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
node *buildtreelevelwise()
{
    int data;
    cout << "Enter the data of root node" << endl;
    cin >> data; // 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1

    if (data == -1)
    {
        return NULL;
    }
    else
    {
        node *root = new node(data);
        queue<node *> q;
        q.push(root);

        while (!q.empty())
        {

            node *x = q.front();
            q.pop();

            cout << "Enter the left and right child of " << x->data << endl;

            int lc, rc;
            cin >> lc >> rc;

            if (lc != -1)
            {
                x->left = new node(lc);
                q.push(x->left);
            }

            if (rc != -1)
            {
                x->right = new node(rc);
                q.push(x->right);
            }
        }

        return root;
    }
}
void func(node *root, map<int, int> &m, int x)
{
    // base case
    if (!root)
    {
        return;
    }

    // recursive case
    if (m.find(x) == m.end())
    {
        m[x] = root->data;
    }
    func(root->left, m, x - 1);
    func(root->right, m, x + 1);
}

int main()
{
    node *root = buildtreelevelwise();
    map<int, int> mp;
    func(root, mp, 0);

    cout << "Top View of Binary Tree : ";

    for (auto x : mp)
    {
        cout << x.second << " ";
    }
    cout << endl;
}