#include <bits/stdc++.h>
using namespace std;


// if we have inorder and preorder/postorder we can create unique binary tree
// if we have preorder and postorder we cannot create unique binary tree. here various trees can be created

class Solution
{
public:
    bool isPossible(int a,int b)
    {
        //code here
        return abs(a-b)==1;
        
    }
};

