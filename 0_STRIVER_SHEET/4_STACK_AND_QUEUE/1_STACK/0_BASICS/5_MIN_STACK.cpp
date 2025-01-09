#include<bits/stdc++.h>
using namespace std;

class MinStack {
    stack<pair<int,int>>st;
public:
    MinStack() {

    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val,val});
        }
        else{
            st.push({val,min(val,st.top().second)});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
    // TC:O(1)
    // SC:O(2N) BECAUSE WE STORE PAIRS
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


// APPROACH 2
class MinStack {
    stack<long long>st;
    long long mini;
public:
    MinStack() {
        while (st.empty() == false) st.pop();
        mini=INT_MAX;
    }
    
    void push(int val) {
        long long value=(long long)val;
        if(st.empty()){
            mini=value;
            st.push(value);
        }
        else{
            if(value>mini) st.push(value);
            else{
                // 2*val-mini=new_mini;
                st.push(2*value*1LL-mini);
                mini=value;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long x=st.top();
        st.pop();

        if(x<mini){
            // it means it is a modified value
            // previous_mini=2*mini-x
            mini=2*mini-x;
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        long long x=st.top();
        if(mini<x) return x;
        return mini;
    }
    
    int getMin() {
        return mini;    
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */