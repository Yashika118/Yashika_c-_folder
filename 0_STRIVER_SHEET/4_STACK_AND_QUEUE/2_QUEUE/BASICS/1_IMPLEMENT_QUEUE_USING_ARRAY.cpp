#include<bits/stdc++.h>
using namespace std;

class Queue{
    int arr[10];
    int start,end,currSize,maxSize;
    public:
        Queue(){
            start=end=-1;
            currSize=0;
            maxSize=10;
        }

        void push(int x){

            if(currSize==maxSize){
                cout<<"queue is full"<<endl;
                return;
            }
            if(currSize==0){
                start=end=0;
            }
            else{
                end=(end+1)%maxSize;
            }

            arr[end]=x;
            currSize++;
        }

        void pop(){
            if(currSize==0){
                cout<<"queue is empty"<<endl;
                return;
            }
            int ele=arr[start];
            if(currSize==1){
                start=end=-1;
            }
            else{
                start=(start+1)%maxSize;
            }

            currSize--;
            cout<<"You popped the element "<<ele<<endl;
            return;

        }

        int top(){
            if(currSize==0){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            return arr[start];
        }

        int size(){
            return currSize;
        }

        void print(){
            for(int i=0;i<10;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

        // TC:O(1)
        // SC:O(10)  -->CONSTANT

};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);

    q.print();

    q.push(11);

    q.pop();
    q.pop();
    q.pop();

    q.push(11);

    q.print();
    cout<<q.size()<<endl;

}