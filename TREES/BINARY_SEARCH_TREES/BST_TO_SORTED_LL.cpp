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

class linkedll
{
public:
    node *head;
    node *tail;
    linkedll()
    {
        head = NULL;
        tail = NULL;
    }
};

linkedll bsttosortedll(node *root)
{
    linkedll l;
    // base case
    if (root == NULL)
    {
        return l;
    }

    // recursive case
    // case 1 no lst and no rst
    if ((root->left == NULL) and (root->right == NULL))
    {
        l.head = root; // dot(.) is used to access the address of bucket
        l.tail = root;
        return l;
    }
    // case 2 only lst exist
    else if ((root->left != NULL) and (root->right == NULL))
    {
        linkedll le = bsttosortedll(root->left);
        le.tail->right = root;
        l.head = le.head;
        l.tail = root;
        return l;
    }
    // case 3 only rst exist
    else if ((root->left == NULL) and (root->right != NULL))
    {
        linkedll ri = bsttosortedll(root->right);
        root->right = ri.head;
        l.head = root;
        l.tail = ri.tail;
        return l;
    }

    // case 4 both lst and rst exist
    else
    {
        linkedll le = bsttosortedll(root->left);
        linkedll ri = bsttosortedll(root->right);
        le.tail->right = root;
        root->right = ri.head;
        l.head = le.head;
        l.tail = ri.tail;
        return l;
    }
}
void printll(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->right;
    }
    cout << endl;
}

int main()
{
    node *root = buildbst(); // INPUT: 8 3 10 1 6 14 4 7 13 -1
    printlevelorder(root);
    linkedll x = bsttosortedll(root);
    printll(x.head);
}