// LS-58
// allocate minimum no. of pages
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to find minimum number of pages.
    bool check(int A[], int tot_students, int minipage, int N)
    {
        int mere_students = 1;
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            if (sum + A[i] > minipage)
            {
                mere_students++;
                sum = A[i];
            }
            else
            {
                sum += A[i];
            }
        }
        if (mere_students <= tot_students)
        {
            return true;
        }
        return false;
    }
    int findPages(int A[], int N, int M)
    {
        // code here
        if (N < M)
        {
            return -1;
        }

        int low = *max_element(A, A + N);
        int high = accumulate(A, A + N, 0); // to calculate max sum
        int ans = -1;

        while (low <= high)
        {
            int mid = (low + high) / 2; // itne page allocate krna chah rha hoon

            if (check(A, M, mid, N) == true)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};