// class Solution {
// public:

//     void smalleronleft(vector<int>heights,vector<int>&left){
//         stack<int>s;
//         s.push(0);
//         for(int i=1;i<heights.size();i++){
//             while((!s.empty()) and heights[i]<=heights[s.top()]){
//                 s.pop();
//             }

//             if(!s.empty()){
//                 left[i]=s.top();
//             }
//             s.push(i);

//         }

//     }

//      void smalleronright(vector<int>heights,vector<int>&right){
//          stack<int>s;
//          s.push(heights.size()-1);
//          for(int i=heights.size()-2;i>=0;i--){
//              while((!s.empty()) and heights[i]<=heights[s.top()]){
//                  s.pop();
//              }

//              if(!s.empty()){
//                  right[i]=s.top();
//              }
//              s.push(i);
//          }
//      }

//     int largestRectangleArea(vector<int>& heights) {

//         vector<int>left(heights.size(),-1);
//         vector<int>right(heights.size(),heights.size());

//         smalleronleft(heights,left);

//         // for(auto x:left){
//         //     cout<<x<<" ";
//         // }
//         // cout<<endl;

//         smalleronright(heights,right);
//         // for(auto x:right){
//         //     cout<<x<<" ";
//         // }
//         // cout<<endl;

//         // WIDTH
//         vector<int>width(heights.size(),0);
//         for(int i=0;i<heights.size();i++){
//             width[i]=(right[i]-left[i])-1;
//         }

//         // for(auto x:width){
//         //     cout<<x<<" ";
//         // }
//         // cout<<endl;

//         // AREA
//         vector<int>area(heights.size(),0);
//         for(int i=0;i<heights.size();i++){
//             area[i]=heights[i]*width[i];
//         }

//         //  for(auto x:area){
//         //     cout<<x<<" ";
//         // }
//         // cout<<endl;

//        sort(area.begin(),area.end());

//         return area[area.size()-1];
//     }
// };