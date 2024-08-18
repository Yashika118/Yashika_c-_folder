//  #include<iostream>
//  using namespace std;
//  int main(){
//  int n;
//  cin>>n;
//  int arr[n];
//  for(int i=0;i<n;i++){
//      cin>>arr[i];
//  }
//  int a;
//  cin>>a;
//      int i=0;
//  while(i<n){
//      if(arr[i]==a){
//          cout<<i<<endl;
//          break;
//      }
//      i++;
//  }
//  }

// // }

// #include<iostream>
// using namespace std;
// int main(){

// int lar=0;
// int n;
// cin>>n;
// int arr[n];
// for(int i=0;i<n;i++){
//     cin>>arr[i];
// }

// int i=0;
// while(i<n){

//     if(arr[i]>lar){
//         lar=arr[i];
//     }
//         i++;
// }
//     cout<<lar<<endl;

// }

//                                                                LARGEST NO. IN ARRAY
// #include<iostream>
// #include<climits>
// using namespace std;
// int main(){

//     int i;
//     int n;
//     cin>>n;
// 	int lar=INT_MIN;

//     int arr[n];

//     for(i=0;i<=n-1;i++){
//         cin>>arr[i];

//         if(arr[i]>lar){
//         lar=arr[i];
//     }

//     }

//     cout<<lar<<endl;

//     return 0;
// }

//                                                                DOWNWARD TRIANGLE
// #include<iostream>
// using namespace std;
// int main(){

//  int n;
//  cin>>n;

//  int row=1;
//  int countstar=1;
//     while(countstar<=n){
//         cout<<'*'<<' ';
//         countstar++;

//     }

//     cout<<endl;

//     row++;
//  while(row<=n){

//     int space=1;
//     while(space<=row-1){
//         cout<<' ';
//         space++;
//     }

//     int star=1;
//     while(star<=n-space+1){
//         cout<<'*'<<' ';
//         star++;
//     }

//     cout<<endl;
//     row++;

//  }

//     return 0;
// }

//                                                               PATTERN MOUNTAIN;

// #include<iostream>
// using namespace std;
// int main(){

//     int a;
//     int n;
//     cin>>n;

//     int row=1;

//     while(row<=n){
//         if(row==n){
//             a=1;
//             while(a<=row-1){
//                 cout<<a<<' ';
//                 a++;
//             }
//         }
//         else{
//         a=1;
//     while(a<=row){
//         cout<<a<<' ';
//         a++;
//     }}
//     int space=1;

//     while(space<=((2*n)-(row+n))){
//         cout<<' '<<' ';
//         space++;
//     }

//     int spc=1;

//     while(spc<=(n-(row+1))){
//         cout<<' '<<' ';
//         spc++;
//     }

// //    if(row==n){
// //     a=row-1;
// //    }
// //    else{
//     a=row;
// //    }

//    while(a>=1){
//     cout<<a<<' ';
//         a--;
//    }

//     cout<<endl;
//     row++;

//     }

//     return 0;
// }

//                                                                              PATTERN
// #include<iostream>
// using namespace std;
// int main(){

// int n;
// cin>>n;
// int row=1;
// int a=1;
// while(row<=n){
// int count=1;
// while(count<=row){
//     cout<<a<<' ';
//     a++;
//     count++;
// }

// cout<<endl;
// row++;
// }

//     return 0;
// }

// INC DEC PATTERN
// #include <iostream>
// using namespace std;
// int main(){

// int n;
// cin>>n;
// int row=1;
// while(row<=n){

//     int space=1;
//     while(space<=n-row){
//         cout<<'\t';
//         space++;
//     }

//     int inc=row;
//     while(inc<=(2*row-1)){
//         cout<<inc<<'\t' ;
//         inc++;
//     }

//     if(row>=2){
//         int dec=(row-1)*2;
//         while(dec>=row){
//             cout<<dec<<'\t';
//             dec--;
//         }
//     }

// cout<<endl;
// row++;
// }

//     return 0;
// }

// HOURGLASS PATTERN
// #include<iostream>
// using namespace std;
// int main(){

//     int n;
//     cin>>n;
//     //upper trng
//     int row=1;
//     while(row<=n+1){
//         int space=1;
//         while(space<=row-1){
//             cout<<' '<<' ';
//             space++;
//         }

//         int dec=(n-row+1);
//         while(dec>=0){
//             cout<<dec<<' ';
//             dec--;
//         }

//     int inc=1;
//     while(inc<=(n-row+1)){
//         cout<<inc<<' ';
//         inc++;
//     }

//     cout<<endl;
//     row++;
//     }

//     // lower triangle
//      row=n;
//     while(row>=1){
//         int space=1;
//         while(space<=row-1){
//             cout<<' '<<' ';
//             space++;
//         }

