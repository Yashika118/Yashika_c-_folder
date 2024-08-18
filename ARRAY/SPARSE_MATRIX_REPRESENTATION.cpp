#include <bits/stdc++.h>
using namespace std;
struct sparseMatrix
{
    int row;
    int col;
    int val;
};
int main()
{
    int row, col;
    cout << "enter number of rows and cols : ";
    cin >> row >> col;
    int arr[row][col];

    cout << "enter the elements of matrix : ";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<sparseMatrix> ans;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] != 0)
            {
                sparseMatrix temp;
                temp.row = i;
                temp.col = j;
                temp.val = arr[i][j];
                ans.push_back(temp);
            }
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].row << " " << ans[i].col << " " << ans[i].val << endl;
    }
    return 0;
}