#include <bits/stdc++.h>
using namespace std;
class student
{
    string name;

public:
    // below these attributes are called DATA MEMBERS of class
    // string name;
    int age;
    bool gender;

    // void setname(string s)
    // {
    //     name = s;
    // }
    // void getname()
    // {
    //     cout << name << endl;
    // }

    void printinfo()
    {
        cout << "Name = ";
        cout << name << endl;
        cout << "Age = ";
        cout << age << endl;
        cout << "Gender = ";
        cout << gender << endl;
    }

    // parameterised constructor call
    student(string s, int a, bool g)
    {
        cout << "parameterised constructor is called" << endl;
        name = s;
        age = a;
        gender = g;
    }

    // default constructor
    student()
    {
        cout << "default constructor is called" << endl;
    }

    // default copy constructor
    student(student &a)
    {
        cout << "copy constructor is called" << endl;
        name = a.name;
        age = a.age;
        gender = a.gender;
    }

    // destructor
    ~student()
    {
        cout << "destructor is called" << endl;
    }

    // overloading operator
    bool operator==(student &a)
    {
        if (name == a.name, age == a.age, gender == a.gender)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    // student a;
    // student b;
    // student c;
    // student d;
    // student e;

    // a.name='yashika';
    // a.age=20;
    // a.gender=1;

    // student arr[3];
    // for (int i = 0; i < 3; i++)
    // {
    //     string s;   //-->when name is private
    //     cin >> s;
    //     arr[i].setname(s);
    //     // cin >> arr[i].name;
    //     cin >> arr[i].age;
    //     cin >> arr[i].gender;
    // }

    // // call for print
    // for (int i = 0; i < 3; i++)
    // {
    //     arr[i].printinfo();
    // }

    // // input when our name is private
    // for (int i = 0; i < 3; i++)
    // {
    //     string s;
    //     cout << "Name = ";
    //     cin >> s;
    //     arr[i].setname(s);  //-->name private h toh func use kiya h
    //     cout << "Age = ";
    //     cin >> arr[i].age; //-->public h
    //     cout << "Gender = ";
    //     cin >> arr[i].gender;
    // }

    // // print names only
    // for (int i = 0; i < 3; i++)
    // {
    //     arr[i].getname();
    // }

    student a("khushi", 20, 1);
    student b("disha", 17, 1);
    student c("mishti", 7, 1);

    // a.printinfo();
    // b.printinfo();
    // c.printinfo();

    student d; //-> default constructor ka obj h

    student e = a; // copy constructor

    if (e == a)
    { // overload
        cout << "same" << endl;
    }
    else
    {
        cout << "not same" << endl;
    }
}