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

node *deletioninbst(node *root, int key)
{
    // case 1 key in lst
    if (key < root->data)
    {
        root->left = deletioninbst(root->left, key);
        return root;
    }

    // case 2 key in rst
    else if (key > root->data)
    {
        root->right = deletioninbst(root->right, key);
        return root;
    }

    else
    {
        // case 3 key agr root k equal hai
        // key==root->data
        // 1. lst and rst both are not present
        if (root->left == NULL and root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 2. only lst present
        else if (root->left != NULL and root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        // 3. only rst present
        else if (root->left == NULL and root->right != NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        // 4. lst and rst dono hai
        else
        {
            // // replacing max of lst
            // node*replace=root->left;
            // while(replace->right!=NULL){
            // replace=replace->right;
            // }
            // swap(root->data,replace->data);
            // root->left=deletioninbst(root->left,key);
            // return root;

            // or
            // // replacing min of rst
            node *replace = root->right;
            while (replace->left != NULL)
            {
                replace = replace->left;
            }
            swap(root->data, replace->data);
            root->right = deletioninbst(root->right, key);
            return root;
        }
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
int main()
{
    node *root = buildbst(); // INPUT: 8 3 10 1 6 14 4 9 7 13 -1
    printlevelorder(root);
    cout << endl;
    int key;
    cin >> key;
    deletioninbst(root, key);
    printlevelorder(root);
    cout << endl;
}