#include<bits/stdc++.h>
using namespace std;
// Definition for doubly-linked list.
class Node
{
public:
   int data;
   Node *next, *prev;
   Node() : data(0), next(nullptr), prev(nullptr) {}
   Node(int x) : data(x), next(nullptr), prev(nullptr) {}
   Node(int x, Node *next, Node *prev) : data(x), next(next), prev(prev) {}
};


Node* constructDLL(vector<int>& arr) {
    // Write your code here
    Node*head=new Node(arr[0]);
    Node*temp=head;
    for(int i=1;i<arr.size();i++){
        Node*n=new Node(arr[i]);
        n->prev=temp;
        temp->next=n;
        temp=n;
    }
    return head;
}
