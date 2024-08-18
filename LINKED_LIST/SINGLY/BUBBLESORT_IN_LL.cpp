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
void printll(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->d << " ";
        temp = temp->next;
    }
}
void bubblesortinll(node *head, int N)
{
    for (int i = 0; i < N - 1; i++)
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
    int N;
    int arr[10000];
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    node *head = NULL;
    node *tail = NULL;

    for (int i = 0; i < N; i++)
    {
        insertatfront(head, tail, arr[i]);
    }

    bubblesortinll(head, N);
    printll(head);
}
