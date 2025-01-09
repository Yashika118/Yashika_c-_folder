#include<bits/stdc++.h>
using namespace std;
class StockSpanner {
public:
    vector<int>ans;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        ans.push_back(price);
        int cnt=1;
        for(int i=ans.size()-2;i>=0;i--){
            if(ans[i]<=price) cnt++;
            else break;
        }
        return cnt;
    }
};
// TC:O(NO. OF DAYS)
// SC:O(TOTAL NO. OF NEXT CALLS )
class StockSpanner {
public:
    stack<pair<int,int>>st;
    int ind=-1;
    StockSpanner() {
        ind=-1;
        // st.clear();
    }
    
    int next(int price) {
        ind=ind+1;

        while(!st.empty() and st.top().first<=price){
            st.pop();
        }
        int ans=ind-(st.empty()?-1:st.top().second);
        st.push({price,ind});

        return ans;
    }
    // TC:O(2N)
    // SC:O(N)
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */