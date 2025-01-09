#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        vector<int>knowMe(n,0);
        vector<int>Iknow(n,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    Iknow[i]++;
                    knowMe[j]++;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(knowMe[i]==n-1 and Iknow[i]==0){
                return i;
            }
        }
        return -1;
    }
};

// TC:O(N^2)+O(N)
// SC:O(2N)


// OPTIMAL SOL

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        
        int top=0; int down=n-1;
        
        while(top<down){
            // top knows down then top cannot be a celebrity
            if(mat[top][down]==1){
                top=top+1;
            }
            else if(mat[down][top]==1){
                // down knows top then down cannot be a celebrity
                down=down-1;
            }
            else{
                // if both don;t know each other then both cannot be a celebrity
                top=top+1;
                down=down-1;
            }
        }
            
            if(top>down) return -1;
            // if(top==down){
                for(int i=0;i<n;i++){
                    if(i==top) continue;
                    if(mat[top][i]==0 and mat[i][top]==1) continue;
                    else return -1;
                }
                
                return top;
            // }
            
        
        
    }
    // TC:O(2N)
    // SC:O(1)
};
