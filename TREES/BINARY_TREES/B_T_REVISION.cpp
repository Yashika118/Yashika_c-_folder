#include <iostream>
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
        // recursive case
        node *root = new node(data);
        root->left = buildtree();
        root->right = buildtree();

        return root;
    }
}

void preorderprint(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // recursive case
    cout << root->data << " ";
    preorderprint(root->left);
    preorderprint(root->right);
}

int countnodesintree(node *root)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }

    // recursive case
    return countnodesintree(root->left) + countnodesintree(root->right) + 1;
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

int diameteroftree(node *root)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }

    // recursive case
    // op1 dia of lst
    int op1 = diameteroftree(root->left);
    // op2 dia of rst
    int op2 = diameteroftree(root->right);
    // op3 dia through root
    int op3 = height(root->left) + height(root->right);

    return max(op1, max(op2, op3));
}
int main()
{
    node *root = buildtree();
    // input 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
    preorderprint(root);
    cout << endl;
    cout << "number of nodes is " << countnodesintree(root) << endl;
    cout << "heights is " << height(root) << endl;
    cout << "diameter of tree is " << diameteroftree(root) << endl;
}