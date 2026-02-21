#include<bits/stdc++.h>
using namespace std;

vector<int> findPGE(vector<int>arr){
  int n =arr.size();

  vector<int>ans(n);
  stack<int>st;

  for (int i = 0; i < n; i++)
  {
    // get the curr elem 
    int currElem = arr[i];
    // pop the elem if currElem is greater or equal to the top elem until stack is empty
    while (!st.empty() && arr[st.top()<=currElem])
    {
      st.pop();
    }
    if(st.empty()) ans[i] = -1;
    else ans[i] = st.top();
    st.push(i);    
  }
  return ans;
}

vector<int> stockSpan(vector<int>arr,int n){
  vector<int>PGE = findPGE(arr);
  vector<int> ans(n);
  // compute the result
  for (int i = 0; i < n; i++)
  {
    ans[i] = i - PGE[i];
  }
  return ans;
}