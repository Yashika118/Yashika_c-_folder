#include<bits/stdc++.h>
using namespace std;

// if we have to return element of R th row and C th col
// R-1
//    C
//      C-1
//  means n C r = n! / ( r! * (n-r)! )
// if R=5 AND C=3
// THEN 4 C 2 = 4! / ( 2! * (4-2)! ) = 6 -->ans 

// SHORTCUT :
// EX :  10 C 3 = 10*9*8 / 3*2*1 = 10/1 * 9/2 * 8/3   -->just to simply for writing code
// jitni bar base number multiply hoga utni bar numerator m bhi
// Ex : 5 C 2 = 5*4 / 2*1


// EX :  10 C 3 = 10*9*8 / 3*2*1 = 10/1 * 9/2 * 8/3
// in this ex as we saw : 
// 10 = n-0
// 9 = n-1
// 8 = n-2

int NCR(int n, int r){
    int res=1;
    for(int i=0;i<r;i++){
        res=res*(n-i);
        res=res/(i+1);
    }
    return res;
    // TC: O(r)
    // SC : O(1)
}