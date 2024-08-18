#include <iostream>
using namespace std;
class node
{
public:
    int d;
    node *next;

    node(int data)
    {
        d = data;
        next = NULL;
    }
};
void insertatfront(node *&head, node *&tail, int data)
{
    node *n = new node(data); // DMA
    // if ll is emplty
    if (head == NULL)
    {
        head = n;
        tail = n;
    }
    // if ll is not empty
    else
    {
        n->next = head;
        head = n;
    }
}

void insertattail(node *&head, node *&tail, int data)
{
    node *n = new node(data); // DMA
    // if ll is emplty
    if (head == NULL)
    {
        head = n;
        tail = n;
    }
    // if ll is not empty
    else
    {
        tail->next = n;
        tail = n;
    }
}
void printll(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->d << " ";
        temp = temp->next;
    }
}

int lengthofll(node *head)
{
    int count = 0;
    node *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

void insertatanypos(node *&head, node *&tail, int data, int position)
{

    if (position == 0)
    {
        insertatfront(head, tail, data);
    }
    else if (position >= lengthofll(head))
    {
        insertattail(head, tail, data);
    }
    else
    {
        node *temp = head;

        for (int jump = 1; jump <= position - 1; jump++)
        {
            temp = temp->next;
        }

        node *n = new node(data);
        n->next = temp->next;
        temp->next = n;
    }
}

node *midpointofll(node *head)
{
    node *slow = head;
    // node *fast = head;
    node *fast = head->next;

    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int Kthnodefromend(node *head, int k)
{
    node *x = head;
    node *y = head;
    for (int jump = 1; jump <= k - 1; jump++)
    {
        y = y->next;
    }

    while (y->next != NULL)
    {
        x = x->next;
        y = y->next;
    }

    return x->d;
}

int main()
{

    node *head = NULL;
    node *tail = NULL;

    int n, data;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> data;
        insertattail(head, tail, data);
    }

    cout << Kthnodefromend(head, 3) << endl;
    cout << Kthnodefromend(head, 2);

    // printll(head);
    // cout << endl;
}