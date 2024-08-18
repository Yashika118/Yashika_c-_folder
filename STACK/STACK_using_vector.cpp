#include <iostream>
#include <vector>
using namespace std;
class Stack
{
    vector<int> v;

public:
    // vector<int> v;

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
    // s.pop();
    s.size();
    s.top();
    s.empty();

    // cout << s.v[1] << endl;
    // print stack

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}