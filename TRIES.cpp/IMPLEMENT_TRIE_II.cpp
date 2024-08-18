// LS-65
// CODING NINJA
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    vector<Node *> arr;
    int word_count;
    int prefix_count;

    Node()
    {
        arr.resize(26, NULL);
        word_count = 0;
        prefix_count = 0;
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

    void insert(string &word)
    {
        Node *temp = root;
        for (auto ch : word)
        {
            if (temp->arr[ch - 'a'] == NULL)
            {
                temp->arr[ch - 'a'] = new Node();
            }
            temp = temp->arr[ch - 'a'];
            temp->prefix_count++;
        }
        temp->word_count++;
    }

    int countWordsEqualTo(string &word)
    {
        Node *temp = root;
        for (auto ch : word)
        {
            if (temp->arr[ch - 'a'] == NULL)
            {
                return 0;
            }
            temp = temp->arr[ch - 'a'];
        }
        return temp->word_count++;
    }

    int countWordsStartingWith(string &word)
    {
        Node *temp = root;
        for (auto ch : word)
        {
            if (temp->arr[ch - 'a'] == NULL)
            {
                return 0;
            }
            temp = temp->arr[ch - 'a'];
        }
        return temp->prefix_count++;
    }

    void erase(string &word)
    {
        Node *temp = root;
        for (auto ch : word)
        {
            if (temp->arr[ch - 'a'] == NULL)
            {
                temp->arr[ch - 'a'] = new Node();
            }
            temp = temp->arr[ch - 'a'];
            temp->prefix_count--;
        }
        temp->word_count--;
    }
};
