#include<iostream>
using namespace std;
void  spiralprint(int arr[10][10],int row,int col){
    
    int right=0;
    int downward=0;
    int left=0;
    int upward=0;
    int elements=row*col;
    int count=0;
    
    

    int i=0;
    int j=left;

    // while(elements!=count){
        
        for(j=left;j<col;j++){
            cout<<arr[i][j]<<" ";
            count++;
            if(count==elements){
            break;
            }
             right=j;
        }
    

        for(i=i+1;i<row;i++){
            cout<<arr[i][right]<<" ";
            count++;
            if(count==elements){
            break;
            }
            downward=i;
        }
// 
        for(j=right-1;j>=0;j--){
            cout<<arr[downward][j]<<" ";
            count++;
            if(count==elements){
            break;
            }
            left=j;
        }

        for(i=downward-1;i>0;i--){
            cout<<arr[i][left]<<" ";
            count++;
            if(count==elements){
            break;
            }
            upward=i;
        }

        // for(int i=upward-1;i>0;i--){
        //     cout<<arr[i][left];
            // again=i;
        
        left++;
        // j=left;
        i=upward;
        row--;
        col--;
        
        
        
        }

    // }




int main(){

    int row,col;
    cin>>row>>col;

    

    int arr[10][10];

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
         cin>>arr[i][j];
        }
    }

    spiralprint(arr,row,col);


}