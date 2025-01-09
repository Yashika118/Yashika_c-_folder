// least recently used
// LRU(4 --> MAX CAPACITY)
// put(2,6)
// put(4,7)
// put(8,11)
// put(7,10)
// get(2)
// get(8)
// put(5,6)
// get(7)
// put(5,7)

// ANS-->

// (7,10) (8,11) (4,7) (2,6)  -->BCOZ MAX CAPACITY IS 4
//  MRU                 LRU

// get(2) == 6 so it is MRU now so it will put in starting 
// (2,6) (7,10) (8,11) (4,7) 

// get(8) == 11 so it is MRU now so it will put in starting 
//  (8,11) (2,6) (7,10) (4,7) 

// now we have to put (5,6) but capacity is full therefore we first remove LRU and then put it 
// (5,6) (8,11) (2,6) (7,10)

// get(7) == 10 so it is MRU now so it will put in starting 
// (7,10) (5,6) (8,11) (2,6) 

// now we have to put (5,7) so we first put (5,6) in starting then update its value
// (5,6) (7,10) (8,11) (2,6) 
// (5,7) (7,10) (8,11) (2,6) 

#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int key,val;
    Node*next;
    Node*prev;
    Node(int key,int val){
        this->key=key;
        this->val=val;
        next=NULL;
        prev=NULL;
    }
};
class LRUCache {
    int size,capacity;
    Node*head;
    Node*tail;
    unordered_map<int,Node*>mp;
public:
    LRUCache(int capacity) {
        size=0;
        this->capacity=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }

    void insertNodeAtEnd(Node* node){
        // detachment of node 
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        if(prevNode != NULL) prevNode->next = nextNode; // for new node prevNode would be null
        if(nextNode != NULL) nextNode->prev = prevNode; // for new node nextNode would be null
        
        // attachment of node at end
        Node* tailPrev = tail->prev;
        tailPrev->next = node;
        node->prev = tailPrev;
        node->next = tail;
        tail->prev = node;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        
        Node* node = mp[key];
        insertNodeAtEnd(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];
            node->val = value;
            insertNodeAtEnd(node);
        }
        else{
            Node* node = NULL;
            if(size == capacity){
                node = head->next;
                mp.erase(node->key);
                node->key = key;
                node->val = value;
                // insertNodeAtEnd(node);
            }
            else{
                size++;
                node = new Node(key,value);
                // insertNodeAtEnd(node);
            }
            insertNodeAtEnd(node);
            mp[key] = node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */