// // permutations of N distinct elements = N!   --> time complexity will be O(N!)

// void printpermutations(int arr[],int ci){
//     // base case
//     if(ci==arr.length-1){
//         printarray(arr);
//         return;
//     }
//     // recursive case
//     for(int i=ci,i<arr.length;i++){
//         swap(arr[i],arr[ci]);
//         printpermutations(arr,ci+1);
//         swap(arr[i],arr[ci]);

//     }
// }
// int main(){
//     printpermutations(arr,0);
// }
