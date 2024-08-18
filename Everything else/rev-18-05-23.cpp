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
void insertatback(node *&head, node *&tail, int data)
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
// int lenoflinkedlist(node*head){
//     node*temp=head;
//     int count=0;
//     while(temp!=NULL){
//         count++;
//         temp=temp->next;
//     }
//     return count;
// }

int lenofllrec(node *head)
{
    // base case
    if (head == NULL)
    {
        return 0;
    }

    // recursive case
    return 1 + lenofllrec(head->next);
}
void insertatanypos(node *&head, node *&tail, int data, int position)
{
    if (position == 0)
    {
        insertatfront(head, tail, data);
    }
    else if (position >= lenofllrec(head))
    {
        insertatback(head, tail, data);
    }
    else
    {
        node *temp = head;
        node *n = new node(data);
        for (int jump = 1; jump <= position - 1; jump++)
        {
            temp = temp->next;
            n->next = temp->next;
            temp->next = n;
        }
    }
}
void deleteatfront(node *&head, node *&tail)
{
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
void deleteatback(node *&head, node *&tail)
{
    if (head == NULL)
    {
        return;
    }
    else if (head->next == NULL)
    {
        delete head;
        head = NULL;
        tail == NULL;
    }
    else
    {
        node *temp = head;
        for (int jump = 1; jump <= lenofllrec(head) - 2; jump++)
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
    else if (position >= lenofllrec(head))
    {
        deleteatback(head, tail);
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
node *midpointinll(node *head)
{
    node *slow = head;
    node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
void bubblesortinll(node *head)
{
    for (int i = 0; i <= lenofllrec(head) - 2; i++)
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
node *mergetwosortedll(node *&head1, node *&head2)
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
node *mergesortinll(node *head)
{
    if (head == NULL)
    {
        return head;
    }
    if (head->next == NULL)
    {
        return head;
    }

    node *m = midpointinll(head);
    node *temp = m->next;
    m->next = NULL;
    node *h = mergesortinll(head);
    node *t = mergesortinll(temp);

    node *newhead = mergetwosortedll(h, t);
    return newhead;
}
void printll(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->d << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    node *head = NULL;
    node *tail = NULL;

    // insertatfront(head, tail, 8);
    // insertatfront(head, tail, 4);
    // insertatfront(head, tail, 6);
    // insertatfront(head, tail, 2);
    // insertatfront(head, tail, 3);
    // insertatfront(head, tail, 9);
    // deleteatanypos(head, tail, 4);
    // printll(head);
    // cout << endl;
    // cout << midpointinll(head) << endl;
    // bubblesortinll(head);
    // printll(head);
    // cout << endl;

    // // merge two sorted ll
    // node *head1 = NULL;
    // node *tail1 = NULL;
    // node *head2 = NULL;
    // node *tail2 = NULL;

    // insertatfront(head1, tail1, 18);
    // insertatfront(head1, tail1, 8);
    // insertatfront(head1, tail1, 4);
    // insertatback(head1, tail1, 25);
    // insertatback(head2, tail2, 10);
    // insertatback(head2, tail2, 12);
    // insertatback(head2, tail2, 32);

    // node *newll = mergetwosortedll(head1, head2);
    // printll(newll);
    // cout << endl;

    insertatfront(head, tail, 5);
    insertatfront(head, tail, 3);
    insertatfront(head, tail, 6);
    insertatfront(head, tail, 4);
    insertatfront(head, tail, 2);
    node *newlinkedlist = mergesortinll(head);
    printll(newlinkedlist);
    cout << endl;
};