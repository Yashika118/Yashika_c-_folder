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
    void deleteAtFront(ListNode*&head){
        if(head->next==NULL){
            head=NULL;
            return;
        }
        ListNode*temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    void deleteAtEnd(ListNode* &head){
        ListNode*temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        ListNode*temp1=temp->next;
        temp->next=NULL;
        delete temp1;
    }
    int lengthofll(ListNode*&head){
        int cnt=0;
        ListNode*temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    void deleteAtAnyPos(ListNode*&head,int pos){
        ListNode*temp=head;
        for(int jump=1;jump<pos;jump++){
            temp=temp->next;
        }
        ListNode*a=temp->next;
        temp->next=temp->next->next;
        a->next=NULL;
        delete a;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=lengthofll(head);
        int pos=len-n;

        if(pos==0){
            deleteAtFront(head);
        }
        else if(pos>=len-1){
            deleteAtEnd(head);
        }
        else{
            deleteAtAnyPos(head,pos);
        }

        return head;
    }
};



// OPTIMAL SOL

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL){
            return head->next;
        }

        ListNode*fast=head;
        while(n--){
            fast=fast->next;
        }

        if(fast==NULL) return head->next;
        
        ListNode*slow=head;
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        
        ListNode*temp=slow->next;
        slow->next=slow->next->next;
        temp->next=NULL;

        delete temp;
        return head;
    }
};