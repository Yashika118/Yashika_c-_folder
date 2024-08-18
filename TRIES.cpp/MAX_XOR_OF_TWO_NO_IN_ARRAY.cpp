// LS-65
// BASIC IDEA : BINARY TRIE
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    vector<Node *> arr;
    Node()
    {
        arr.resize(2, 0);
    }

    bool contains(int bit)
    {
        return arr[bit] != NULL;
    }

    void insert(int bit, Node *node)
    {
        arr[bit] = node;
    }

    Node *next(int bit)
    {
        return arr[bit];
    }
};
class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int no)
    {
        Node *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = ((no >> i) & 1);
            if (!temp->contains(bit))
            {
                temp->insert(bit, new Node());
            }
            temp = temp->next(bit);
        }
    }

    int getans(int no)
    {
        int ans = 0;
        Node *temp = root;

        for (int i = 31; i >= 0; i--)
        {
            int bit = ((no >> i) & 1);
            if (temp->contains(!bit))
            {
                ans = ans | (1 << i);
                temp = temp->next(!bit);
            }
            else
            {
                temp = temp->next(bit);
            }
        }

        return ans;
    }
};
class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        Trie obj;
        for (auto x : nums)
        {
            obj.insert(x);
        }

        int ans = 0;
        for (auto x : nums)
        {
            int val = obj.getans(x);
            ans = max(ans, val);
        }
        return ans;
    }
};
