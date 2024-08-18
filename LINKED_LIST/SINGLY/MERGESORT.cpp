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

    node *N = new node(data);
    if (head == NULL)
    {
        head = N;
        tail = N;
    }
    else
    {
        N->next = head;
        head = N;
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
node *midpointofll(node *head)
{
    node *slow = head;
    node *fast = head->next;
    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
node *mergetwosortedarr(node *head1, node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    else if (head2 == NULL)
    {
        return head1;
    }
    else
    {
        node *newhead = NULL;
        if (head1->d < head2->d)
        {
            newhead = head1;
            newhead->next = mergetwosortedarr(head1->next, head2);
            // return newhead;
        }
        else
        {
            newhead = head2;
            newhead->next = mergetwosortedarr(head1, head2->next);
            // return newhead;
        }
        return newhead;
    }
}
node *mergesort(node *&head)
{
    // base case
    if (head == NULL)
    {
        return head;
    }
    else if (head->next == NULL)
    {
        return head;
    }

    // recursive case
    node *m = midpointofll(head);
    node *temp = m->next;
    m->next = NULL;
    node *h = mergesort(head);
    node *t = mergesort(temp);
    node *newhead = mergetwosortedarr(h, t);
    return newhead;
}
int main()
{
    // int n, arr[10000];
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }

    // node *head = NULL;
    // node *tail = NULL;

    // for (int i = 0; i < n; i++)
    // {
    //     insertatfront(head, tail, arr[i]);
    // }

    // insertatfront(head, tail, 6);
    // insertatfront(head, tail, 15);
    // insertatfront(head, tail, 12);
    // insertatfront(head, tail, 19);
    // insertatfront(head, tail, 23);
    // printll(head);
    // cout << endl;
    // cout << "mid point of ll : " << midpointofll(head) << endl;

    // merge two sorted ll
    node *head1 = NULL;
    node *tail1 = NULL;
    node *head2 = NULL;
    node *tail2 = NULL;
    // insertatfront(head1, tail1, 3);
    // insertatfront(head1, tail1, 2);
    // insertatfront(head1, tail1, 1);
    // insertatfront(head2, tail2, 5);
    // insertatfront(head2, tail2, 4);

    // node *newhead = mergetwosortedarr(head1, head2);
    // printll(newhead);
    // cout << endl;

    // merge sort
    insertatfront(head1, tail1, 13);
    insertatfront(head1, tail1, 22);
    insertatfront(head1, tail1, 12);
    insertatfront(head1, tail1, 53);
    insertatfront(head1, tail1, 14);
    node *newh = mergesort(head1);
    printll(newh);
    cout << endl;

    return 0;
}
