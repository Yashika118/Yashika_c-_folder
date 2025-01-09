#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node*next;

    Node(int new_data)
    {
        data = new_data;
        next=NULL;
    }
};

class Queue{
    public:
    Node*start=NULL;
    Node*end=NULL;
    int Size=0;

    void push(int x){
        Node*temp=new Node(x);

        if(start==NULL){
            start=temp;
            end=temp;
            
        }
        else{
            end->next=temp;
            end=temp;
        }
        Size++;
    }

    void pop(){
        int ele=-1;
        if(start==NULL){
            cout<<"queue is empty"<<endl;
            return;
        }
        else{
            Node*temp=start;
            ele=start->data;
            start=start->next;
            delete temp;
        }
        Size--;
    }

    int top(){
        if(start==NULL){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return start->data;
    }

    int size(){
        return Size;
    }

    bool empty(){
        if(Size==0) return true;
        return false;
    }

    void print(){
        Node*i=start;
        while(i!=NULL){
            cout<<i->data<<" ";
            i=i->next;
        }
        cout<<endl;
    }
    // TC:O(1)
    // SC: DYNAMIC
};

int main(){
    Queue q;
    q.push(6);
    q.push(2);
    q.push(4);
    q.push(3);
    q.push(1);

    q.print();
    cout<<q.size()<<endl;

    q.pop();
    q.print();

    q.pop();
    q.print();

   
}