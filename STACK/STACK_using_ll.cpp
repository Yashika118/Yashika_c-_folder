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

class Stack
{
    node *head;
    int len;

public:
    Stack()
    {
        head = NULL;
        len = 0;
    }

    // push
    void push(int data)
    {
        node *n = new node(data);
        n->next = head;
        head = n;
        len++;
    }

    // pop
    // deleteatfront
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

    // size
    int size()
    {
        return len;
    }

    // top
    int top()
    {
        return head->data;
    }

    // empty
    bool empty()
    {
        if (len == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Stack s;
    s.push(2);
    s.push(3);
    s.push(5);
    s.push(7);
    s.push(6);
    s.pop();
    s.size();
    s.top();
    s.empty();

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}