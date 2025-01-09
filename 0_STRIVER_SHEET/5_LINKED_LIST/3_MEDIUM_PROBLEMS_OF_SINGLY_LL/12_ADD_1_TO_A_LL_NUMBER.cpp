#include <bits/stdc++.h>
using namespace std;



struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};



class Solution {
  public:
    Node*reversell(Node*&head){
        Node*temp=head;
        Node*prev=NULL;
        
        while(temp!=NULL){
            Node*front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        head=reversell(head);
        int carry=1; Node*temp=head;
        
        while(temp!=NULL){
            temp->data = temp->data+carry;
            
            if(temp->data<10){
                carry=0;
                break;
            }
            else{
                temp->data=0;
                carry=1;
            }
            
            temp=temp->next;
        }
        
        head=reversell(head);
        
        if(carry==1){
            Node*n=new Node(1);
            n->next=head;
            head=n;
        }
        
        
        return head;
    }
    // TC:O(3N)
    // SC:O(1)
};


// OPTIMAL RECURSIVE SOL

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    int add1InNumer(Node*&temp){
        
        if(temp==NULL){
            return 1;
        }
        
        
        int carry=add1InNumer(temp->next);
        temp->data=temp->data+carry;
        if(temp->data <10){
            return 0;
        }
       
        temp->data=0;
        return 1;
       
        
    }
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        int carry=add1InNumer(head);
        if(carry==1){
            Node*n=new Node(1);
            n->next=head;
            head=n;
        }
        
        return head;
    }
};
