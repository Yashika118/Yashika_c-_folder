//  Q. ARRANGE ODD EVEN LINKED LIST
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
    int num = 0;
    int i = 0;

    // MODIFIED LINKED LIST
    temp = head;
    num = 0;

    while (temp != NULL)
    {
        num++;
        if ((num % 2) != 0)
        { // odd
            arr[i] = temp->d;
            i++;
        }
        temp = temp->next;
    }
    temp = head;
    num = 0;
    while (temp != NULL)
    {
        num++;
        if ((num % 2) == 0)
        { // even
            arr[i] = temp->d;
            i++;
        }
        temp = temp->next;
    }
    cout << "Modified List: ";
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

    cout << "Original List: ";
    printll(head);
    cout << endl;

    oddevenll(head);
}
