// LS-65
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    vector<Node *> arr;
    bool word_end;

    Node()
    {
        arr.resize(26, NULL);
        word_end = false;
    }

    // for more optimise solution k liye
    bool contains(char ch)
    {
        return arr[ch - 'a'] != NULL;
    }

    void insert(char ch, Node *node)
    {
        arr[ch - 'a'] = node;
    }

    Node *next(char ch)
    {
        return arr[ch - 'a'];
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    // insert
    void insertintrie(string s)
    {
        Node *temp = root;

        for (auto ch : s)
        {
            if (temp->arr[ch - 'a'] == NULL)
            {
                temp->arr[ch - 'a'] = new Node();
            }
            temp = temp->arr[ch - 'a'];
        }
        temp->word_end = true;

        // more optimisise solution
        // Node *temp = root;
        // for (auto ch : s)
        // {
        //     if (!temp->contains(ch))
        //     {
        //         temp->insert(ch, new Node());
        //     }
        //     temp = temp->next(ch);
        // }
        // temp->word_end = true;
    }

    bool doeswordexist(string word)
    {
        Node *temp = root;
        for (auto ch : word)
        {
            if (temp->contains(ch) == false)
            {
                return false;
            }
            temp = temp->next(ch);
        }
        return temp->word_end;
    }
};
int main()
{
    Trie obj;
    string s;
    cin >> s;

    obj.insertintrie(s);

    // obj.insertintrie("hell");
    // obj.insertintrie("bac");

    // for search
    string word;
    cin >> word;
    cout << obj.doeswordexist(word);
}