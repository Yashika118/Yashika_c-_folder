#include<bits/stdc++.h>
using namespace std;

// USING HASHMAP

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int>mp;
        ListNode*temp=head;

        while(temp!=NULL){
            if(mp.find(temp)!=mp.end()){
                return temp;
            }
            else{
                mp[temp]++;
            }
            temp=temp->next;
        }
        return NULL;
    }
};

// USING TORTOISE AND HARE

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode*slow=head;
        ListNode*fast=head;
        
        while(fast!=NULL and fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return NULL;

    }
};