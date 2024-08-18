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
    // head!=NULL
    else
    {
        n->next = head;
        head = n;
    }
}
void insertatback(node *&head, node *&tail, int data)
{
    node *n = new node(data);
    // if ll is empty
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
// int lengthofll(node *head)
// {
//     int count = 0;
//     node *temp = head;

//     while (temp != NULL)
//     {
//         count++;
//         temp = temp->next;
//     }
//     return count;
// }
int lengthofllrec(node *head)
{
    // base case
    if (head == NULL)
    {
        return 0;
    }

    // recursive case
    return 1 + lengthofllrec(head->next);
}
void insertatanypos(node *&head, node *&tail, int data, int position)
{
    if (position == 0)
    {
        insertatfront(head, tail, data);
    }
    else if (position >= lengthofllrec(head))
    {
        insertatback(head, tail, data);
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

void printll(node *head)
{

    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->d << " ";
        temp = temp->next;
    }
    cout << endl;
}

int midpointinll(node *head)
{
    node *slow = head;
    // node *fast = head; // even ke case m 2nd wala mid point deta h
    node *fast = head->next; // even ke case m 1st wala mid point deta h

    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->d;
}

int main()
{
    node *head = NULL;
    node *tail = NULL;

    int key;
    cin >> key;

    insertatfront(head, tail, 4);
    insertatfront(head, tail, 8);
    insertatback(head, tail, 18);
    insertatback(head, tail, 92);
    insertatback(head, tail, 25);

    // printll(head);

    insertatanypos(head, tail, 7, 3);

    printll(head);
    cout << lengthofllrec(head) << endl;

    

    cout << midpointinll(head) << endl;

    

    
}

