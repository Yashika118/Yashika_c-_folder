#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int lengthofll(ListNode*&head){
        int cnt=0;
        ListNode*temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    ListNode* middleNode(ListNode* head) {
        int len=lengthofll(head);
        int mid=(len/2)+1;
        ListNode*temp=head;
        int cnt=1;

        while(temp!=NULL){
            if(cnt==mid){
                return temp;
            }
            cnt++;
            temp=temp->next;
        }
        return head;
    }
    // TC:O(N+N/2)
    // SC:O(1)
};


// OPTIMAL SOL  --> TORTOISE AND HARE ALGO

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL and fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};