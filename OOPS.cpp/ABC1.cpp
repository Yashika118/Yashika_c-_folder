#include <bits/stdc++.h>
using namespace std;
class student
{
    // private: //--> access out side the class
    // private  --> access within a class  (by default)
    // protect  -->
public:
    int age;
    string name;

    // // this is called-->getter and setter functions..
    // void Assign(int a, string n)
    // {

    //     age = a;
    //     name = n;

    //     return;
    // }

    // void print()
    // {
    //     cout << age << " " << name << endl;
    // }

    student(int a, string n) //--> parameterised constructor
    // default constructor is destroyed when we make our own constructor
    {
        age = a;
        name = n;
    }

    // student(int age, string name)
    // {
    //     // this-->used to store address of object, it is a pointer type keyword

    //     this->age = age;
    //     this->name = name;
    // }

    // ~student() -->destructor used when object khtm hota h -->only for static memory
    ~student()
    {
        cout << " destructor is called" << endl;
    }
};
int main()
{
    // static
    // student s1;
    // student s2;
    // student s3 ;

    // dynamic bnana hua toh
    // student *s4 = new student;

    // // static m access kese krenge data
    // cout << s1.age << endl;
    // cout << s1.name << endl;

    // // dynamic m kese access krenge data
    // cout<<(*s4).age<<endl;
    // cout<<(*s4).name<<endl;
    // // short cut
    // cout<<s4->age<<endl;

    // // value assign krni ho toh
    // s1.age=20;

    // s1.Assign(20, "abc");
    // s1.print();

    // CONSTRUCTOR
    // student s1(10, "abc");
    // student s2(s1); //--> synatx of "copy constructor"  -->s1 copy ho jaega s2 mein
    // // it represents to compiler as --> s2.student(student s1)
    // cout << s1.age << " " << s1.name << endl;

    // student *s3 = new student(s1);
    // cout << s3->name << endl;

    // student *s4 = new student(*s3);
    // cout << s4->name << endl;

    // copy assignment operator
    // student s2 = s1;

    // for destructor ko check krne k liye input:
    student s1(10, "yashi");
    student s2(20, "disha"); //-->static mem m constructor call end hota h toh next destructor call hota h

    student *s3 = new student(30, "mihsti");
    delete s3; //--> dynamic memory ko delete kre k baad destructor call hota h vrna nhi hoga destructor call
}