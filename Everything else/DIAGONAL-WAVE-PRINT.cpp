// DIAGONAL WAVE PRINT
#include <iostream>
using namespace std;
int main()
{

    int arr[100][100];
    int row, col;
    cin >> row >> col;
    int i, j;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }

    i = 0;
    while (i < row)
    {
        int ii = i;
        j = 0;
        while (ii >= 0)
        {
            cout << arr[ii][j];

            ii--;
            j++;
        }

        i++;
    }

    j = 1;
    while (j <= col - 1)
    {
        int ii = row - 1;
        int jj = j;

        while (jj < col & ii >= 0)
        {
            cout << arr[ii][jj];

            ii--;
            jj++;
        }

        j++;
    }
}
