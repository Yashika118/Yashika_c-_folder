#include <bits/stdc++.h>
using namespace std;
// template<typename T,typename S>
// T-->int and S-->string
class node
{
public:
    string fruitname;
    int price;
    node *next;

    node(int p, string f)
    {
        price = p;
        fruitname = f;
        next = NULL;
    }
};

class Hashmap
{
    node **arr;
    int cs;
    int ts;

public:
    Hashmap(int s = 7)
    { // s-->size
        arr = new node *[s];
        for (int i = 0; i < s; i++)
        {
            arr[i] = NULL;
        }
        cs = 0;
        ts = s;
    }

    int hashfunction(string fn)
    {
        int ans = 0;
        int mult = 1;

        for (int i = 0; fn[i] != '\0'; i++)
        {
            ans = ans + (fn[i] % ts * mult % ts) % ts;
            mult = (mult * 29) % ts;
        }
        return ans % ts;

        // property of mode(%)
        // (a+b)%c=a%c + b%c
        // (a*b)%c=(a%c * b%c)%c
    }

    void rehashing()
    {
        node **oldarr = arr;
        int oldts = ts;
        arr = new node *[2 * ts];
        ts = 2 * ts;
        cs = 0;

        for (int i = 0; i < ts; i++)
        {
            arr[i] = NULL;
        }

        // iterate krna h over the old arr
        // and put oldarr elements in new arr
        for (int i = 0; i < oldts; i++)
        {
            node *head = oldarr[i];
            while (head != NULL)
            {
                insert(head->fruitname, head->price);
                head = head->next;
            }
        }

        // delete[] arrayname;
        delete[] oldarr;
    }

    // insertion
    void insert(string fn, int pr)
    {
        int index = hashfunction(fn);
        node *n = new node(pr, fn);
        n->next = arr[index];
        arr[index] = n;
        cs++;

        if (cs / (ts * 1.0) > 0.6)
        {
            rehashing();
        }
    }

    // print hashmap
    void printhm()
    {
        for (int i = 0; i < ts; i++)
        {
            cout << i << " : ";

            node *head = arr[i];

            while (head != NULL)
            {
                cout << "(" << head->fruitname << "," << head->price << "), ";
                head = head->next;
            }
            cout << endl;
        }
    }

    // search
    bool search(string s)
    {
        int index = hashfunction(s);
        node *head = arr[index];
        while (head != NULL)
        {

            if (head->fruitname == s)
            {
                return true;
            }
            head = head->next;
        }
        return false;
    }
};
int main()
{
    Hashmap h;
    h.insert("Apple", 1300);
    h.insert("kiw", 2190);
    h.insert("kiwi", 2490);
    h.insert("mango", 8940);
    h.insert("banana", 130);
    h.insert("orange", 720);
    h.insert("leechi", 200);
    h.insert("grapes", 2990);

    h.printhm();

    if (h.search("kiwi"))
    {
        cout << "present" << endl;
    }
    else
    {
        cout << "not present" << endl;
    }

    return 0;
}