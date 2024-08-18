#include<iostream>
using namespace std;
int main(){

    int n;
    cin>>n;
    int row;
    int countstar=1;


    row=1;
    while(countstar<=(2*n-1)){
    cout<<'*'<<' ';
        countstar++;

    }
    
    cout<<endl;
    row++;

    while(row<=n){
        int star=1;

    while(star<=n+1-row){
        cout<<'*'<<' ';
        star++;
    }
        // cout<<endl;
        int space=1;
        while(space<=(2*row-3)){
        cout<<' '<<' ';
        space++;
    }
        int str=1;
        while(str<=n+1-row){
        cout<<'*'<<' ';
        str++;
    }
        cout<<endl;
        row++;
    }

    int ro=2;
    
    while(ro<=(n-1)){
    int st=1;
    while(st<=ro){
        cout<<'*'<<' ';
        st++;
    }
        int spc=1;
        while(spc<=((2*n)-((2*ro)+1))){
            cout<<' '<<' ';
            spc++;
        }
        
        int sta=1;
        while(sta<=ro){
        cout<<'*'<<' ';
        sta++;
        }
        cout<<endl;
        ro++;
    }
    
    int coutstar=1;
    while(coutstar<=(2*n-1)){
        cout<<'*'<<' ';
        coutstar++;
    }
   
    return 0;
    }









    
    
