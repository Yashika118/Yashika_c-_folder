#include <bits/stdc++.h>
using namespace std;

// // APPROACH 1

// // s1 --> s2
// // x ---> s1
// // s2 ---> s1
// class Queue
// {   public:
//     stack<int> s1;
//     stack<int> s2;

//     void push(int x)
//     {

//         while (!s1.empty())
//         {
//             s2.push(s1.top());
//             s1.pop();
//         }
//         s1.push(x);
//         while(!s2.empty()){
//             s1.push(s2.top());
//             s2.pop();
//         }
//     } //O(2N)

//     void pop(){
//         s1.pop();
//     }
//     int top(){
//         return s1.top();
//     }

//     bool empty(){
//         if(s1.size()==0) return true;
//         return false;
//     }

//     void print(){
//         while(!s1.empty()){
//             cout<<s1.top()<<" ";
//             s1.pop();
//         }
//     }
// };
// // TC:O(2N)
// // SC:O(NO. OF ELE)

// int main(){
//     Queue q;
//     q.push(2);
//     q.push(9);
//     q.push(6);
//     q.push(1);
//     q.push(10);

//     q.pop();
//     cout<<q.top()<<endl;
//     cout<<q.empty()<<endl;

//     q.print();
// }




// APPROACH 2

class Queue
{   public:
    stack<int> s1;
    stack<int> s2;

    void push(int x)
    {
        s1.push(x);   
    } //O(1)

    int pop(){
        int ele=-1;
         if(!s2.empty()){
            ele=s2.top();
            s2.pop();
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            ele=s2.top();
            s2.pop();
        }

        return ele;
    }// O(N)  BECAUSE S1->S2
    int top(){
        if(!s2.empty()){
            return s2.top();
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }// O(N) BEACUSE S1->S2

    bool empty(){
        if(s1.size()==0 and s2.size()==0) return true;
        return false;
    }//O(1)

};

int main(){
    Queue q;
    q.push(2);
    q.push(9);
    q.push(6);
    q.push(1);
    q.push(10);

    q.pop();

    cout<<q.top()<<endl;

    cout<<q.empty()<<endl;

}