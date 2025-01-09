#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*,int>mp;
        ListNode*temp1=headA;
        ListNode*temp2=headB;

        while(temp1!=NULL){
            mp[temp1]=1;
            temp1=temp1->next;
        }

        while(temp2!=NULL){
            if(mp.find(temp2)!=mp.end()){
                return temp2;
            }else{
                mp[temp2]=1;
            }
            temp2=temp2->next;
        }

        return NULL;
    }
    // TC:O(N + N*LOGN)
    // SC:O(N)
};



// BETTER

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*t1=headA;  int l1=0;
        ListNode*t2=headB;  int l2=0;
        while(t1!=NULL){
           l1++;
           t1=t1->next;
        }
        while(t2!=NULL){
           l2++;
           t2=t2->next;
        }

        int diff=abs(l1-l2);
        ListNode*temp1=headA;
        ListNode*temp2=headB;
        while(l2>l1){
            temp2=temp2->next;
            l2--;
        }
        while(l1>l2){
            temp1=temp1->next;
            l1--;
        }

        while(temp1!=NULL and temp2!=NULL){
            if(temp1==temp2){
                return temp1;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return NULL;
    }
    // TC:O(4N)
    // SC:O(1)
};



// OPTIMAL SOL
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;

        ListNode*t1=headA;
        ListNode*t2=headB;

        while(t1!=t2){
            t1=t1->next;
            t2=t2->next;

            if(t1==t2) return t1;

            if(t1==NULL) t1=headB;
            if(t2==NULL) t2=headA;
        }

        return t1;
    }
    // TC:O(N1+N2)
    // SC:O(1)
};