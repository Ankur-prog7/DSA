// no of next greatest elements to right
#include<bits/stdc++.h>
using namespace std;

// funcn to find next greater elem for each elem in array
vector<int> nextGreater(vector<int> arr){
  int n = arr.size();

  // for result
  vector<int>ans;
  
  // to store elem
  stack<int>st;

  for (int i = n-1; i >= 0; i--)
  {
    int currElem = arr[i];

    // pop the elem in stack until top elem is not greater than curr elem
    while(!st.empty() && st.top() <= currElem){
      st.pop();
    }

    if(st.empty()) ans[i]=-1;
    else ans[i] = st.top();

    // push the curr elem maintaining decreasing order
    st.push(ans[i]);
  }
  return ans;
}