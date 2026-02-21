//  A power set of an array is an array of all possible subarrays

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> getPowerSet(vector<int>&nums){
  int n = nums.size();
  // Calculate the total number of subsets (2^n) using bitwise shift
  int subsets = 1<<n;

  vector<vector<int>>ans;

  for(int num=0;num<subsets;num++){
    vector<int> subset;
    for (int i = 0; i < n; i++)
    {
      if(num & (1<<i)){
        subset.push_back(nums[i]);
      }
    }
    ans.push_back(subset);
  }
  return ans;
}