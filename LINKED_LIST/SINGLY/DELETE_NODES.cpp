// Q. DELETE NODES -LL
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
        tail = NULL;
    }
    else
    {
        node *temp = head;
        for (int jump = 1; jump <= lengthofll(head) - 2; jump++)
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
    else if (position >= lengthofll(head) - 1)
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
void deletesmallerno(node *&head, node *&tail)
{
    node *temp1 = head;
    node *temp2 = head->next;
    node *temp3 = head;

    while (temp2 != NULL || temp2->next->next != NULL)
    {
        if (temp1->d < temp2->d)
        {
            node *a = temp1;
            if (temp1 == head)
            {
                temp3 = temp3->next;
            }
            else
            {

                temp3->next = a->next;
                temp3 = temp3->next->next;
            }
            temp1 = temp1->next->next;
            delete a;
            a = NULL;
        }
        else
        {
            temp1 = temp1->next->next;
        }

        // if (temp1->next->next == NULL || temp1->next == NULL)
        // {
        //     break;
        // }

        temp2 = temp2->next->next;
        // temp3=temp3->next->next;
    }
}
int main()
{
    node *head = NULL;
    node *tail = NULL;
    int data;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> data;
        insertattail(head, tail, data);
    }

    lengthofll(head);

    deletesmallerno(head, tail);
    printll(head);
}