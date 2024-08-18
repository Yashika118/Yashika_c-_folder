#include <iostream>
#include <vector>
using namespace std;
template <typename U>
class Stack
{
    // vector<int> v;
    vector<U> v;

public:
    // vector<int> v;

    // push
    void push(U d)
    {
        v.push_back(d);
    }

    // pop
    void pop()
    {
        v.pop_back();
    }

    // top
    U top()
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
    Stack<char> s;
    s.push('A');
    s.push('B');
    s.push('C');
    s.push('D');
    s.push('E');
    s.push('F');
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