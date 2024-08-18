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
bool cycleispresentornot(node *head)
{ // agr ll infinite chl rha h toh cycle present h
    node *slow = head;
    node *fast = head;
    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}
void createacycle(node *head, node *tail)
{
    tail->next = head->next->next;
}
void breakcycle(node *head)
{
    // pehle check krenge ki cycle present h ki nhi tbhi  break krenge
    node *prev = NULL;
    node *slow = head;
    node *fast = head;
    while (fast != NULL and fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
    slow = head;
    while (slow != fast)
    {
        prev = prev->next;
        slow = slow->next;
        fast = fast->next;
    }
    prev->next = NULL;
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

    createacycle(head, tail);
    breakcycle(head);

    // if (cycleispresentornot(head) == true)
    // {
    //     cout << "cycle is present" << endl;
    // }
    // else
    // {
    //     cout << "cycle is not present" << endl;
    // }

    printll(head);
    cout << endl;
}