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
// void insertatback(node *&head, node *&tail, int data)
// {
//     node *n = new node(data);
//     // if ll is empty
//     if (head == NULL)
//     {
//         head = n;
//         tail = n;
//     }
//     // if ll is not empty
//     else
//     {
//         tail->next = n;
//         tail = n;
//     }
// }
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
// void printll(node *head)
// {

//     node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->d << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }
// node *mergetwosortedll(node *head1, node *head2)
// {
//     node *newhead = NULL;
//     if (head1 == NULL)
//     {
//         return head2;
//     }
//     else if (head2 == NULL)
//     {
//         return head1;
//     }
//     else
//     {
//         if (head1->d < head2->d)
//         {
//             newhead = head1;

//             newhead->next = mergetwosortedll(head1->next, head2);
//             return newhead;
//         }
//         else
//         {
//             newhead = head2;
//             newhead->next = mergetwosortedll(head1, head2->next);
//             return newhead;
//         }
//     }
// }
// int main()
// {
//     int T;
//     cin >> T;

//     for(int k=0;k<T;k++){
//     node *head1 = NULL;
//     node *tail1 = NULL;
//     node *head2 = NULL;
//     node *tail2 = NULL;

//     int data1, data2;
//     int N1;
//     cin >> N1;
//     for (int i = 0; i < N1; i++)
//     {
//         cin >> data1;
//         insertatback(head1, tail1, data1);
//     }

//     int N2;
//     cin >> N2;
//     for (int j = 0; j < N2; j++)
//     {
//         cin >> data2;
//         insertatback(head2, tail2, data2);
//     }
//     node *newh = mergetwosortedll(head1, head2);
//     printll(newh);
//     cout << endl;
//     }

// }

// Q.
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
node *mergetwosortedll(node *head1, node *head2)
{
    node *newhead = NULL;
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
int main()
{
    node *head1 = NULL;
    node *tail1 = NULL;
    node *head2 = NULL;
    node *tail2 = NULL;

    int K; // k-->no. of linked ll
    int N;
    cin >> K >> N;

    for (int k = 0; k < K; k++)
    {
        int data1;
        int N1 = N;
        for (int i = 0; i < N1; i++)
        {
            cin >> data1;
            insertatback(head1, tail1, data1);
        }
    }

    node *newh = mergetwosortedll(head1, head2);
    printll(newh);
    cout << endl;
}
