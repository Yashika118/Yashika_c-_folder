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
    int lengthOfLL(ListNode*head){
        ListNode*temp=head; int cnt=0;
        while(temp!=NULL){
            cnt++;
            // if(temp->next==NULL){
            //     end=temp;
            // }
            temp=temp->next;
        }
        return cnt;
    }
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
        int len=lengthOfLL(head);

        int m=k%len;
        if(m==0) return head;

        ListNode*temp=head;
        temp=reversell(temp);
        ListNode*end=temp;
        while(end->next!=NULL){
            end=end->next;
        }


        while(m--){
            ListNode*n=temp;
            temp=temp->next;
            n->next=NULL;
            end->next=n;
            end=n;
        }

        temp=reversell(temp);
        return temp;
    }
    // TC:O(3N+K)
};


// OPTIMAL SOL

class Solution {
public:
    int lengthofll(ListNode*head,ListNode*&end){
        ListNode*temp=head; int cnt=0;
        while(temp!=NULL){
            cnt++;
            if(temp->next==NULL){
                end=temp;
            }
            temp=temp->next;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
        ListNode* end=head;
        int len=lengthofll(head,end);
        int m=k%len;
        int diff=len-m-1;

        ListNode*temp=head;

        while(diff--){
            temp=temp->next;
        }

        end->next=head;
        ListNode*n=temp->next;
        temp->next=NULL;
        return n;
    }
};