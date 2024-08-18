// LS-65
// CODESTUDIO
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
};

class Trie
{
private:
    Node *root;
    int ans;

public:
    Trie()
    {
        root = new Node();
        ans = 0;
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
                ans++;
            }
            temp = temp->arr[ch - 'a'];
        }
        temp->word_end = true;
    }

    int getans()
    {
        return ans + 1;
    }
};

int countDistinctSubstrings(string &s)
{
    Trie obj;
    for (int i = 0; i < s.length(); i++)
    {
        string str = "";
        for (int j = i; j < s.length(); j++)
        {
            str += s[j];
            obj.insertintrie(str);
        }
    }

    return obj.getans();
}
int main()
{
    string s = "abab";
    cout << countDistinctSubstrings(s) << endl;
}