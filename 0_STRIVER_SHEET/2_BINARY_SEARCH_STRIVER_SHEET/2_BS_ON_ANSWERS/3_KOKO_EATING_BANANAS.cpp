// linear search
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double kokoEatBanana(vector<int>& piles,int h){
        sort(piles.begin(),piles.end());
        double k=0;
        for(int i=1;i<=piles[piles.size()-1];i++){
            double tot_hr=0;
            for(int p=0;p<piles.size();p++){
                double a=piles[p],b=i;
                double hr=ceil(a/b);
                tot_hr+=hr;
            }
            if(tot_hr <= h){
                k=i;
                break;
            }
        }

        return k;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        return kokoEatBanana(piles,h);
        
    }
};


// binary search
class Solution {
public:
    int kokoEatBanana(vector<int>& piles,int h){
        sort(piles.begin(),piles.end());
        int n=piles.size();
        int low=0; int high=piles[n-1];
        int k=0;
        while(low<=high){

            int mid=(low+high)/2;
            double tot_hr=0;

            for(int p=0;p<piles.size();p++){
                double a=piles[p], b=mid;
                double hr=ceil(a/b);
                tot_hr+=hr;
            }

            if(tot_hr <= h){
                k=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
            
        }

        return k;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        return kokoEatBanana(piles,h);
        
    }
};


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int maxBananaPerHr=INT_MIN;
        for(int i=0;i<n;i++){
            maxBananaPerHr=max(maxBananaPerHr,piles[i]);
        }

        int low=1;
        int high=maxBananaPerHr;
        int k=0;

        while(low<=high){
            int mid=(low+high)/2;
            double tot_hr=0;

            for(int i=0;i<n;i++){
                 double a=piles[i];
                 double b=mid;
                 double hr=ceil(a/b);
                 tot_hr+=hr;
            }
            if(tot_hr<=h){
                k=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            
        }

        return k;
    }
};