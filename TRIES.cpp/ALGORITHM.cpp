// LS-64
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    char data;
    bool isterminal;
    // unordered_map<key type,value type>name of map;
    unordered_map<char, node *> h;
    node(char ch)
    {
        data = ch;
        isterminal = false;
    }
};
class trie
{
    node *root;

public:
    trie()
    {
        root = new node('\0');
    }
    // insert
    void insert(char *arr)
    {
        node *temp = root;
        for (int i = 0; arr[i] != '\0'; i++)
        {

            char ch = arr[i];
            if (temp->h.count(ch))
            {
                // char present hai
                temp = temp->h[ch];
            }
            else
            {
                // char present nahi h
                temp->h[ch] = new node(ch);
                temp = temp->h[ch];
            }
        }
        temp->isterminal = true;
    }

    // search in tries
    bool search(char *arr) //"cat"
    {
        node *temp = root;
        for (int i = 0; arr[i] != '\0'; i++)
        {

            char ch = arr[i]; //'c'
            if (temp->h.count(ch))
            {
                // ch is present h
                temp = temp->h[ch];
            }
            else
            {
                // present nhi h
                return false;
            }
        }
        return temp->isterminal;
    }
};
int main()
{
    trie t;
    // char arr[] = "cat";
    t.insert("cat");
    t.insert("cate");
    t.insert("hello");
    t.insert("hell");
    if (t.search("hell"))
    {
        cout << "present" << endl;
    }
    else
    {
        cout << "not present" << endl;
    }

    // vector<string>words={"ayush","ayushi","daasi"};
    // for(auto w:words){
    //     t->insert(w);
    // }
    // if(t->search("ayush")){
    //     cout<<"YES"<<endl;
    // }
    // else{
    //     cout<<"NO"<<endl;
    // }
}