//         int dec=(n-row+1);
//         while(dec>=0){
//             cout<<dec<<' ';
//             dec--;
//         }

//     int inc=1;
//     while(inc<=(n-row+1)){
//         cout<<inc<<' ';
//         inc++;
//     }

//     cout<<endl;
//     row--;
//     }

//     return 0;
// }

//                                   REPLACE THEM ALL
// #include<iostream>
// using namespace std;
// long long int  reverse(long long int  n){
//     long long int  rev=0;
//     while(n){
//         rev=rev*10+n%10;
//         n/=10;
//     }
//     return rev;
// }
// long long int  zerotofive(long long int  ans){
//     if(ans==0){
//         return 5;
//     }
//  long long int  rev=0;
//     while(ans!=0){
//     long long int  dg=ans%10;
//     if(dg==0){
//         dg=5;
//     }
//     rev=rev*10+dg;
//     ans=ans/10;
//     }
//     return rev;
// }
// int  main(){

//     long long int  n;
//     cin>>n;

//     long long int  fans=zerotofive(n);
//     cout<<reverse(fans);

// }

//                   ODD EVEN BACK IN DELHI
// #include<iostream>
// using namespace std;
// int main(){

// int dig;

// int n;cin>>n;
// int countno=1;

//  while(countno<=n){
//     int sum_odd=0;
//     int sum_even=0;
//  int a;cin>>a;
// while(a!=0){
//     dig=a%10;
// if(dig%2==0){
//     sum_even=sum_even+dig;
// }
// else{
//     sum_odd=sum_odd+dig;
// }
//     a=a/10;
// }

// // cout<<sum_odd<<endl;
// // cout<<sum_even<<endl;

// if((sum_even%4==0)||(sum_odd%3==0)){
//     cout<<"Yes"<<endl;
// }
// else{
//     cout<<"No"<<endl;
// }

// countno++;
// }

// return 0;
// }

//                                 INVERSE OF AN ARRAY

// #include<iostream>
// using namespace std;
// int main(){

// int i;
// int n;
// cin>>n;
// int arr1[n];

//     for( i=0;i<n;i++){
//         cin>>arr1[i];

//     }

//      for( i=0;i<n;i++){
//     int a=i;
//     i=arr1[i];
//     arr1[i]=i;
//      }
//     //   int arr2[n];

//     //   for(int j=arr1[i];j<=arr1[i];j++){
//     //     cout<<arr2[j];
//     //   }

//     return 0;
// }

//                  IS ARMSTRONG

// #include<iostream>
// #include<math.h>
// using namespace std;
// int main(){

// int n;
// cin>>n;

// int dig;
// int count=0;
// int num;
// num=n;

// while(n!=0){
// dig=n%10;
// n=n/10;
// count++;

// }
// // cout<<count<<endl;
// // bool isarmstrong=false;
// int N=num;
// int sum=0;
// while(num!=0){
//  dig=num%10;
//  sum=sum+pow(dig,count);
//  num=num/10;

// }
// // cout<<sum<<endl;
// if(sum==N){
//     cout<<"true"<<endl;
// }
// else{
//     cout<<"false"<<endl;
// }

// }
//                                  PRINT ARMSTRONG
// #include<iostream>
// #include<math.h>
// using namespace std;
// int main(){

// int N1,N2;
// cin>>N1>>N2;

//  int dig;
//  int num;

//  while(N1<=N2){
//     num=N1;
//  int n=num;
//  int count=0;

//  while(num!=0){
//  dig=num%10;
//  num=num/10;
//  count++;
//  }

// int N=n;
// int sum=0;
// while(n!=0){
//  dig=n%10;
//  sum=sum+pow(dig,count);
//  n=n/10;
// }
// //  cout<<sum<<endl;
// //  cout<<N<<endl;
// if(sum==N){
//     cout<<N<<endl;
// }

//     N1++;

//  }

// }

//                                                          BUBBLESORT
// #include <iostream>
// using namespace std;
// void bubblesort(int arr[10000], int n)
// {

//     for (int j = 0; j < n; j++)
//     {
//         for (int i = 0; i <= n-2; i++)
//         {
//             cout << i << " " << i + 1 << endl;
//             if (arr[i] > arr[i + 1])
//             {
//                 swap(arr[i], arr[i + 1]);
//             }
//         }

//     }
//     return;
// }

// int main()
// {
//     int n;
//     cin >> n;

//     int arr[10000];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     bubblesort(arr, n);
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i];
//     }
// }

//                                              FUNCTION+SORTING
// #include <iostream>
// using namespace std;

