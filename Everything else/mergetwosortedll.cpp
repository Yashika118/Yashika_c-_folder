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

void bubblesort(node *head)
{
    for (int i = 0; i <= lengthofll(head) - 2; i++)
    {
        for (node *j = head; j->next != NULL; j = j->next)
        {
            if (j->d > j->next->d)
            {
                swap(j->d, j->next->d);
            }
        }
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
node *mergetwosortedll(node *head1, node *head2)
{
    if (head2 == NULL)
    {
        return head1;
    }
    else if (head1 == NULL)
    {
        return head2;
    }
    else
    {
        node *newhead = NULL;
        if (head1->d < head2->d)
        {
            newhead = head1;
            newhead->next = mergetwosortedll(head1->next, head2);
            return newhead;
        }
        else
        {
            newhead = head2;
            newhead->next = mergetwosortedll(head1, head2->next);
            return newhead;
        }
    }
}
node *mergesort(node *head)
{

    if (head == NULL)
    {
        return head;
    }
    if (head->next == NULL)
    {
        return head;
    }

    node *m = midpointofll(head);
    node *temp = m->next;
    m->next = NULL;
    head = mergesort(head);
    temp = mergesort(temp);

    node *newhead = mergetwosortedll(head, temp);
    return newhead;
}
int main()
{

    node *head = NULL;
    node *tail = NULL;
    // node *head2 = NULL;
    // node *tail2 = NULL;

    insertatfront(head, tail, 16);
    insertatfront(head, tail, 4);
    insertatfront(head, tail, 9);
    insertatfront(head, tail, 1);

    node *newh = mergesort(head);

    printll(newh);
    cout << endl;

    // insertatfront(head2, tail2, 8);
    // insertatfront(head2, tail2, 3);
    // insertatfront(head2, tail2, 2);

    // printll(head2);
    // cout << endl;

    // node *newh = mergetwosortedll(head1, head2);
    // printll(newh);
    // cout << endl;
}