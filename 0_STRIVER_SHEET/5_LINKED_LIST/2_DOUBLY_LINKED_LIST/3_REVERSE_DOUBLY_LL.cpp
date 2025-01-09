#include <bits/stdc++.h>
using namespace std;


// USING STACK

class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
        stack<int>st;
        DLLNode*temp=head;
        while(temp!=NULL){
            st.push(temp->data);
            temp=temp->next;
        }
        DLLNode*temp1=head;
        while(!st.empty()){
            temp1->data=st.top();
            st.pop();
            temp1=temp1->next;
        }
        
        return head;
    }
    // TC:O(2N)
    // SC:O(N)
};

// USING SWAPING THE LINKS
class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
        if(head==NULL || head->next==NULL) return head;
        
        DLLNode*last=NULL;
        DLLNode*current=head;
        while(current!=NULL){
            last=current->prev;
            current->prev=current->next;
            current->next=last;
            current=current->prev;
        }
        return last->prev;
    }
};

// TC:O(N)
// SC:O(1)

