#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> a; // infinite size of arr in stl
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    // a.push(6);

    // STL of queue does not give overflow and underflow because of infinite size

    a.pop();
    a.pop();
    a.pop();
    a.pop();
    a.pop();   // empty ho jaega queue
    a.pop();   // segmentation falut dega kyuki kuch hai hi nhi pop krne ko
    a.push(6); // ye print nhi ho kyuki segmentation fault balance ho jaega
    a.push(6); // ye ab print hoga
    // a.push(6);

    while (!a.empty())
    {
        cout << a.front() << " ";
        a.pop();
    }
}