#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> justbiggeronright(vector<int> v)
{
    stack<int> s;
    vector<int> ans(v.size(), 0);

    for (int i = v.size() - 1; i >= 0; i--)
    {

        if (s.empty())
        {
            ans[i] = -1;
            s.push(i);
        }

        else
        {
            while (v[i] > v[s.top()])
            {
                s.pop();

                if (s.empty())
                {
                    break;
                }
            }

            if (s.empty())
            {
                ans[i] = -1;
                s.push(i);
            }
            else
            {
                ans[i] = s.top();
                s.push(i);
            }
        }
    }

    return ans;
}

vector<int> justsmalleronleft(vector<int> v)
{
    stack<int> s;
    vector<int> ans(v.size(), 0);

    for (int i = 0; i < v.size(); i++)
    {

        if (s.empty())
        {
            ans[i] = -1;
            s.push(i);
        }
        else
        {
            while (v[i] > v[s.top()])
            {
                s.pop();
                if (s.empty())
                {
                    break;
                }
            }
            if (s.empty())
            {
                ans[i] = -1;
                s.push(i);
            }

            else
            {
                ans[i] = s.top();
                s.push(i);
            }
        }
    }

    return ans;
}

void printvector(vector<int> ans)
{
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v;
    v.push_back(17);
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);
    v.push_back(5);
    v.push_back(8);

    vector<int> newans = justbiggeronright(v);
    // vector<int> newans = justsmalleronleft(v);
    printvector(newans);
}