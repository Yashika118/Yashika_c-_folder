#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE
bool ls(vector<int>&a , int num){
    for(int i=0;i<a.size();i++){
        if(a[i]==num){
            return true;
        }
    }
    return false;
}
int longestSuccessiveElements(vector<int>&a) {
    // Write your code here.
    int n=a.size();
    int max_len=1;

    for(int i=0;i<n;i++){
        int x=a[i];
        int len=1;
        
        while(ls(a,x+1) ==true){
            x=x+1;
            len++;
        }
        max_len=max(max_len,len);
    }
    return max_len;
    // TC:O(N^2)
}


// BETTER
int longestSuccessiveElements(vector<int>&a) {
    // Write your code here.
    int n=a.size();
    int maxlen=1;
    int lastSmallest=INT_MIN;
    int count=0;

    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if( a[i]-1 == lastSmallest ){
            count++;
            lastSmallest=a[i];
        }
        else if( a[i] != lastSmallest ){
            count=1;
            lastSmallest=a[i];
        }

        maxlen=max(maxlen,count); 
    }

    return maxlen;

    // TC: O(n log n) + O(n)
}


// OPTIMAL SOLUTION
int longestSuccessiveElements(vector<int>&a) {
    // Write your code here.
    int n=a.size();
    if(n==0) return 0;
    int maxlen=1;

    unordered_set<int>st;
    // TC: O(1) --> AVERAGE CASE ,   O(N)--> WORST CASE

    for(int i=0;i<n;i++){   // TC:O(N)
        st.insert(a[i]);
    }

    for(auto it:st){        // TC:O(2N)
        if(st.find(it-1)== st.end()){   // if it-1 not found
            int cnt=1;
            int x=it;

            while(st.find(x+1) != st.end()){    // if x+1 found
                x=x+1;
                cnt++;
            } 
            maxlen=max(maxlen,cnt);
        }
    }

    // TC: O(N)+O(2N) = O(3N)
    // SC:O(N)
    return maxlen;
}