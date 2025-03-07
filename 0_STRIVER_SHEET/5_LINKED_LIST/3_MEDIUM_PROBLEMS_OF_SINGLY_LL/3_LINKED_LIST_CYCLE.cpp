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
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,int>mp;
        ListNode*temp=head;

        while(temp!=NULL){
            if(mp.find(temp)!=mp.end()){
                return true;
            }
            else{
                mp[temp]=1;
            }
            temp=temp->next;
        }
        return false;
    }
    // TC:O(N * (2 LOG N))
    // SC:O(N)
};


// USING TORTOISE AND HARE PROBLEM
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode*slow=head;
        ListNode*fast=head;

        while(fast!=NULL and fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};