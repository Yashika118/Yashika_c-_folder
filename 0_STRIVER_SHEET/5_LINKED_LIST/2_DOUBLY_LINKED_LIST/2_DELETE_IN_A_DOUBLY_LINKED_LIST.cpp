//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Solution {
  public:
    // Function to delete a node at given position.
    void deleteAtAnyPosition(Node*&head,int x){
        Node*temp=head;
        for(int jump=1;jump<x;jump++){
            temp=temp->next;
        }
        Node*b=temp->prev;
        temp->prev=NULL;
        temp->next->prev=b;
        b->next=temp->next;
        temp->next=NULL;
        delete temp;
    }
    void deleteAtEnd(Node*&head){
        Node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        Node*backward=temp->prev;
        backward->next=NULL;
        temp->prev=NULL;
        delete temp;
    }
    void deleteAtFront(Node*&head){
        Node*temp=head;
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        delete temp;
    }
    int lengthOfll(Node*head){
        int cnt=0;
        Node*temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    Node* deleteNode(Node* head, int x) {
        // Your code here
        int len=lengthOfll(head);
        
        if(x==1){
            deleteAtFront(head);
        }
        else if(x>=len){
            deleteAtEnd(head);
        }
        else{
            deleteAtAnyPosition(head,x);
        }
        
        return head;
    }
};

