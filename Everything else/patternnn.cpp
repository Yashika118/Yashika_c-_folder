#include <iostream>
using namespace std;
int main()
{

    int n;
    int row;
    int space;
    int countstar;
    cin >> n;

    row = 1;
    space = 1;
    while (space <= n - 1)
    {
        cout << ' ';
        space = space + 1;
    }
    countstar = 1;
    while (countstar <= n)
    {
        cout << '*';
        countstar = countstar + 1;
    }
    cout << endl;

    row = row + 1;
    while (row <= n - 1)
    {
        space = 1;
        while (space <= n - row)
        {
            cout << " ";
            space = space + 1;
        }
        cout << '*';

        space = 1;
        while (space <= n - 2)
        {
            cout << ' ';
            space = space + 1;
        }
        cout << '*' << endl;

        row = row + 1;
    }

    row = row + 1;
    countstar = 1;
    while (countstar <= n)
    {
        cout << '*';
        countstar = countstar + 1;
    }
    cout << endl;
}

// MAGIC PATTERN;

// #include<iostream>
// using namespace std;
// int main(){

// int row;
// int n;
// int countstar;

// cin>>n;
// row=1;
// countstar=1;
// while(countstar<=n){
//     cout<<'*';
//     countstar=countstar+1;
// }

// cout<<endl;

// int a=5;
// row=row+1;
// countstar=1;
// while(countstar<=n-a){
//     cout<<'*';
//     countstar=countstar+1;
// }
// int space=1;
// while(space<=(n-(2*countstar))){
//     cout<<'#';
//     // countstar=countstar-1;
//      space=space+2;
//     }
// }
// while(space<row){
//     cout<<' ';
//     space=space+1;

// row=row+1;
// while(countstar<=n-a){
//     cout<<'*';
//     countstar=countstar+1;
// }
