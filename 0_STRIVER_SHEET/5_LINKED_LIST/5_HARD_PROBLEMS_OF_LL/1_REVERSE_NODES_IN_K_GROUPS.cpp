#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    ListNode*findKthNode(ListNode*temp,int k){
        k-=1;
        while(temp!=NULL and k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*temp=head;
        ListNode*nextNode=NULL;
        ListNode*prevNode=NULL;
        while(temp!=NULL){
            ListNode*kthNode=findKthNode(temp,k);
            if(kthNode==NULL){
                if(prevNode) prevNode->next=temp;
                break;
            }
            nextNode=kthNode->next;
            kthNode->next=NULL;
            reversell(temp);
            if(temp==head){
                head=kthNode;
            }
            else{
                prevNode->next=kthNode;
            }
            prevNode=temp;
            temp=nextNode;
        }

        return head;
    }
};