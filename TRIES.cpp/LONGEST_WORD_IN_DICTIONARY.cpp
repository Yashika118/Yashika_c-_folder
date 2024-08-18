#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    struct Node
    {
        vector<Node *> arr;
        bool word_end;

        Node()
        {
            arr.resize(26, NULL);
            word_end = false;
        }

        Node *contains(char ch)
        {
            return arr[ch - 'a'];
        }
        Node *get(char ch)
        {
            return arr[ch - 'a'];
        }
    };
    class Trie
    {
        Node *root;
        int len;

    public:
        Trie()
        {
            root = new Node();
        }
        // insert
        void insert(string s)
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
        }

        bool iscomplete(string element)
        {
            Node *temp = root;
            int n = element.size();
            for (int i = 0; i < n; i++)
            {
                temp = temp->get(element[i]);
                if (temp->word_end == false)
                {
                    return false;
                }
            }
            return true;
        }
    };

    string longestWord(vector<string> &words)
    {
        Trie obj;
        for (auto i : words)
        {
            obj.insert(i);
        }

        string ans = "";
        for (auto i : words)
        {
            if (obj.iscomplete(i))
            {
                if (ans.size() < i.size())
                {
                    ans = i;
                }
                if (ans.size() == i.size())
                    ans = min(ans, i);
            }
        }

        return ans;
    }
};
