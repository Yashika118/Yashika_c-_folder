// STACK USING VECTOR
#include <iostream>
#include <vector>
using namespace std;
class Stack
{
    vector<char> v;

public:
    // push
    void push(char d)
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
    char top()
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
    cout << endl;
}
