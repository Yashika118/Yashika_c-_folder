#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*>mp;
        Node*temp=head;
        while(temp!=NULL){
            Node*newNode=new Node(temp->val);
            mp[temp]=newNode;
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            Node*copyNode=mp[temp];
            copyNode->next=mp[temp->next];
            copyNode->random=mp[temp->random];
            temp=temp->next;
        }

        return mp[head];
    }
};


// OPTIMAL SOL
                                
// Node *cloneLL(Node *head){
// 	// Write your code here
// 	Node *temp=head;
// 	while(temp!=nullptr)
// 	{
// 		Node *naya=new Node();
// 		naya->data=temp->data;
// 		naya->next=temp->next;
// 		temp->next=naya;
// 		temp=temp->next->next;
// 	}
// 	temp=head;
// 	while(temp!=nullptr)
// 	{
//                 if (temp->random != nullptr) {
//                   temp->next->random = temp->random->next;
//                 }
//                 temp=temp->next->next;
// 	}
// 	temp=head;
//   Node* clonedHead = temp->next;
//     Node* clonedTemp = clonedHead;
//     while (temp != nullptr) {
//         temp->next = temp->next->next;
//         temp = temp->next;

//         if (clonedTemp->next != nullptr) {
//             clonedTemp->next = clonedTemp->next->next;
//             clonedTemp = clonedTemp->next;
//         }
//     }
// 	return  clonedHead;
// }