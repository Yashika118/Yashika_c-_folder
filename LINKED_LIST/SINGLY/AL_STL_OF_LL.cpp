#include <iostream>
#include <list>
using namespace std;
int main()
{
    // list<datatype>name;
    list<int> l;
    l.push_back(5);
    l.push_back(15);
    l.push_back(50);
    l.push_back(75);
    l.push_back(98);

    cout << l.front() << endl;
    cout << l.back() << endl;

    cout << l.size() << endl;

    list<int>::iterator it = l.begin();
    l.insert(it, 2);
    cout << l.front() << endl;

    advance(it, 3); // it=it+3
    l.insert(it, 27);
    cout << endl;
    cout << "linked list is : ";

    for (it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    l.pop_back();
    l.pop_front();

    for (it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    l.reverse();

    for (it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}