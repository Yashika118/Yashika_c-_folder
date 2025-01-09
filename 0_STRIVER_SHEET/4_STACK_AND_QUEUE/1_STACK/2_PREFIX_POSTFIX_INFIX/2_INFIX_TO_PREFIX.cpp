// 1. REVERSE THE INFIX EXPRESSION
// 2. CHANGE '(' TO ')' AND ')' TO '('
// 3. INFIX TO POSTFIX
// 4. REVERSE THE ANS
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int priority(char ch){
        if(ch=='^') return 3;
        else if(ch=='*' || ch=='/') return 2;
        else if(ch=='+' || ch=='-') return 1;
        else return -1;
        
    }
    string infixToPostfix(string s) {
        // Your code here
        stack<char>st;
        int n=s.length();
        string ans="";
        
        for(int i=0;i<n;i++){
            // if ch is an operand
            char ch=s[i];
            if((ch>='A' and ch<='Z') || (ch>='a' and ch<='z') || (ch>='0' and ch<='9')){
                ans=ans+ch;
            }
            else if(ch=='('){
                // if we get '(' , add it to st
                st.push(ch);
            }
            else if(ch==')'){
                // remove all ele from st till we get '('
                while(!st.empty() and st.top()!='('){
                    ans=ans+st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                // if we  get operator
                while(!st.empty() and priority(ch)<priority(st.top())){
                    ans=ans+st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
        
        while(!st.empty()){
            ans=ans+st.top();
            st.pop();
        }
        cout<<"POSTFIX: "<<ans<<endl;
        return ans;
    }
    
    string infixToPrefix(string s){
        reverse(s.begin(),s.end());
        string ans="";
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch=='('){
                // s[i]=')';
                ch=')';
                ans+=ch;
            }
            else if(ch==')'){
                // s[i]='(';
                ch='(';
                ans+=ch;
            }
            else{
                ans+=ch;
            }
        }
        // ans=s;
        cout<<"REVERSE: "<<ans<<endl;
        string new_ans=infixToPostfix(ans); 
        reverse(new_ans.begin(),new_ans.end());
        
        return new_ans;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {

    Solution ob;
    string str="(A+B)*C-D+F";
    cout << ob.infixToPrefix(str) << endl;
    return 0;
}

// } Driver Code Ends
// TC:O(N/2)+O(N/2)+O(2N)
// SC:O(N)

        