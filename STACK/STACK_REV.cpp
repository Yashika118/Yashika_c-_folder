// #include <iostream>
// #include <vector>
// using namespace std;
// class Stack
// {
//     vector<int> v;

// public:
//     // push
//     void push(int d)
//     {
//         v.push_back(d);
//     }

//     // pop
//     void pop()
//     {
//         v.pop_back();
//     }

//     // size
//     int size()
//     {
//         return v.size();
//     }

//     // top
//     int top()
//     {
//         return v[v.size() - 1];
//     }

//     // empty
//     bool empty()
//     {
//         return v.size() == 0;
//     }
// };
// int main()
// {
//     Stack s;
//     s.push(2);
//     s.push(3);
//     s.push(6);
//     s.push(7);
//     s.push(9);
//     s.pop();

//     while (!s.empty())
//     {
//         cout << s.top() << " ";
//         s.pop();
//     }
//     cout << endl;
//     // cout << s.top();
// }

#include <iostream>
#include <vector>
using namespace std;
// template<typename U>
class Stack
{
    vector<int> v;

public:
    // push
    void push(int data)
    {
        v.push_back(data);
    }

    // pop
    void pop()
    {
        v.pop_back();
    }

    // top
    int top()
    {
        return v[v.size() - 1];
    }

    // size
    int size()
    {
        return v.size();
    }

    // empty
    bool empty()
    {
        if (v.size() == 0)
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
    s.push(4);
    s.push(5);
    s.push(6);
    s.pop();

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

// #include <iostream>
// using namespace std;
// class node
// {

// public:
//     int data;
//     node *next;

//     node(int d)
//     {
//         data = d;
//         next = NULL;
//     }
// };

// class Stack
// {
// public:
//     node *head;
//     int len;

//     Stack()
//     {
//         head = NULL;
//         len = 0;
//     }
//     // push
//     // insertatfront

//     void push(int d)
//     {
//         node *n = new node(d);

//         n->next = head;
//         head = n;
//         len++;
//     }

//     // pop
//     void pop()
//     {
//         if (head == NULL)
//         {
//             return;
//         }
//         else if (head->next == NULL)
//         {
//             delete head;
//             head = NULL;
//             len--;
//         }
//         else
//         {
//             node *temp = head;
//             head = head->next;
//             delete temp;
//             temp = NULL;
//             len--;
//         }
//     }

//     // top
//     int top()
//     {
//         return head->data;
//     }

//     // size
//     int size()
//     {
//         return len;
//     }

//     // empty
//     bool empty()
//     {
//         if (len == 0)
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }
// };
// int main()
// {
//     Stack s;
//     s.push(5);
//     s.push(9);
//     s.push(8);
//     s.push(7);
//     s.push(4);
//     s.push(2);

//     while (!s.empty())
//     {
//         cout << s.top() << " ";
//         s.pop();
//     }

//     return 0;
// }