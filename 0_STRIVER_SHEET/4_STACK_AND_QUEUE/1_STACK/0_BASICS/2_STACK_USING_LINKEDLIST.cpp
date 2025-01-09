#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
        Node(int new_data){
            data=new_data;
            next=NULL;
        }
};

class Stack{
    public:
    Node*top;
    int Size=0;

    void push(int x){
        Node*temp=new Node(x);
        temp->next=top;
        top=temp;
        Size++;
    }

    int pop(){
        if(top==NULL) return -1;
        Node*temp=top;
        top=top->next;
        int ele=temp->data;
        delete temp;
        Size--;
        return ele;
    }
    int peek(){
        return top->data;
    }

    int size(){
        return Size;
    }
    
    bool empty(){
        if(Size==0){
            return true;
        }
        return false;
    }
};

int main(){
    Stack st;
    st.push(6);
    st.push(7);
    st.push(2);
    st.push(4);
    st.push(9);

    st.pop();
    cout<<st.peek()<<endl;
    cout<<"size : "<<st.size()<<endl;

    while(!st.empty()){
        cout<<st.peek()<<" "<<endl;
        st.pop();
    }

    
}