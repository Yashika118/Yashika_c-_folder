#include<bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     int divide(int dividend, int divisor) {
//         long sum=0; long cnt=0;
//         while(sum+divisor <= dividend){
//             sum=sum+divisor;
//             cnt=cnt+1;
//         }

//         return cnt;

//         // TC: O(dividend) --> THIS GIVES TLE
//         // INTERVIEWER WILL NOT HAPPY WITH THIS   
//     }
// };

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;

        bool sign=true;
        if(dividend>=0 and divisor<0){
            sign=false;
        }
        if(dividend<0 and divisor>0){
            sign=false;
        }

        long divid=abs(dividend); long divis=abs(divisor);
        long ans=0;

        while(divid >= divis){   // log (base 2) N
            int cnt=0;
            while(divid >= (divis << (cnt+1))){    // divis << cnt == divis * 2^(cnt+1))      log (base 2) N   
                cnt++;
            }
            ans+=(1 << cnt);   // 1 << cnt == 2^cnt
            divid=divid-(divis << cnt);
        }
        if(ans== (1<<31) and sign==true) return INT_MAX;
        if(ans== (1<<31) and sign==false) return INT_MIN;
        return sign ? ans : (-1 * ans);

        // TC: O(log (base 2) N)^2
        // SC: O(1)
    }
};