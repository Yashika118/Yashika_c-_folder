#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};
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
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
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
void reversell(node *&head)
{
    node *temp1 = head;
    int length = lengthofll(head);
    int len = (length / 2);

    while (length != len)
    {

        node *temp2 = head;

        for (int jump = 1; jump <= lengthofll(head) - 1; jump++)
        {
            temp2 = temp2->next;
        }
        swap(temp1->data, temp2->data);
        temp1 = temp1->next;
        length--;
    }
}
int main()
{
    node *head;
    node *tail;

    head = NULL;
    tail = NULL;

    int N, data;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> data;
        insertattail(head, tail, data);
    }
    cout << endl;

    printll(head);
    cout << lengthofll(head) << endl;
    reversell(head);
    printll(head);
}