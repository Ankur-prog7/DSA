#include<bits/stdc++.h>
using namespace std;

void fun(int ind,vector<int>&arr,vector<int>&ds,vector<vector<int>>&ans,int target){
  if(ind == arr.size()){
    if(target==0) ans.push_back(ds);
    return;
  }
  // pick up the elem
  if(arr[ind]<=target){
    ds.push_back(arr[ind]);
    fun(ind,arr,ds,ans,target-arr[ind]);
    ds.pop_back();
  }
  fun(ind+1,arr,ds,ans,target);
}

vector<vector<int>> combnSum(vector<int>cand,int target){
  vector<vector<int>>ans;
  vector<int>ds;
  fun(0,cand,ds,ans,target);
  return ans;
}

int main(){
  vector<int>arr= {1,2,3,4};
  int target = 4;
  vector<vector<int>>sum = combnSum(arr,target);
  for(auto it:sum){
    bool flag=true;
    for(auto print:it){
      if(!flag) cout << ",";
      cout<< print ;
      flag = false;
    }
    cout<< endl;
  }
}