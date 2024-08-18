// Q. REVERSE A SINGLY LINKED LIST
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

void reversell(node *head, int length)
{
    int len = length;
    int leng = (len / 2);
    node *temp1 = head;

    while (length != leng)
    {
        node *temp2 = head;
        for (int jump = 1; jump <= length - 1; jump++)
        {
            temp2 = temp2->next;
        }

        swap(temp1->d, temp2->d);
        temp1 = temp1->next;
        length--;
    }
}
int main()
{
    node *head = NULL;
    node *tail = NULL;

    int N, data;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> data;
        // insertatfront(head, tail, data);
        insertattail(head, tail, data);
    }

    // printll(head);
    // cout << endl;

    int length = lengthofll(head);
    // cout << "lenth of ll is " << length;
    // cout << endl;

    reversell(head, length);
    printll(head);
    cout << endl;
}