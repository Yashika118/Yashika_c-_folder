// #include <iostream>
// using namespace std;
// class node
// {
// public:
//     int d;
//     node *f;
//     node *b;
//     node(int data)
//     {
//         d = data;
//         f = NULL;
//         b = NULL;
//     }
// };
// void insertatfront(node *&head, node *&tail, int data)
// {
//     node *n = new node(data);
//     if (head == NULL)
//     {
//         head = n;
//         tail = n;
//     }
//     else
//     {
//         n->f = head;
//         head->b = n;
//         head = n;
//     }
// }
// void printll(node *head)
// {
//     node *temp = head;

//     while (temp != NULL)
//     {
//         cout << temp->d << " ";
//         // temp = temp->f;
//         temp = temp->b;
//     }
// }

// int main()
// {
//     node *head = NULL;
//     node *tail = NULL;

//     insertatfront(head, tail, 4);
//     insertatfront(head, tail, 13);
//     insertatfront(head, tail, 7);
//     insertatfront(head, tail, 12);
//     // // printll(head);
//     // // cout<<endl;
//     printll(tail);

// }

// CYCLIC LINKED LIST
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
bool cycleispresentornot(node *head)
{
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
    // tail->next = head->next->next;

    // to create cycle at any pos
    int position;
    cin >> position;
    node *temp = head;

    for (int jump = 1; jump <= position - 1; jump++)
    {
        temp = temp->next;
    }
    tail->next = temp;
}
void breakcycle(node *head)
{
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

int kthnodefromend(node *head, int k)
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
        insertatfront(head, tail, data);
    }

    printll(head);
    cout << endl;
    // createacycle(head, tail);

    // if (cycleispresentornot(head) == true)
    // {
    //     cout << "cycle is present" << endl;
    // }
    // else
    // {
    //     cout << "cycle is not present" << endl;
    // }

    // // printll(head);

    // breakcycle(head);
    // printll(head);

    cout << kthnodefromend(head, 1) << endl;
}