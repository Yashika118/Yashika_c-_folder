#include <iostream>
using namespace std;
class node
{
public:
    int data;
    int *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

class Queue
{
public:
    node *head;
    node *tail;

    Queue()
    {
        head = NULL;
        tail = NULL;
    }
    // push
    push(int d)
    {
    }

    // pop

    // front

    // empty

    // size
};

int main()
{

    // Queue q;
    Queue a;
    a.push(1);

    return 0;
}