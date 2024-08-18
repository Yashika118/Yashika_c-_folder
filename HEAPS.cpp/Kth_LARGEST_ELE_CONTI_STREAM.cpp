// kth no.of largest elements in a continous stream before -1
#include <bits/stdc++.h>
using namespace std;
#define minheap priority_queue<int, vector<int>, greater<int>>
void printheap(minheap h)
{ // heaps are pass by val
    while (!h.empty())
    {
        cout << h.top() << " ";
        h.pop();
    }
    cout << endl;
}
int main()
{
    // priority_queue<int, vector<int>, greater<int> >h;
    minheap h;
    int k;
    cin >> k;
    int count = 0;

    int data;

    while (-20)
    {

        cin >> data; // 13 1
        if (data == -1)
        {
            // print heap
            printheap(h);
        }
        else
        {

            if (count < k)
            {
                h.push(data);
                count++;
            }
            else
            {
                if (h.top() < data)
                {
                    h.pop();
                    h.push(data);
                }
            }
        }
    }
}