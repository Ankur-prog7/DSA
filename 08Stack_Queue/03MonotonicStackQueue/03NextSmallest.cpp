#include<bits/stdc++.h>
using namespace std;

vector<int> NextSmallest(vector<int>&nums){
  stack<int>st;

  // for result 
  int n = nums.size();
  // initialize answer array with -1
  vector<int>res(n,-1);

  // iterating from front till end
  for (int i = 0; i < n; i++)
  {
  // checking if prev no is less or not 
  while(!st.empty() && st.top() >= nums[i]){
    st.pop();
  } 
  res[i] = st.empty()?-1:st.top();
  st.push(nums[i]);
  }
  return res; 
}

int main(){
  vector<int>a={2,10,12,1,11};
  vector<int>ans = NextSmallest(a);
  for(auto res:ans){
  cout << res<<" ";
  }
  return 0;
}