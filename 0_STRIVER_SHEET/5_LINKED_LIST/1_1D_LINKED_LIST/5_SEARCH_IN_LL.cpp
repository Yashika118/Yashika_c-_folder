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
    // Function to count nodes of a linked list.
    bool searchKey(int n, struct Node* head, int key) {
        // Code here
        Node*temp=head;
        while(temp!=NULL){
            if(temp->data == key){
                return true;
                break;
            }
            temp=temp->next;
        }
        return false;
    }
};
