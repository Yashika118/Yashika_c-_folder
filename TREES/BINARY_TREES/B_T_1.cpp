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
    cout << root->data << " ";
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
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // recursive case
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
int countnodes(node *root)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }

    // recursive case
    return countnodes(root->left) + countnodes(root->right) + 1;
}
int height(node *root)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }

    // recursive case
    return max(height(root->left), height(root->right)) + 1;
}

class Pair
{
public:
    int hei;
    int dia;

    Pair()
    {
        hei = 0;
        dia = 0;
    }
};

Pair diameterinon(node *root) // time complexity is o(n) --> optimise solution
{
    Pair p;

    // base case
    if (root == NULL)
    {
        return p;
    }

    // recursive case
    Pair l = diameterinon(root->left);
    Pair r = diameterinon(root->right);
    p.hei = max(l.hei, r.hei) + 1;

    int op1 = l.hei + r.hei;
    int op2 = l.dia;
    int op3 = r.dia;

    p.dia = max(op1, max(op2, op3));

    return p;
}
int diameter(node *root) // time complexity is n^2 -->not optimise solution
{
    // base case
    if (root == NULL)
    {
        return 0;
    }

    // recursive case
    // op1 is diameter is lies in lst    //op-->option
    int op1 = diameter(root->left);
    // op2 is diameter is lies in rst
    int op2 = diameter(root->right);
    // op3 is diameter is passing through root
    int op3 = height(root->left) + height(root->right);
    return max(op1, max(op2, op3));
}
int sumofnodesintree(node *root)
{
    //  base case
    if (root == NULL)
    {
        return 0;
    }
    // recursive case
    return sumofnodesintree(root->left) + sumofnodesintree(root->right) + root->data;
}
bool searchinbinarytree(node *root, int key)
{
    // base case
    if (root == NULL)
    {
        return false;
    }

    // recursive case
    if (root->data == key)
    {
        return true;
    }
    else
    {
        return searchinbinarytree(root->left, key) || searchinbinarytree(root->right, key);
    }
}
void mirroroftree(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // recursive case
    swap(root->left, root->right);
    mirroroftree(root->left);
    mirroroftree(root->right);
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
            cout << x->data;
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
int main()
{
    node *root = buildtree();

    // To print a tree
    // 1. pre order print
    // 2.in order print
    // 3. post order print

    // PRE ORDER PRINT for every node
    // 1. root ka data print krenge
    // 2.LST ka data print
    // 3.RST ka data print

    // IN ORDER PRINT
    // 1.LST
    // 2.root
    // 3.RST

    // POST ORDER PRINT
    // 1.LST
    // 2.RST
    // 3.root

    // cout << "pre order print" << endl;
    // preorder(root);
    // cout << endl;

    // cout << " inorder print" << endl;
    // inorder(root);
    // cout<<endl;

    // cout << " postorder print" << endl;
    // postorder(root);
    // cout<<endl;

    // cout << "count of nodes is " << countnodes(root) << endl;
    // cout << "height of tree is " << height(root) << endl;
    // cout << "diameter " << diameter(root) << endl;

    // let us INPUT for preorder: 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

    // Pair x = diameterinon(root);

    // cout << "diameter is " << x.dia << endl;
    // cout << "height is " << x.hei << endl;
    // cout << sumofnodesintree(root) << endl;

    // int key;
    // cin >> key;

    // if (searchinbinarytree(root, key) == true)
    // {
    //     cout << "yes present " << endl;
    // }
    // else
    // {
    //     cout << "not present" << endl;
    // }

    cout << "preorder print is" << endl;
    preorder(root);
    cout << endl;

    mirroroftree(root);

    cout << "after mirror print is " << endl;
    preorder(root);
    cout << endl;

    return 0;
};