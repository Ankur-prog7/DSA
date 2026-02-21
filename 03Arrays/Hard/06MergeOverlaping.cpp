// merge overlapping sub-intervals
//ans.back()--> it store previous elem
// ans.back()[1]-->it stores previous elem present in 1st column  

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>mergeOverlapping(vector<vector<int>> &arr){
  int n = arr.size();
  sort(arr.begin(),arr.end());
  vector<vector<int>>ans;
  for (int i = 0; i < n; i++){
    if(ans.empty() || arr[i][0] > ans.back()[1]){ // If ans is empty, OR second wale pair ka first elem if 1st wale pair k second elem se bada h to new interval banayege {1,3},{5,8}--> here 5>3 therefore store 5,8 in new list
      ans.push_back(arr[i]);
    }
    else{
      ans.back()[1] = max(ans.back()[1],arr[i][1]);//"Increase the end of the merged interval to the largest end point so far."
    }
  }
  return ans;

}

int main(){
  vector<vector<int>> a = {
    {2,4},
    {3,1},
    {2,8},
    {9,1},
    {3,6}
  };
  vector<vector<int>> t = mergeOverlapping(a);
  for(auto x:t){
      cout<<"{"<< x[0] <<','<< x[1] <<"}"<<endl;;
    }
    
  return 0;
}