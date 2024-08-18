// STACK USING VECTOR
#include <iostream>
#include <vector>
using namespace std;
class Stack
{
    vector<int> v;

public:
    // push
    void push(int d)
    {
        v.push_back(d);
    }
    // pop
    void pop()
    {
        v.pop_back();
    }

    // size
    int size()
    {
        return v.size();
    }
    // top
    int top()
    {
        return v[v.size() - 1];
    }

    // empty
    bool empty()
    {
        // if(v.size()==0){
        //     return true;
        // }
        // else{
        //     return false;
        // }

        return v.size() == 0;
    }
};
int main()
{
    Stack s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(1);
    s.pop();

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

// STACK USING LINKED LIST
// #include <iostream>
// #include <vector>
// using namespace std;
// class node
// {
// public:
//     int d;
//     node *next = NULL;
//     node(int data)
//     {
//         d = data;
//         next = NULL;
//     }
// };

// class Stack
// {
//     node *head;
//     int len;

// public:
//     Stack()
//     {
//         head = NULL;
//         len = 0;
//     }

//     // push
//     // insertatfront
//     void push(int data)
//     {
//         node *n = new node(data);
//         n->next = head;
//         head = n;
//         len++;

//         // l.push_front(data);
//     }

//     // pop
//     // deleteatfront
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
//         return head->d;
//     }

//     // size
//     int size()
//     {
//         return len;
//     }

//     // empty
//     bool empty()
//     {
//         // if(head==NULL){
//         //     return true;
//         // }
//         // else{
//         //     return false;
//         // }

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
//     s.push(2);
//     s.push(3);
//     s.push(1);
//     s.push(5);
//     s.push(0);

//     while (!s.empty())
//     {
//         cout << s.top() << " ";
//         s.pop();
//     }

//     cout << endl;
// }