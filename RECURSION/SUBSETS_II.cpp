// class Solution {

//   public:
//   void findsubsets(int ind,vector<int>nums,vector<int>a,vector<vector<int>>&ansvec){
//     ansvec.push_back(a);
//     for(int i=ind;i<nums.size();i++){
//         if(i!=ind and nums[i]==nums[i-1]){
//             continue;
//         }
//         a.push_back(nums[i]);
//         findsubsets(i+1,nums,a,ansvec);
//         a.pop_back();

//     }
// }
//     vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
//         // Write your code here
//         sort(nums.begin(),nums.end());
//         vector<int>a;
//         vector<vector<int>>ansvec;
//         // ansvec.push_back(a);
//         findsubsets(0,nums,a,ansvec);
//         return ansvec;
//         }
// };

#include <bits/stdc++.h>
using namespace std;
void findsubsets(int ind, vector<int> v, vector<int> a, vector<vector<int>> &ansvec)
{
    ansvec.push_back(a);
    for (int i = ind; i < v.size(); i++)
    {
        if (i != ind and v[i] == v[i - 1])
        {
            continue;
        }
        a.push_back(v[i]);
        findsubsets(i + 1, v, a, ansvec);
        a.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> v)
{
    sort(v.begin(), v.end());
    vector<int> a;
    vector<vector<int>> ansvec;
    // ansvec.push_back(a);
    findsubsets(0, v, a, ansvec);
    return ansvec;
}
int main()
{
    vector<int> v;
    vector<vector<int>> ans;
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(3);
    ans = subsetsWithDup(v);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
