#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validCapacity(vector<int>& weights,int days,int maxCap){
        int sum=0; int d=1;
        int n=weights.size();
        for(int i=0;i<n;i++){
            if(weights[i]>maxCap){
                // return d;
                // cout<<false<<endl;
                return false;
            }
            sum+=weights[i];
            // cout<<"weigh : "<<weights[i]<<" sum : "<<sum<<endl;
            if(sum>maxCap){
                d++;
                sum=0;
                i=i-1;
            }

        }

        if(d<=days) return true;
        return false;
        // return d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        
        for(int i=1;i<=INT_MAX;i++){
            if(validCapacity(weights,days,i)) return i;
        }
        return 0;
  
    }
};


// BINARY SEARCH
class Solution {
public:
    bool validCapacity(vector<int>& weights,int days,int maxCap){
        int sum=0; int d=1;
        int n=weights.size();
        for(int i=0;i<n;i++){
            if(weights[i]>maxCap){
                // return d;
                // cout<<false<<endl;
                return false;
            }
            sum+=weights[i];
            // cout<<"weigh : "<<weights[i]<<" sum : "<<sum<<endl;
            if(sum>maxCap){
                d++;
                sum=0;
                i=i-1;
            }

        }

        if(d<=days) return true;
        return false;
        // return d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low=1; int high=INT_MAX;
        int ans=0;
        while(low<=high){
            int mid=(low/2)+(high/2);
            if(validCapacity(weights,days,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return ans;
    }
};


class Solution {
public:
    bool check(vector<int>& weights,int days,int currCapacity){
        int n=weights.size();
        int sum=0; int myDay=1;
        for(int i=0;i<n;i++){
            sum+=weights[i];
            if(sum>currCapacity){
                sum=0;
                myDay++;
                i=i-1;
            }
            
        }
        if(myDay>days){
            return false;
        }
        return true;

    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int maxWeight=INT_MIN;
        for(int i=0;i<n;i++){
            maxWeight=max(maxWeight,weights[i]);
        }

        int low=maxWeight;
        int high=INT_MAX;
        int ans=-1;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(check(weights,days,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return ans;
    }
};