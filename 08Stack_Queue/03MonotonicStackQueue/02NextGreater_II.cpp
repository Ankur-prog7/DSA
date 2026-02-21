// if you don't find greater you can roatate
// use of circular array with i%n
#include<bits/stdc++.h>
using namespace std;

vector<int> GreaterNum(vector<int>nums){
  stack<int>st;

  // for storing result
  int n = nums.size();
  vector<int>res(n);

  // traversing from last i.e double of arr
  for (int i = 2*n-1; i >=0; i--)
  {
    // get actual index
    int ind = i%n;
    /* Pop the elements in the stack until 
    the stack is not empty and the top 
    element is not the greater element */
    while(!st.empty() && st.top() <= nums[i]){
      st.pop();
    }

    // store the elem for second half
    if(i<n){
      // if greater elem is not found stack will be empty
      if(st.empty()) res[i] = -1;
      else res[i] = st.top();
    }

    st.push(nums[i]);
  }
  return res;
}