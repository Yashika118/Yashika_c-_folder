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
    node *n = new node(data);
    if (head == NULL)
    {
        head = n;
        tail = n;
    }
    else
    {
        n->next = head;
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
        tail->next = n;
        tail = n;
    }
}
void printll(node *&head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->d << " ";
        temp = temp->next;
    }
}
int lengthofll(node *&head)
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
        n->next = temp;
        temp->next = n;
    }
}
void deleteatfront(node *&head, node *&tail)
{
    // ll is not present
    if (head == NULL)
    {
        return;
    }
    else if (head->next == NULL)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        node *temp = head;
        head = head->next;
        delete temp;
        temp = NULL;
    }
}
void deleteattail(node *&head, node *&tail)
{
    // ll is not present
    if (head == NULL)
    {
        return;
    }
    else if (head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        node *temp = head;
        for (int jump = 1; jump <= lengthofll(head) - 2; jump++)
        {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }
}
void deleteatanypos(node *&head, node *&tail, int position)
{
    if (position == 0)
    {
        deleteatfront(head, tail);
    }
    else if (position >= lengthofll(head) - 1)
    {
        deleteattail(head, tail);
    }
    else
    {
        node *temp = head;
        for (int jump = 1; jump <= position - 1; jump++)
        {
            temp = temp->next;
        }
        node *a = temp->next;
        temp->next = temp->next->next;
        delete a;
        a = NULL;
    }
}
int main()
{
    node *head = NULL;
    node *tail = NULL;
    insertatfront(head, tail, 4);
    insertatfront(head, tail, 50);
    insertattail(head, tail, 24);
    insertattail(head, tail, 12);
    printll(head);
    cout << endl;
    cout << lengthofll(head) << endl;
    insertatanypos(head, tail, 23, 3);
    printll(head);
    deleteatfront(head, tail);
    deleteattail(head, tail);
    deleteatanypos(head, tail, 2);
    printll(head);
}