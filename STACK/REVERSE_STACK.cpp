#include <iostream>
#include <stack>
#include <vector>
using namespace std;
void insertatbottom(stack<int> &s, int topelement)
{
    // base case
    if (s.empty())
    {
        s.push(topelement);
        return;
    }

    // recursive case
    int y = s.top();
    s.pop();
    insertatbottom(s, topelement);
    s.push(y);
}
void reversestack(stack<int> &s)
{
    // base case
    if (s.empty())
    {
        return;
    }
    // recursive case
    int topelement = s.top();
    s.pop();
    reversestack(s);
    insertatbottom(s, topelement);
}

void printstack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
int main()
{
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(1);
    s.pop();

    printstack(s);

    reversestack(s);
}
