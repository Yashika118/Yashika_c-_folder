#include <iostream>
using namespace std;

void antispiralprint(int arr[10][10], int row, int col)
{

    int lowercol = 0;
    int uppercol = col - 1;
    int lowerrow = 0;
    int upperrow = row - 1;
    int elements = row * col;
    int count = 0;

    while (count < elements)
    {

        for (int i = lowerrow; i <= upperrow; i++)
        {
            if (count == elements)
            {
                break;
            }
            cout << arr[i][lowercol] << ", ";
            count++;
        }
        lowercol++;

        for (int j = lowercol; j <= uppercol; j++)
        {
            if (count == elements)
            {
                break;
            }
            cout << arr[upperrow][j] << ", ";
            count++;
        }
        upperrow--;

        for (int i = upperrow; i >= lowerrow; i--)
        {
            if (count == elements)
            {
                break;
            }
            cout << arr[i][uppercol] << ", ";
            count++;
        }
        uppercol--;

        for (int j = uppercol; j >= lowercol; j--)
        {
            if (count == elements)
            {
                break;
            }
            cout << arr[lowerrow][j] << ", ";
            count++;
        }
        lowerrow++;
    }

    cout << "END";
}

int main()
{

    int row, col;
    cin >> row >> col;

    int arr[10][10];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }

    antispiralprint(arr, row, col);
}