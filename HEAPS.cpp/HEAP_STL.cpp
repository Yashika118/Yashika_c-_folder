#include <iostream>
#include <queue>
using namespace std;
int main()
{

    // priority_queue<int> h;  // gives max heap by default (in descending order)
    priority_queue<int, vector<int>, greater<int>> h; // gives min heap; (ascending order)
    // vector<int>, greater<int>  --> comparator
    h.push(36);
    h.push(7);
    h.push(25);
    h.push(100);
    h.push(2);

    while (!h.empty())
    {
        cout << h.top() << " ";
        h.pop();
    }

    cout << endl;
}