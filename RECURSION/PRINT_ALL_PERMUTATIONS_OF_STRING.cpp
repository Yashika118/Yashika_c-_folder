// arr[]={1,2,3};  so n=3;
// total no. of permutations = n!=3!;
// #include <bits/stdc++.h>
// using namespace std;
// void printallpermutations(int arr[], int n, bool freq[3], vector<int> v, vector<vector<int>> &ans)
// {
//     if (v.size() == n)
//     {
//         ans.push_back(v);
//         return;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if (!freq[i])
//         {
//             freq[i] = true;
//             v.push_back(arr[i]);
//             printallpermutations(arr, n, freq, v, ans);
//             v.pop_back();
//             freq[i] = false;
//         }
//     }
// }
// int main()
// {
//     int arr[] = {1, 2, 3};
//     int n = sizeof(arr) / sizeof(int);
//     vector<int> v;
//     vector<vector<int>> ans;
//     bool freq[3];

//     printallpermutations(arr, n, freq, v, ans);
//     for (int i = 0; i < ans.size(); i++)
//     {
//         for (int j = 0; j < ans[i].size(); j++)
//         {
//             cout << ans[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

//

// 2ND APPROACH
#include <bits/stdc++.h>
using namespace std;
void permutations(int ind, vector<int> nums, vector<int> v, vector<vector<int>> &ans)
{
    // base case
    if (ind == nums.size())
    {
        for (int i = 0; i < nums.size(); i++)
        {
            v.push_back(nums[i]);
        }
        ans.push_back(v);
        return;
    }

    // recursive case
    for (int i = ind; i < nums.size(); i++)
    {
        swap(nums[ind], nums[i]);
        permutations(ind + 1, nums, v, ans);
        swap(nums[ind], nums[i]);
    }
}
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    vector<int> v;
    vector<vector<int>> ans;
    permutations(0, nums, v, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}