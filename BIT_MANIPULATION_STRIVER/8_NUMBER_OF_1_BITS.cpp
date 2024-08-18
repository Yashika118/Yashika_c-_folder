#include<bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     void func(int n,int &count){
//         int i=0; int num; int temp=31;
//         while(temp--){
//             num=1<<i;
//             if((n & num)!=0){
//                 count++;
//             }
//             i++;
//         }
//     }
//     int hammingWeight(int n) {
//         int count=0;
//         func(n,count);
//         return count;
//     }
// };


class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        while(n>0){
            count++;
            n=n & (n-1);
        }
        return count;
    }
};