// void sortanarray(int arr[10000], int n)
// {
//     for (int j = 0; j < n; j++)
//     {
//         int k = 0;
//         for (int i = 0; i <= n - 2 - k; i++)
//         {
//             if (arr[i] > arr[i + 1])
//             {
//                 swap(arr[i], arr[i + 1]);
//             }
//         }
//         k++;
//     }
//     return;
// }

// void kyasummila(int arr[10000], int sum, int n)
// {

//     for (int i = 0; i < n; i++)
//     {

//         for (int j = 1; j < n; j++)
//         {

//             int currsum = arr[i] + arr[j];
//             if (currsum == sum)
//             {
//                 cout << "YES";
//             }
//         }
//         return;
//     }

//     cout << "NO";

//     return;
// }

// int main()
// {
//     int arr[] = {1, 8, 9, 5, 4, 5, 3};
//     int n = sizeof(arr) / sizeof(int);

//     sortanarray(arr, n);
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << endl;
//     }

//     int sum;
//     cin >> sum;

//     kyasummila(arr, sum, n);
// }

//                                                      ARRAY TARGET SUM PAIRS
// #include <iostream>
// using namespace std;

// void findtarget(int arr[1000], int n, int target)
// {

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i+1; j < n; j++)
//         {
//             int sum = arr[i] + arr[j];
//             if (sum == target)
//             {
//                 cout << min(arr[i], arr[j]) << " and " << max(arr[i], arr[j]) << endl;
//             }
//         }
//     }
// }
// int main()
// {

//     int n;
//     cin >> n;

//     int arr[1000];

//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     int target;
//     cin >> target;

//     findtarget(arr, n, target);
// }

//                                                      REVERSE AN ARRRAY
// #include <iostream>
// using namespace std;

// void reverseanarray(int arr[10000], int n)
// {

//     int i = 0, j = n - 1;
//     while (i < j)
//     {

//         swap(arr[i], arr[j]);

//         i++;
//         j--;
//     }

//     return;
// }
// int main()
// {

//     int n;
//     cin >> n;

//     int arr[10000];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     reverseanarray(arr, n);
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
// }

//                                              INVERSE AN ARRAY
// #include <iostream>
// using namespace std;

// void inverseanarray(int arr[10000], int n, int inversearr[10000])
// {

//     for (int i = 0; i < n; i++)
//     {
//         // int index = i;
//         // int value = arr[i];

//         int newindex = arr[i];
//         // int newvalue = index;
//         // int inversearr[newindex];

//         inversearr[newindex] = i;
//     }
//     return;
// }
// int main()
// {
//     int n;
//     cin >> n;

//     int arr[10000];

//     int inversearr[10000];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     inverseanarray(arr, n, inversearr);
//     for (int i = 0; i < n; i++)

//     {
//         cout << inversearr[i] << " ";
//     }
// }

// ARRAY TARGET SUM TRIPLET
// #include <iostream>
// #include <algorithm>
// using namespace std;

// void sortanarray(int arr[1000], int n)
// {

//     sort(arr, arr + n);

//     return;
// }

// void targetsumtriplet(int arr[1000], int n, int target)
// {

//     for (int i = 0; i <= n - 3; i++)
//     {
//         for (int j = i + 1; j <= n - 2; j++)
//         {

//             for (int k = j + 1; k <= n - 1; k++)
//             {
//                 int sum = arr[i] + arr[j] + arr[k];

//                 if (sum == target)
//                 {
//                     cout << arr[i] << ", " << arr[j] << " "
//                          << "and"
//                          << " " << arr[k] << endl;
//                 }
//             }
//         }
//     }

//     return;
// }
// int main()
// {

//     int n;
//     cin >> n;

//     int arr[1000];

//     for (int k = 0; k < n; k++)
//     {
//         cin >> arr[k];
//     }

//     int target;
//     cin >> target;

//     sortanarray(arr, n);

//     targetsumtriplet(arr, n, target);
// }
#include <iostream>
using namespace std;
int main()
{
    // string s;
    // cin>>s;
    // int len=s.length();
    // int num=1;
    // if(s[len-1]==num){

    // }

    // int num;
    // cin >> num;
    // int number = 97;
    // char ch = number;
    // int Num = 1;
    // for (num = 1; num <= 26; num++)
    // {
    //     if (num == Num)
    //     {
    //         cout << ch;
    //     }
    //     number++;
    //     Num++;
    // }

    int num;
    cin >> num; // 5

    int Num = 97;
    char ch = Num;
    int number = 1;
    while (number <= 26)
    {

        if (number != num)
        {
            if (number < num)
            {
                Num++;
            }
        }
        if (num == number)
        {
            // cout<<ch;
            break;
        }

        number++;
    }
    cout << ch;
}
