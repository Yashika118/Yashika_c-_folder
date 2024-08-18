// // USING VECTOR
// #include <iostream>
// #include <vector>
// using namespace std;

// class Queue
// {
// public:
//     vector<int> v;

//     // push
//     void push(int data)
//     {
//         v.push_back(data);
//     }

//     // pop
//     void pop()
//     {
//         if (!v.empty())
//         {
//             v.erase(v.begin());
//         }
//         return;
//     }

//     // front
//     int front()
//     {
//         if (!v.empty())
//         {
//             return v[0];
//         }
//         return 0;
//     }

//     // empty
//     bool empty()
//     {
//         if (v.size() == 0)
//         {
//             return true;
//         }
//         return false;
//     }

//     // size
//     int size()
//     {
//         return v.size();
//     }
// };
// int main()
// {
//     Queue q;
//     q.push(5);
//     q.push(4);
//     q.push(6);
//     q.push(7);
//     q.push(9);

//     cout << q.front() << endl;

//     cout << q.size() << endl;

//     if (q.empty())
//     {
//         cout << "yes" << endl;
//     }
//     else
//     {
//         cout << "No" << endl;
//     }

//     // while (!q.empty())
//     // {
//     //     cout << q.front() << " ";
//     //     q.pop();
//     // }
//     // cout << endl;
// }

// USING LINKED LIST
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
    // insertattail
    void push(int d)
    {
        node *n = new node(d);

        if (head == NULL)
        {
            // ll khali hai
            head = n;
            tail = n;
            len++;
        }
        else
        {
            tail->next = n;
            tail = n;
            len++;
        }
    }
    // pop
    // deleteatfront
    void pop()
    {
        // agr ll khali hai
        if (head == NULL)
        {
            return;
        }
        // single node hai
        else if (head->next == NULL)
        {
            delete head;
            head = NULL;
            tail = NULL;
            len--;
        }
        // multiple nodes
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

    // size
    int size()
    {
        return len;
    }

    // empty
    bool empty()
    {
        // if(len==0){
        //     return true;
        // }
        // else{
        //     return false;
        // }

        // if(len==0){
        //     return true;
        // }
        //     return false;

        // if(head==NULL){
        //     return true;
        // }
        // else{
        //     return false;
        // }

        return len == 0;
        // return head==NULL;
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
    cout << endl;
}

// // USING ARRAY
// #include <iostream>
// using namespace std;
// class Queue
// {
//     int *arr;
//     int f;  // front
//     int r;  // rear
//     int cs; // current size
//     int ts; // total size
// public:
//     Queue(int s)
//     { // s-->size of arr
//         arr = new int[s];
//         ts = s;
//         cs = 0;
//         f = 0;
//         // r=-1;       //-->ye bhi kr skte hai
//         r = s - 1;
//     }

//     // push
//     void push(int d)
//     {
//         if (cs < ts)
//         {
//             r = (r + 1) % ts;
//             arr[r] = d;
//             cs++;
//         }
//         else
//         {
//             cout << "overflow" << endl;
//         }
//     }

//     // pop
//     void pop()
//     {
//         if (cs > 0)
//         {
//             f = (f + 1) % ts;
//             cs--;
//         }
//         else
//         {
//             cout << "underflow" << endl;
//         }
//     }

//     // front
//     int front()
//     {
//         return arr[f];
//     }

//     // empty
//     bool empty()
//     {
//         return cs == 0;
//     }
//     // size
//     int size()
//     {
//         return cs;
//     }
// };
// int main()
// {
//     Queue a(5);
//     a.push(1);
//     a.push(2);
//     a.push(3);
//     a.push(4);
//     a.push(5);
//     a.push(6);

//     a.pop();
//     a.pop();
//     a.pop();
//     a.pop();
//     a.pop();

//     a.push(6);
//     a.push(6);
//     a.push(6);

//     while (!a.empty())
//     {
//         cout << a.front() << " ";
//         a.pop();
//     }
// }