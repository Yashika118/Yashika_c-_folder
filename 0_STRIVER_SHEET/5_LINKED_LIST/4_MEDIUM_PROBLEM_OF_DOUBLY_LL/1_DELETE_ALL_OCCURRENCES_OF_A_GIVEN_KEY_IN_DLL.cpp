#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; 

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        Node*head=*head_ref;
        Node*temp=head;
        
        while(temp!=NULL){
            if(temp->data==x and temp==head){
                Node*del=temp;
                temp=temp->next;
                temp->prev=NULL;
                head=temp;
                delete del;
            }
            else if(temp->data==x and temp->next==NULL){
                Node*del=temp;
                temp=temp->prev;
                temp->next=NULL;
                delete del;
            }
            else if(temp->data ==x) {
                Node*del=temp;
                Node*front=temp->next;
                temp=temp->prev;
                temp->next=front;
                front->prev=temp;
                delete del;
                temp=temp->next;
                
            }
            else{
                
                temp=temp->next;
            }
        }
        
        *head_ref=head;
        return;
    }
};


