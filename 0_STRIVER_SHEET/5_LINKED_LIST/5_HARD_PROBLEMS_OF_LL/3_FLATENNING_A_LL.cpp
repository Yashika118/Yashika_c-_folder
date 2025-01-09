#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};


class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node*convertFunc(vector<int>v){
        if(v.size()==0) return NULL;
        Node*head=new Node(v[0]);
        Node*temp=head;
        for(int i=1;i<v.size();i++){
            Node*n=new Node(v[i]);
            temp->bottom=n;
            temp=temp->bottom;
        }
        return head;
    }
    Node *flatten(Node *root) {
        vector<int>v;
        Node*temp=root;
        while(temp!=NULL){
            Node*t2=temp;
            while(t2!=NULL){
                v.push_back(t2->data);
                t2=t2->bottom;
            }
            temp=temp->next;
        }
        
        sort(v.begin(),v.end());
        root=convertFunc(v);
        return root;
    }

    // TC:O( 2*(N*M) + (N*M) LOG (N*M))
    // SC:O(N*M)*2
};


// OPTIMAL SOL
class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node* mergeTwoSortedLL(Node*l1,Node*l2){
        Node*dummy=new Node(-1);
        Node*temp=dummy;
        while(l1!=NULL and l2!=NULL){
            if(l1->data < l2->data){
                temp->bottom=l1;
                temp=temp->bottom;
                l1=l1->bottom;
            }
            else{
                temp->bottom=l2;
                temp=temp->bottom;
                l2=l2->bottom;
            }
            temp->next=NULL;
        }
        if(l1) temp->bottom=l1;
        else temp->bottom=l2;
        return dummy->bottom;
    }
    Node*func(Node*head){
        if(head==NULL || head->next==NULL) return head;
        
        
        Node*mergeHead=func(head->next);
        return mergeTwoSortedLL(head,mergeHead);
        
        
    }
    Node *flatten(Node *root) {
        // Your code here
        Node*head=root;
        
        return func(head);
        
    }
    // TC:O(N*2M)
    // SC:O(N)
};



