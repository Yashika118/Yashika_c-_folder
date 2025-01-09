//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        unordered_map<Node*,int>mp;
        Node*temp=head; 
        int cnt=1;
        while(temp!=NULL){
            if(mp.find(temp)!=mp.end()){
                int value=mp[temp];
                return cnt-value;
            }
            else{
                mp[temp]=cnt;
                cnt++;
            }
            temp=temp->next;
        }
        return 0;
    }
};


// OPTIMAL SOL
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        Node*slow=head;
        Node*fast=head;
        int cnt=1;
        while(fast!=NULL and fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                fast=fast->next;
                while(fast!=slow){
                    fast=fast->next;
                    cnt++;
                }
                return cnt;
            }
        }
        return 0;
    }
};


