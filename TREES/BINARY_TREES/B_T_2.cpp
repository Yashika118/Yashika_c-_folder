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
void preorder(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // recursive case
    cout << root->data << ", ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // recursive case
    inorder(root->left);
    cout << root->data << ", ";
    inorder(root->right);
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

int preord[] = {8, 3, 1, 6, 4, 7, 10, 14, 13};
int inord[] = {1, 3, 4, 6, 7, 8, 10, 13, 14};
int i = 0;

node *buildtreeusingpreandin(int s, int e)
{

    // base case
    if (s > e)
    {
        return NULL;
    }

    // recursive case
    int x = preord[i]; // 8
    i++;

    node *root = new node(x);

    int k;
    for (k = s; k <= e; k++)
    {
        if (inord[k] == x)
        {
            break;
        }
    }

    root->left = buildtreeusingpreandin(s, k - 1);
    root->right = buildtreeusingpreandin(k + 1, e);
    return root;
}

int main()
{
    // node*root=buildtree();  //8 6 1 -1 -1 7 -1 -1 9 -1 14 13 -1 -1 -1
    // printlevelorder(root);

    int n = sizeof(preord) / sizeof(int);
    node *root = buildtreeusingpreandin(0, n - 1);
    printlevelorder(root);

    // preorder(root);
    // cout << endl;

    // inorder(root);
    // cout << endl;

    return 0;
};