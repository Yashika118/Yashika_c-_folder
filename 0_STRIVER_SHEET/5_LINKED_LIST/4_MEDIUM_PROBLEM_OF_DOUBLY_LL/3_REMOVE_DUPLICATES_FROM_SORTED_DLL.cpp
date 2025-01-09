#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};


class Solution
{
public:
 
    Node * removeDuplicates(struct Node *head)
    {
        // Your code here
        map<int,int>mp;
        Node*temp=head;
        while(temp!=NULL){
            mp[temp->data]++;
            temp=temp->next;
        }
        
        Node*temp1=head->next;
        while(temp1!=NULL){
            if(mp.find(temp1->data)!=mp.end()){
                if(mp[temp1->data]>1){
                    // delete
                    Node*del=temp1;
                    Node*front=temp1->next;
                    Node*back=temp1->prev;
                    back->next=front;
                    front->prev=back;
                    mp[temp1->data]--;
                    temp1=back;
                    delete del;
                }
            }
            temp1=temp1->next;
        }
        
        return head;
    }
};



// OPTIMAL SOL

class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {
        // Your code here
        Node*temp=head;
        Node*newTemp=temp->next;
        
        while(temp->next!=NULL){
            if(newTemp->data==temp->data){
                
                Node*del=newTemp;
                Node*front=newTemp->next;
                if(front!=NULL){
                    
                front->prev=temp;
                }
                temp->next=front;
                newTemp=front;
                delete del;
            }
            else{
                temp=newTemp;
                newTemp=newTemp->next;
            }
        }
        return head;
    }
};


