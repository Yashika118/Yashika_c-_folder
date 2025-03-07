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
