#include<bits/stdc++.h>
using namespace std;

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        if(head==NULL){
            Node*node=new Node(x);
            head=node;
            return head;
        }
        
        Node*temp=head;
        while(temp->next!=NULL){
            
            temp=temp->next;
        }
        
        Node*node=new Node(x);
        temp->next=node;
    
            
        return head;
        
    }
};

