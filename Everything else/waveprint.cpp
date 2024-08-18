#include <iostream>
using namespace std;

void rowwisewaveprint(int arr[1000][1000], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
            if (i % 2 == 0)
            {
                for (int j = 0; j <= n - 1; j++){
                
                cout << arr[i][j] << ", ";

                }
            }
        
        // cout<<endl;
        
            if (i % 2 != 0)
            {
                for (int j = n - 1; j >= 0; j--){

                cout << arr[i][j] << ", ";
                }

            }
        
        // cout<<endl;
    }
    cout << "END";
    cout << endl;
}
int main()
{

    int m, n;
    cin >> m >> n;

    int arr[1000][1000];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    rowwisewaveprint(arr, m, n);
}