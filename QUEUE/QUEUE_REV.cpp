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
class Queue
{
    node *head;
    node *tail;
    int len;

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
        len = 0;
    }
    // push
    void push(int d)
    {
        node *n = new node(d);

        if (head == NULL)
        {
            head = n;
            tail = n;
            len++;
            return;
        }
        else
        {
            tail->next = n;
            tail = n;
            len++;
        }
    }
    // pop
    void pop()
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
            len--;
        }
        else
        {
            node *temp = head;
            head = head->next;
            delete temp;
            temp = NULL;
            len--;
        }
    }

    // front
    int front()
    {
        if (len != 0)
        {
            return head->data;
        }
    }

    // empty
    bool empty()
    {
        if (len == 0)
        {
            return true;
        }
        return false;
    }

    // size
    int size()
    {
        return len;
    }
};

int main()
{
    Queue a;
    a.push(2);
    a.push(9);
    a.push(5);
    a.push(7);
    a.push(4);
    a.pop();

    while (!a.empty())
    {
        cout << a.front() << " ";
        a.pop();
    }
};