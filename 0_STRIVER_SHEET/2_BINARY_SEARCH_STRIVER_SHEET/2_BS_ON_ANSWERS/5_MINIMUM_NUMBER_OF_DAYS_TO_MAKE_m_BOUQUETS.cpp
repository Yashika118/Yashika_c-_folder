// BRUTE FORCE // MY SOLUTION
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dayExist(vector<int>& bloomDay,int day,int m,int k){
        int n=bloomDay.size();
        int count=0;
        for(int i=0;i<n;){ //0
            cout<<"i"<<i<<endl;
            if(bloomDay[i]<=day){ //7
                for(int j=0;j<k;j++){
                    cout<<"j"<<j<<endl;
                    if(i+j<n and bloomDay[i+j]<=day){
                        if(j==k-1){
                            cout<<"yes"<<endl;
                            count+=1;
                            i=i+j+1;
                        }
                    }else{
                        i=i+j+1;
                        break;
                    }
                }

            }
            else{
                i++;
            }
        }
        if(count<m) return 0;
        return 1;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans=0;

        int var=*max_element(bloomDay.begin(),bloomDay.end());
        for(int day=1;day<=var;day++){
            cout<<"day : "<<day<<endl;
            if(dayExist(bloomDay,day,m,k)){
                ans=day;
                return day;
            }
        } 

        return -1;  
    }
};



// BRUTE FORCE STRIVER SOL
class Solution {
public:
    bool possible(vector<int>& bloomDay,int day,int m,int k){
        int n=bloomDay.size();
        int count=0; int noOfBouq=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=day){
                count++;
            }else{
                noOfBouq+=count/k;
                count=0;
            }
        }
        noOfBouq+=count/k;
        if(noOfBouq>=m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        vector<int>arr=bloomDay;
        int n=arr.size();

        if(n < (m*k)) return -1;

        sort(arr.begin(),arr.end());
        int mini=arr[0];
        int maxi=arr[n-1];
        for(int i=mini;i<=maxi;i++){
            if(possible(bloomDay,i,m,k)) return i;
            
        }
        return -1;
    }
};


// BINARY SEARCH
class Solution {
public:
    bool dayExist(vector<int>& bloomDay,int day,int m,int k){
        int n=bloomDay.size();
        int count=0;
        for(int i=0;i<n;){ //0
            // cout<<"i"<<i<<endl;
            if(count>=m) return 1;
            if(bloomDay[i]<=day){ //7
                for(int j=0;j<k;j++){
                    // cout<<"j"<<j<<endl;
                    if(i+j<n and bloomDay[i+j]<=day){
                        if(j==k-1){
                            // cout<<"yes"<<endl;
                            count+=1;
                            i=i+j+1;
                        }
                    }else{
                        i=i+j+1;
                        break;
                    }
                }

            }
            else{
                i++;
            }
        }
        if(count<m) return 0;
        return 1;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((n/2) <( m/2 *k/2 ) )return -1;

        int var=*max_element(bloomDay.begin(),bloomDay.end());
        int low=1; int high=var; int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(dayExist(bloomDay,mid,m,k)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        return ans;  
    }
};


class Solution {
public:
    bool isBloomOrNot(vector<int>& bloomDay,int m,int k,int currDay){
        int n=bloomDay.size();
        int numBouques=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=currDay){
                // bloomed
                int kk=k;
                int numFlowers=0;
                for(int j=i;kk--;j++){
                    if(j==n){
                        break;
                    }
                    if(bloomDay[j]<=currDay){
                        numFlowers++;
                        // cout<<numFlowers<<endl;
                    }
                    else{
                        i=j;
                        break;
                    }
                }
                if(numFlowers==k){
                    numBouques++;
                    // cout<<numBouques<<endl;
                    i=i+k-1;
                }
            }
        }
        if(numBouques>=m){
            return true;
        }
        return false;

    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int maxBloomDay=INT_MIN;
        for(int i=0;i<n;i++){
            maxBloomDay=max(maxBloomDay,bloomDay[i]);
        }
        
        int low=1;
        int high=maxBloomDay;
        int ans=-1;

        while(low<=high){
            int mid=(low+high)/2;
            cout<<mid<<endl;
            if(isBloomOrNot(bloomDay,m,k,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
        // isBloomOrNot(bloomDay,m,k,1000000000);
        // return -1;
    }
};
