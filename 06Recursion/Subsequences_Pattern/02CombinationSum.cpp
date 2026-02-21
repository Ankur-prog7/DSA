// find the sequence whose sum == target and don't pick any elem twice
#include<bits/stdc++.h>
using namespace std;

void fun(int ind,vector<int>&arr,vector<vector<int>>&ans,int target,vector<int>&ds){
  if(target==0){
    ans.push_back(ds);
    return;
  }
  for(int i= ind;i<arr.size();i++){//loop 1
    if(i>ind && arr[i]==arr[i-1]) continue;//loop 2
    //skip the picking same elem twice
    if(arr[i]>target) break;
    
    ds.push_back(arr[i]);
    fun(i+1,arr,ans,target-arr[i],ds);
    ds.pop_back();
  }
}
vector<vector<int>> sum(vector<int>&candi,int target){
  sort(candi.begin(),candi.end());
  vector<vector<int>>ans;
  vector<int>ds;
  fun(0,candi,ans,target,ds);
  return ans;
}

int main(){
  vector<int>arr = {1,1,1,2,2};
  int target = 4;
  vector<vector<int>> ans = sum(arr,target);
  for(auto it:ans){
    bool flag =  true;
    for(auto print:it){
      if(!flag) cout<<",";
      cout << print;
      flag = false;
    }
    cout<<endl;
  }
  return 0;
}