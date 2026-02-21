#include<bits/stdc++.h>
using namespace std;

//function to find the next greater elem
vector<int>nextGreater(vector<int>&nums){
  // to store elem
  stack<int>st;

  // result array of same size
  int n = nums.size();
  vector<int>res(n);

  // traverse from right to left <---
  for (int i = n-1; i >= 0; i--)
  {
    // pop elem if it is smaller than or equal to top elem (prev elem)
    while(!st.empty() && st.top() <= nums[i]){
      st.pop();
    }

    // if stack is empty
    if(st.empty()) res[i] = -1;

    // else top of stack is our answer
    else res[i] = st.top();

    // st.push curr elem
    st.push(nums[i]);
  }
  return res;
}

int main(){
  vector<int>a={2,10,12,1,11};
  vector<int>ans = nextGreater(a);
  for(auto res:ans){
  cout << res<<" ";
  }

  return 0;
}