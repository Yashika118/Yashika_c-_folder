#include <iostream>
using namespace std;

int main()
{

    string s1 = "CODING  ";
    string s2 = "BLOCKS";
    string s3 = s1 + s2;

    cout << s3 << endl;
    cout << s1.substr(5) << endl;
    cout << s1.substr(3) << endl;
    cout << s1.substr(0, 2) << endl;
}