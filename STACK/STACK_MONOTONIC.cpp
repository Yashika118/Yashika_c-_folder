#include <iostream>   //shift+alt+v(niche wala arrow)
#include <vector>
using namespace std;
vector<int> justbiggeronright(vector<int> v)
{
    vector<int> ans(v.size(), 0);
    int i, j;

    for (int i = v.size() - 1; i >= 0; i--)
    {
        for (int j = i + 1; j <= v.size(); j++)
        {
            if (j == v.size())
            {
                ans[i] = -1;
                break;
            }

            if (v[i] < v[j])
            {
                ans[i] = j;
                break;
            }
        }
    }

    return ans;
}

vector<int> justsmalleronleft(vector<int> v)
{
    vector<int> ans(v.size(), 0); // 2 5 4 1 3 7
                                  // -1
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i - 1; j >= -1; j--)
        {

            if (j == -1)
            {
                ans[i] = -1;
                break;
            }

            if (v[j] < v[i])
            {
                ans[i] = j;
                break;
            }
        }
    }

    return ans;
}
void printvector(vector<int> v)
{
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    int num;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    // vector<int> ansvector = justbiggeronright(v);
    vector<int> ansvector = justsmalleronleft(v);
    printvector(ansvector);
}
