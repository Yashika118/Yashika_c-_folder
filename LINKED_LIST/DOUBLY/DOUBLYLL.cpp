#include <iostream>
using namespace std;
class node
{
public:
    int d;
    node *f;
    node *b;

    node(int data)
    {
        d = data;
        f = NULL;
        b = NULL;
    }
};

void insertatfront(node *&head, node *&tail, int data)
{
    node *n = new node(data);
    if (head == NULL)
    {
        head = n;
        tail = n;
    }
    else
    {
        n->f = head;
        head->b = n;
        head = n;
    }
}
void insertattail(node *&head, node *&tail, int data)
{
    node *n = new node(data);
    if (head == NULL)
    {
        head = n;
        tail = n;
    }
    else
    {
        n->b = tail;
        tail->f = n;
        tail = n;
    }
}
void printll(node *tail)
{
    node *temp = tail;

    while (temp != NULL)
    {
        cout << temp->d << " ";
        temp = temp->b;
    }
}

int main()
{
    node *head = NULL;
    node *tail = NULL;

    insertatfront(head, tail, 4);
    insertatfront(head, tail, 89);
    insertatfront(head, tail, 13);
    insertatfront(head, tail, 8);
    printll(tail);
    // cout << endl;
    // printll(head);
}