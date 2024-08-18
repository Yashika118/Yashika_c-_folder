// Q1.  delete from linked list (Q Queries)
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
    node *N = new node(data);
    // ll is empty
    if (head == NULL)
    {
        head = N;
        tail = N;
    }
    // ll is not empty
    else
    {
        tail->next = N;
        tail = N;
    }
}
void deleteatpos(node *&head, node *&tail, int n, int position)
{
    node *temp = head;
    if (position == 0)
    {
        temp = head;
        head = head->next;
        delete temp;
        temp = NULL;
    }
    else if (position >= (n - 1))
    {
        node *temp = head;
        for (int jump = 1; jump <= position - 1; jump++)
        {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
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
void printll(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->d << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int n; // n-->no. of nodes
    int q; // q-->no. of queries
    cin >> n >> q;
    node *head = NULL;
    node *tail = NULL;

    int arr[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int pos[100];
    for (int p = 0; p < q; p++)
    {
        cin >> pos[p];
    }

    for (int i = 0; i < n; i++)
    {
        insertatback(head, tail, arr[i]);
    };

    for (int p = 0; p < q; p++)
    {
        deleteatpos(head, tail, n, pos[p]);
        printll(head);
        cout << endl;
    };

    // insertatback(head, tail, 2);
    // insertatback(head, tail, 4);

    // deleteatpos(head,tail,n,4);

    // printll(head);
}
