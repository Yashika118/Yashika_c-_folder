#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE


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
    ListNode* sortList(ListNode* head) {
        ListNode*temp=head;
        vector<int>v;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        } //O(N)
        sort(v.begin(),v.end());  //O(N*LOG N)
        ListNode*temp1=head;
        int i=0;
        while(temp1!=NULL){  // O(N)
            temp1->val=v[i];
            i++;
            temp1=temp1->next;
        }
        return head;
    }
};


// MERGE SORT

class Solution {
public:
    ListNode* mergeTwoSortedLinkedList(ListNode*list1,ListNode*list2){
        ListNode* dummyNode=new ListNode(-1);
        ListNode*temp=dummyNode;
        while(list1!=NULL and list2!=NULL ){
            // if(list1->val < list2->val){
            //     temp->next=list1;
            //     temp=list1;
            //     list1=list1->next;
            // }
            // else{
            //     temp->next=list2;
            //     temp=list2;
            //     list2=list2->next;
            // }
            if(list1->val<list2->val){
                temp->next=list1;
                temp=temp->next;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                temp=temp->next;
                list2=list2->next;
            }
        }
        if(list1!=NULL) temp->next=list1;
        else temp->next=list2;

        return dummyNode->next;
    }
    ListNode* findMidOfll(ListNode*head){
        ListNode*slow=head;
        ListNode*fast=head->next;  // so that we get first one as a  middle not second

        while(fast!=NULL and fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* mergeSort(ListNode*head){
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode*mid=findMidOfll(head);
        ListNode* leftHead=head;  // LEFT LIST
        ListNode* rightHead=mid->next;   // RIGHT LIST
        mid->next=NULL;

        leftHead=mergeSort(leftHead);
        rightHead=mergeSort(rightHead);

        return mergeTwoSortedLinkedList(leftHead,rightHead);
    }
    ListNode* sortList(ListNode* head) {
        ListNode*ans=mergeSort(head);
        return ans;
    }

    // TC:O(LOG N + (N+N/2) )
    // SC:O(1)
};


