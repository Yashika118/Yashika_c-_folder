#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    queue<int>q;
    int Size=0;

    void push(int x){
        Size++;
        q.push(x);

        for(int i=0;i<Size-1;i++){
            q.push(q.front());
            q.pop();
        }

    }  //O(N)

    int pop(){
        if(q.empty()){
            return -1;
        }
        int ele=q.front();
        Size--;
        q.pop();
        return ele;
    }//O(1)

    int size(){
        return q.size();
    }//O(1)

    int top(){
        return q.front();
    }//O(1)

    bool empty(){
        if(q.empty()) return true;
        return false;
    }//O(1)


    // TC:O(N)
};
int main(){
    Stack st;

    st.push(5);
    st.push(7);
    st.push(3);
    st.push(1);
    st.push(4);
    
    cout<<st.top()<<endl; 
    st.pop();
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }


}