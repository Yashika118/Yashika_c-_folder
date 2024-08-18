#include <bits/stdc++.h>
using namespace std;
class student
{
public:
    int age;
    // char name[100]; //--> mem waste ho jaegi toh isse dynamicall bnaenge
    char *name;

    student(){

    }

    student(int age, char *name)
    {
        this->age = age;
        // this->name = name;  //-->for shallow copy
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name); //-->for deep copy
    }

    // copy constructor
    student(student const &s1){
        this->age=s1.age;
        this->name=new char[strlen(s1. name) + 1];
        strcpy(this->name, s1.name);
    }




};
int main()
{
    char name[] = "abcd"; // 0 1 2 3
    student s1(10, name); // 900  name= a b c d
    cout << s1.name[1] << endl;
    name[1] = 'z'; // 900     // a z c d
    cout << s1.name[1] << endl;

    // name has address 900 containing a b c d  , after replacing b to z in the same *arr the name again
    // points to the address 900 this is called "shallow copy"
    // shallow copy is done by copy constructor

    // deep copy is: ek new pointer arr bnega name naam ka jiska size pehle wale arr se 1 zyda hoga , isme purane
    // arr ke sare elements ko copy krega aur next char jo dalna h usse dal dega new jgh pe.

    student s2(s1);
    cout << s2.name[1] << endl;
    s2.name[1] = 'x';
    cout << s2.name[1] << endl;
}