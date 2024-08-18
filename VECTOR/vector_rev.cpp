// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
//     vector<int> b(5, 10);
//     vector<int> d{1, 2, 3, 4, 5};
//     vector<int> c(b.begin(), b.end());

//     for (int i = 0; i < b.size(); i++)
//     {
//         cout << b[i] << " ";
//     }
//     cout << endl;

//     for (int i = 0; i < c.size(); i++)
//     {
//         cout << c[i] << " ";
//     }

//     cout << endl;

//     for (auto x : d)
//     {
//         cout << x << " ";
//     }

//     cout << endl;

//     // vector<int> v;
//     // int n;
//     // cin >> n;
//     // for (int i = 0; i < n; i++)
//     // {
//     //     int num;
//     //     cin >> num;
//     //     v.push_back(num);
//     // }
//     // for (auto x : v)
//     // {
//     //     cout << x << " ";
//     // }
//     // cout << endl;
//     // cout << "size " << v.size() << endl;
//     // cout << "capacity " << v.capacity() << endl;
//     // cout << "max_size " << v.max_size() << endl;

//     // v.pop_back();
//     // for (auto x : v)
//     // {
//     //     cout << x << " ";
//     // }

//     d.insert(d.begin() + 3, 4, 100);
//     for (auto x : d)
//     {
//         cout << x << " ";
//     }
//     cout << endl;

//     d.erase(d.begin() + 2);
//     for (auto x : d)
//     {
//         cout << x << " ";
//     }
//     cout << endl;

//     d.resize(15);
//     cout << d.capacity() << endl;

//     d.clear();
//     cout << d.size() << endl;

//     d.push_back(10);
//     d.push_back(9);
//     d.push_back(11);
//     cout << d.front() << endl;
//     cout << d.back() << endl;

//     vector<int> v;
//     v.reserve(1000);
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         int num;
//         cin >> num;
//         v.push_back(num);
//         cout << "changing capacity " << v.capacity() << endl;
//     }
//     cout << "final capacity " << v.capacity() << endl;

//     for (auto x : v)
//     {
//         cout << x << " ";
//     }
//     cout << endl;
// };

// VECTORS ALGORITHM

class vector
{
    int cs;
    int ms;
    int *arr;

public:
    vector()
    {
        cs = 0;
        ms = 1;
        arr = new int[ms];
    }

    void push_back(int data)
    {
        if (cs == ms)
        { //-->arr is full
            int *oldarr = arr;
            arr = new int[2 * ms];
            ms = 2 * ms;

            for (int i = 0; i < cs; i++)
            {
                arr[i] = oldarr[i];
            }
            delete[] oldarr;
        }
        arr[cs] = data;
        cs++;
    }

    void pop_back()
    {
        cs--;
    }

    int front() const
    {
        return arr[0];
    }

    int back() const
    {
        return arr[cs - 1];
    }

    int capacity() const
    {
        return ms;
    }

    int operator[](const int i)
    {
        return arr[i];
    }
};