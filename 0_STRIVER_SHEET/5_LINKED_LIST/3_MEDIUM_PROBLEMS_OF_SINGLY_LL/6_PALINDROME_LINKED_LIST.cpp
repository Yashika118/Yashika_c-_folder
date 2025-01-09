#include<bits/stdc++.h>
using namespace std;


// BRUTE FORCE

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode*temp=head;
        ListNode*newHead=new ListNode(temp->val);
        ListNode*h=newHead;
        temp=temp->next;
        while(temp!=NULL){
            ListNode*newNode=new ListNode(temp->val);
            h->next=newNode;
            h=newNode;
            temp=temp->next;
        }
        ListNode*temp1=newHead;
        ListNode*prev=NULL;
        while(temp1!=NULL){
            ListNode*front=temp1->next;
            temp1->next=prev;
            prev=temp1;
            temp1=front;
        }
        // ListNode*a=prev;
        // while(a!=NULL){
        //     cout<<a->val<<" ";
        //     a=a->next;
        // }

        ListNode*t1=head;
        ListNode*t2=prev;
        while(t1!=NULL){
            if(t1->val != t2->val){
                return false;
            }
            t1=t1->next;
            t2=t2->next;
        }
        return true;
        
    }
    // TC:O(3N)
    // SC:O(N)
};



// BETTER SOL

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int>st;
        ListNode*temp=head;
        while(temp!=NULL){
            st.push(temp->val);
            temp=temp->next;
        }
        ListNode*temp1=head;
        while(temp1!=NULL){
            if(temp1->val==st.top()){
                st.pop();
                temp1=temp1->next;
            }
            else{
                return false;
            }
        }
        return true;
    }
    // TC:O(2N)
    // SC:O(N)
};


// OPTIMAL SOL
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode*reversell(ListNode*head){
        ListNode*temp=head;
        ListNode*prev=NULL;
        while(temp!=NULL){
            ListNode*front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast->next!=NULL and fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        slow->next=reversell(slow->next);

        // ListNode*a=head;
        // while(a!=NULL){
        //     cout<<a->val<<" ";
        //     a=a->next;
        // }

        ListNode*t1=head;
        ListNode*t2=slow->next;
        while(t2!=NULL){
            if(t1->val!=t2->val){
            
                return false;
            }
            t1=t1->next;
            t2=t2->next;
        }
        
        return true;
    }
    // TC:O(N/2)+O(N/2)+O(N/2)
    // SC:O(1)
};