#include <iostream>
#include <vector>
using namespace std;
template <typename U>
class Stack
{
    vector<U> v;

public:
    // push
    void push(U data)
    {
        v.push_back(data);
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
    U size()
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
    // Stack<int> s;
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // s.push(5);
    // s.push(6);
    // s.pop();
    Stack<char> s;
    s.push('A');
    s.push('B');
    s.push('C');
    s.push('D');
    s.push('E');
    s.pop();

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}