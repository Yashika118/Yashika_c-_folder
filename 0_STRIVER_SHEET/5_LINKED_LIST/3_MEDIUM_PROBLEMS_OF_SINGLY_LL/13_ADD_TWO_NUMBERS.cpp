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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*t1=l1;
        ListNode*t2=l2;
        ListNode*dummy=new ListNode(-1);
        ListNode*temp=dummy;
        int carry=0;
        int sum=0;
        while(t1!=NULL || t2!=NULL){
            sum=carry;
            if(t1) sum+=t1->val;
            if(t2) sum+=t2->val;
           
            ListNode*n=new ListNode(sum%10);
            carry=(sum/10);
            temp->next=n;
            temp=temp->next;
            
            if(t1) t1=t1->next;
            if(t2) t2=t2->next;
        }

    
        if(carry){
            ListNode*n=new ListNode(carry);
            temp->next=n;
        }

        return dummy->next;

    }
};