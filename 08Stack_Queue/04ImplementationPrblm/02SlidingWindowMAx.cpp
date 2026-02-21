#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindo(vector<int>&nums,int k){
  deque<int> dq;
  vector<int>result;

  for (int i = 0; i < nums.size(); i++)
  {
    // remove the elem from front if they are out of range
    if(!dq.empty() && dq.front() <= i-k){
      dq.pop_front();
    }
    while (!dq.empty() && nums[dq.back()]<nums[i])
    {
      dq.pop_back();
    }
    // add the curr index to the dq
    dq.push_back(i);

    // Once the first window is completed , add front elem to result
    if(i >= k-1){
      result.push_back(nums[dq.front()]);
    }
  }
  return result;
}