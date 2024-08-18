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

void deleteatfront(node *&head, node *&tail)
{
    // if ll is not present
    if (head == NULL)
    {
        return;
    }

    // single ll is present
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

void deleteattail(node *&head, node *&tail)
{
    // if ll is not present
    if (head == NULL)
    {
        return;
    }

    // single ll is present
    else if (head->next == NULL)
    {
        delete head;
        head = NULL;
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
        deleteattail(head, tail);
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
bool searchinlliteratively(node *head, int key)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->d == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void bubblesort(node *head)
{
    for (int i = 0; i <= lengthofll(head) - 2; i++)
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
int main()
{

    node *head = NULL;
    node *tail = NULL;
    insertatfront(head, tail, 4);
    insertatfront(head, tail, 8);
    insertatfront(head, tail, 18);
    insertattail(head, tail, 30);
    insertatanypos(head, tail, 45, 0);
    insertatanypos(head, tail, 95, 3);
    printll(head);
    cout << endl;
    // cout << lengthofll(head) << endl;
    // deleteatfront(head, tail);
    // deleteattail(head, tail);
    // deleteatanypos(head, tail, 2);
    // printll(head);

    // int key;
    // cin >> key;
    // if (searchinlliteratively(head, key) == true)
    // {
    //     cout << "key is present" << endl;
    // }
    // else
    // {
    //     cout << "key is not present";
    // }

    // cout << midpointofll(head) << endl;
    bubblesort(head);
    printll(head);
}