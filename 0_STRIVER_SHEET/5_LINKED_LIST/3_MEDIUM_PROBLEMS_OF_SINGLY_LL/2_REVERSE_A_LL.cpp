#include<bits/stdc++.h>
using namespace std;

// USING TWO POINTER
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int lengthofll(ListNode*head){
        int count=0;
        ListNode*temp=head;

        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
            return head;
        }
        else if(head->next==NULL){
            return head;
        }
        else {
            ListNode*temp1=head;
            int length=lengthofll(head);
            int len=(length/2);

            while(length!=len){
                ListNode*temp2=head;
                for(int jump=1;jump<=length-1;jump++){

                    temp2=temp2->next;
                }
                swap(temp1->val,temp2->val);
                length--;
                temp1=temp1->next;
            }
        }

        return head;
    }
};

// USING STACK



class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<int>st;
        ListNode*temp=head;
        while(temp!=NULL){
            st.push(temp->val);
            temp=temp->next;
        }
        ListNode*temp1=head;
        while(!st.empty()){
            temp1->val=st.top();
            st.pop();
            temp1=temp1->next;
        }
        return head;
    }
};


// OPTIMAL SOL -->swaping links
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode*temp=head;
        ListNode*prev=NULL;

        while(temp!=NULL){
            ListNode*front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
};


// RECURSIVE SOL


// Node class represents a
// node in a linked list
class Node {
public:
    // Data stored in the node
    int data;   
    
    // Pointer to the next node in the list
    Node* next;      

    // Constructor with both data and
    // next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to reverse a singly
// linked list using a recursion

Node* reverseLinkedList(Node* head) {
    // Base case:
    // If the linked list is empty or has only one node,
    // return the head as it is already reversed.
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    // Recursive step:
    // Reverse the linked list starting 
    // from the second node (head->next).
    Node* newHead = reverseLinkedList(head->next);
    
    // Save a reference to the node following
    // the current 'head' node.
    Node* front = head->next;
    
    // Make the 'front' node point to the current
    // 'head' node in the reversed order.
    front->next = head;
    
    // Break the link from the current 'head' node
    // to the 'front' node to avoid cycles.
    head->next = NULL;
    
    // Return the 'newHead,' which is the new
    // head of the reversed linked list.
    return newHead;
}


// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list with
    // values 1, 3, 2, and 4
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Reverse the linked list
    head = reverseLinkedList(head);

    // Print the reversed linked list
    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}


// By changing links
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode*temp=head;
        ListNode*prev=NULL;

        while(temp!=NULL){
            ListNode*front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
};

