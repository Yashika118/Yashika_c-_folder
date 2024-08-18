// HEAP SORT ALGORITHM
// LS-50
#include <bits/stdc++.h>
using namespace std;
class Minheap
{
    vector<int> v;

public:
    // heapify is to maintain the heap after deletion
    void heapify(int index)
    {
        int mi = index; // mi-->min index

        int lc = 2 * index;
        int rc = 2 * index + 1;

        if (lc < v.size() and v[mi] > v[lc])
        {
            mi = lc;
        }

        if (rc < v.size() and v[mi] > v[rc])
        {
            mi = rc;
        }

        if (mi != index)
        { // base case
            swap(v[mi], v[index]);
            heapify(mi);
        }
    }

    Minheap()
    {
        v.push_back(-1);
    }

    // insertion
    void insert(int data)
    {
        v.push_back(data);
        int child = v.size() - 1;
        int parent = child / 2;

        while (child > 1 and v[child] < v[parent])
        {
            swap(v[child], v[parent]);
            child = parent;
            parent = child / 2;
        }
    }

    // deletion-->min
    void deleteinheap()
    {
        swap(v[1], v[v.size() - 1]);
        v.pop_back();
        heapify(1);
    }

    // search-->min
    int search()
    {
        return v[1];
    }

    // empty
    bool empty()
    {
        return v.size() == 1;
    }
};
int main()
{
    Minheap h;
    h.insert(2);
    h.insert(1);
    h.insert(3);
    h.insert(17);
    h.insert(19);
    h.insert(36);
    h.insert(7);
    h.insert(25);
    h.insert(100);
    h.deleteinheap();

    while (!h.empty())
    {
        cout << h.search() << " ";
        h.deleteinheap();
    }
    return 0;
}