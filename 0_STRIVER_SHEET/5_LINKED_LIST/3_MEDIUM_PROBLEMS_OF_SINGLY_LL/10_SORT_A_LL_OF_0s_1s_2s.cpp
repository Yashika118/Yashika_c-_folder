#include <bits/stdc++.h>
using namespace std;

  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// BRUTE FORCE

class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {

        // Add code here
        Node*temp=head; int cnt0=0; int cnt1=0; int cnt2=0;
        while(temp!=NULL){
            if(temp->data==0) cnt0++;
            else if(temp->data==1) cnt1++;
            else cnt2++;
            temp=temp->next;
        }
        
        Node*temp1=head;
        while(temp1!=NULL){
            if(cnt0 !=0 ) {
                temp1->data=0;
                cnt0--;
                
            }
            else if(cnt1!=0) {
                temp1->data=1;
                cnt1--;
                
            }
            else{
                temp1->data=2;
                cnt2--;
                
            }
            temp1=temp1->next;
        }
        return head;
    }
};


// MY SOLUTION
class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {

        // Add code here
        if(head==NULL || head->next==NULL) return head;
        
        Node*zeroHead=new Node(-1);
        Node*oneHead=new Node(-1);
        Node*twoHead=new Node(-1);
        
        Node*zero=zeroHead;
        Node*one=oneHead;
        Node*two=twoHead;
        
        Node*temp=head;
        
        while(temp!=NULL){
            if(temp->data==0){
                zero->next=temp;
                zero=zero->next;
                temp=temp->next;
                zero->next=NULL;
            }
            else if(temp->data==1){
                one->next=temp;
                one=one->next;
                temp=temp->next;
                one->next=NULL;
            }
            else{
                two->next=temp;
                two=two->next;
                temp=temp->next;
                two->next=NULL;
            }
            // temp=temp->next;
        }
        
        zero->next= oneHead->next ? oneHead->next : twoHead->next;
        one->next=twoHead->next;
        two->next=nullptr;
        return zeroHead->next;
    }
};


// STRIVER SOL

class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {

        // Add code here
        if(head==NULL || head->next==NULL) return head;
        
        Node*zeroHead=new Node(-1);
        Node*oneHead=new Node(-1);
        Node*twoHead=new Node(-1);
        
        Node*zero=zeroHead;
        Node*one=oneHead;
        Node*two=twoHead;
        
        Node*temp=head;
        
        while(temp!=NULL){
            if(temp->data==0){
                zero->next=temp;
                zero=zero->next;
                // zero->next=NULL;
            }
            else if(temp->data==1){
                one->next=temp;
                one=one->next;
                // one->next=NULL;
            }
            else{
                two->next=temp;
                two=two->next;
                // two->next=NULL;
            }
            temp=temp->next;
        }
        
        zero->next= oneHead->next ? oneHead->next : twoHead->next;
        one->next=twoHead->next;
        two->next=nullptr;
        return zeroHead->next;
    }
};


