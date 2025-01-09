#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        vector<int>ans=asteroids;

        for(int i=0;i<n-1;i++){
            for(int j=0;j<asteroids.size()-1;j++){
                if(asteroids[j]>0 and asteroids[j+1]<0){
                    if(abs(asteroids[j])<abs(asteroids[j+1])){
                        //remove j
                        asteroids.erase(asteroids.begin() + j);
                    }
                    else if(abs(asteroids[j])==abs(asteroids[j+1])){
                        //remove both
                        asteroids.erase(asteroids.begin() + j);
                        asteroids.erase(asteroids.begin() + j);
                    }
                    else{
                        //remove j+1
                        asteroids.erase(asteroids.begin() + j+1);
                    }
                    break;
                }
            }
        }

        return asteroids;
    }
    // GIVES RUNTIME ERROR
};


// OPTIMAL SOL
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        vector<int>st;
        for(int i=0;i<n;i++){
            if(asteroids[i]>0){
                st.push_back(asteroids[i]);
            }
            else{
                while(!st.empty() and st.back()>0 and st.back()<abs(asteroids[i])){
                    st.pop_back();
                    // asteroids.erase(asteroids.begin()+)
                }

                if(!st.empty() and st.back()==abs(asteroids[i])){
                    st.pop_back();
                }
                else if(st.empty() || st.back()<0){
                    st.push_back(asteroids[i]);
                }
            }
        }
        return st;
    }
};
// tc:O(2N)
// SC:O(N)