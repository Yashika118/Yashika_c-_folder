#include <iostream>
using namespace std;

void colwisewaveprint(int arr[1000][1000],int m,int n){

    for(int j=0;j<n;j++){
        if(j%2==0){
            for(int i=0;i<m;i++){
                cout<<arr[i][j]<<", ";
            }
        }

            if(j%2!=0){
                for(int i=m-1;i>=0;i--){
                    cout<<arr[i][j]<<", ";
                }
            }
        

        
    }
    cout<<"END";
    cout<<endl;





    
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

    colwisewaveprint(arr,m,n);




}