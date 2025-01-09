//{ Driver Code Starts
//USING BFS
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        vector<vector<string>>ans;
        unordered_set<string>st(wordList.begin(),wordList.end());
        vector<string>usedOnLevel;
        queue<vector<string>>q;

        q.push({beginWord});
        usedOnLevel.push_back(beginWord);
        int level=0;

        while(!q.empty()){
            vector<string>v=q.front();
            q.pop();

            if(v.size() > level){
                level++;
                for(auto it:usedOnLevel){
                    st.erase(it);
                }
            }

            string word=v.back();

            if(word==endWord){
                if(ans.size()==0){
                    ans.push_back(v);
                }
                else if(ans[0].size()==v.size()){
                    ans.push_back(v);
                }
            }

            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        v.push_back(word);
                        q.push(v);
                        usedOnLevel.push_back(word);
                        v.pop_back();
                    }
                }
                word[i]=original;
            }
        }
        return ans;
    }
};




// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        queue<pair<string,int>>q;
        q.push({startWord,1});
        unordered_set<string>s(wordList.begin(),wordList.end());
        s.erase(startWord);
        while(!q.empty()){
            string word=q.front().first;
            int step=q.front().second;
            q.pop();
            if(word==targetWord) return step;
            
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    //if exists in the set
                    if(s.find(word)!=s.end()){
                        s.erase(word);
                        q.push({word,step+1});
                    }
                }
                
                word[i]=original;
            }
        }
        return 0;
    }
};
// TC: N*word.length*26*log(N)



class Solution
{
    // Create a map of type word->level to get the idea 
    // on which level the word comes after the transformations.
    unordered_map<string, int> mpp;

    // A vector for storing the final answer.
    vector<vector<string>> ans;
    string b;

private:
    void dfs(string word, vector<string> &seq)
    {
        // Function for implementing backtracking using the created map
        // in reverse order to find the transformation sequence in less time.

        // Base condition :
        // If word equals beginWord, we’ve found one of the sequences
        // simply reverse the sequence and return. 
        if (word == b)
        {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
    
            // reverse again so that the dfs calls are not disturbed.
            reverse(seq.begin(), seq.end());
            return;
        }
        int sz = word.size();
        int steps = mpp[word];

        // Replace each character of the word with letters from a-z 
        // and check whether the transformed word is present in the map
        // and at the previous level or not.  
        for (int i = 0; i < sz; i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (mpp.find(word) != mpp.end() && mpp[word] + 1 == steps)
                {
                    seq.push_back(word);
                    dfs(word, seq);
                    // pop the current word from the back of the queue
                    // to traverse other possibilities.
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        // Push all values of wordList into a set
        // to make deletion from it easier and in less time complexity.
        unordered_set<string> st(wordList.begin(), wordList.end());

        // Perform BFS traversal and push the string in the queue
        // as soon as they’re found in the wordList.
        queue<string> q;
        b = beginWord;
        q.push({beginWord});

        // beginWord initialised with level 1.
        mpp[beginWord] = 1;
        int sz = beginWord.size();
        st.erase(beginWord);
        while (!q.empty())
        {

            string word = q.front();
            int steps = mpp[word];
            q.pop();
            
            // Break out if the word matches the endWord
            if (word == endWord)
                break;

            // Replace each character of the word with letters from a-z 
            // and check whether the transformed word is present in the 
            // wordList or not, if yes then push to queue
            for (int i = 0; i < sz; i++)
            {
                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++)
                {

                    word[i] = ch;
                    if (st.count(word))
                    {
                        q.push(word);
                        st.erase(word);
                       
                        // push the word along with its level
                        // in the map data structure.
                        mpp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }
    
        // If we reach the endWord, we stop and move to step-2
        // that is to perform reverse dfs traversal.
        if (mpp.find(endWord) != mpp.end())
        {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return ans;
    }
};

