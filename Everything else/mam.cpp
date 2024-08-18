// #include <iostream>
// using namespace std;
// class node
// {
// public:
//     int data;
//     node *next;
//     node(int d)
//     {
//         data = d;
//         next = NULL;
//     }
// };
// void insertathead(node *&head, node *&tail, int d)
// {
//     node *n = new node(d);
//     if (head == NULL)
//     {

//         head = n;
//         tail = n;
//     }
//     else
//     {
//         n->next = head;
//         head = n;
//     }
// }
// void insertattail(node *&head, node *&tail, int d)
// {
//     node *n = new node(d);
//     if (head == NULL)
//     {
//         head = n;
//         tail = n;
//     }
//     else
//     {
//         tail->next = n;
//         tail = n;
//     }
// }

// int lengthll(node *head)
// {
//     node *temp = head;
//     int count = 0;
//     while (1)
//     {
//         temp = temp->next;
//         if (temp == NULL)
//         {
//             break;
//         }
//         count++;
//     }
//     return count;
// }
// void printll(node *head)
// {
//     node *temp = head;
//     while (1)
//     {
//         cout << temp->data << "->";
//         temp = temp->next;
//         if (temp == NULL)
//         {
//             break;
//         }
//     }
// }
// node *mergetwosortedll(node *head1, node *head2)
// {
//     // case 1 LL1 empty
//     if (head1 == NULL)
//     {
//         return head2;
//     }
//     // case 2 LL2 empty
//     else if (head2 == NULL)
//     {
//         return head1;
//     }
//     else
//     {
//         node *newhead = NULL;
//         if (head1->data < head2->data)
//         {
//             newhead = head1;
//             newhead->next = mergetwosortedll(head1->next, head2);
//         }
//         else
//         {
//             newhead = head2;
//             newhead->next = mergetwosortedll(head1, head2->next);
//         }
//         return newhead;
//     }
// }
// int main()
// {
//     node *head1 = NULL;
//     node *tail1 = NULL;

//     node *head2 = NULL;
//     node *tail2 = NULL;

//     insertattail(head1, tail1, 2);
//     insertattail(head1, tail1, 3);
//     insertattail(head1, tail1, 4);
//     insertattail(head1, tail1, 5);

//     insertattail(head2, tail2, 7);
//     insertattail(head2, tail2, 8);
//     insertattail(head2, tail2, 9);

//     node *newhead = mergetwosortedll(head1, head2);
//     printll(newhead);

//     return 0;
// }

// #include <iostream>
// using namespace std;
// class node
// {
// public:
//     int d;
//     node *next;
//     node(int data)
//     {
//         d = data;
//         next = NULL;
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
//         n->next = head;
//         head = n;
//     }
// }
// void printll(node *head)
// {
//     node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->d << " ";
//         temp = temp->next;
//     }
// }
// int lengthofll(node *head)
// {
//     node *temp = head;
//     int count = 0;

//     while (temp != NULL)
//     {
//         count++;
//         temp = temp->next;
//     }
//     return count;
// }

// void reversell(node *head, int length)
// {
//     int len = length;
//     node *temp1 = head;
//     node *temp2 = head;

//     for (int i = 0; i < len / 2; i++)
//     {
//         temp2 = head;
//         for (int jump = 1; jump <= length - 1; jump++)
//         {
//             temp2 = temp2->next;
//         }

//         swap(temp1->d, temp2->d);
//         temp1 = temp1->next;
//         length--;
//     }
// }
// int main()
// {
//     node *head = NULL;
//     node *tail = NULL;

//     int n, data;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> data;
//         insertatfront(head, tail, data);
//     }

//     // printll(head);
//     // cout << endl;

//     int length = lengthofll(head);
//     // int len = length;
//     cout << "lenth of ll is " << length;
//     cout << endl;

//     reversell(head, length);
//     printll(head);
//      cout << endl;
// }

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
void insertattail(node *&head, node *&tail, int data)
{
    node *N = new node(data);
    if (head == NULL)
    {
        head = N;
        tail = N;
    }
    else
    {
        tail->next = N;
        tail = N;
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
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}
void oddevenll(node *head)
{
    node *temp = head;

    int arr[10000];
    // int num = 0;
    int i = 0;

    // MODIFIED LINKED LIST
    temp = head;
    // num = 0;

    while (temp != NULL)
    {
        // num++;
        if (((temp->d) % 2) != 0)
        { // odd
            arr[i] = temp->d;
            i++;
        }
        temp = temp->next;
    }
    temp = head;
    // num = 0;
    while (temp != NULL)
    {
        // num++;
        if (((temp->d) % 2) == 0)
        { // even
            arr[i] = temp->d;
            i++;
        }
        temp = temp->next;
    }
    // cout << "Modified List: ";
    for (int i = 0; i < lengthofll(head); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    node *head = NULL;
    node *tail = NULL;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        insertattail(head, tail, data);
    }

    // cout << "Original List: ";
    // printll(head);
    // cout << endl;

    oddevenll(head);
}
