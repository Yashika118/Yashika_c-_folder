// STACK --> LIFO (LAST IN FIRST OUT)
// QUEUE --> FIFO (FIRST IN FIRST OUT)

#include <bits/stdc++.h>
using namespace std;

class MyStack
{
private:
    int arr[1000];
    int top;

public:
    MyStack()
    {
        top = -1;
    }

    void push(int x)
    {
        if (top >= 1000)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        top = top + 1;
        arr[top] = x;
    } // o(1)

    int pop()
    {
        if (top == -1)
        {
            return -1;
        }
        int ele = arr[top];
        top = top - 1;
        return ele;
    } // o(1)

    int peek()
    {
        if (top == -1)
            return 0;
        return arr[top];
    } // o(1)

    int size()
    {
        return top + 1;
    } // o(1)

    bool empty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    } // o(1)
};

// TC:O(1);
// SC:O(1000) -->CONSTANT

int main()
{
    MyStack st;
    st.push(4);
    st.push(2);
    st.push(1);
    st.push(8);
    st.push(25);
    st.push(31);
    st.pop();
    st.push(5);

    cout << st.size() << endl;
    while (!st.empty())
    {
        cout << st.peek() << " ";
        st.pop();
    }
    cout << endl;
}
