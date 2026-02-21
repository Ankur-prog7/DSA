// Use a stack to find the index of the next smaller element to the right for each position

#include<bits/stdc++.h>
using namespace std;

vector<int> findNSE(vector<int> &arr){
  int n = arr.size();

  // for ans
  vector<int>ans(n);

  stack<int>st;

  for (int i = n-1; i >= 0; i--)
  {
    while(!st.empty() && st.top()>=arr[i]){
      st.pop();
    }
    ans[i] = st.empty()?-1:st.top();

    st.push(arr[i]);
  }
  return ans;
}

vector<int> findPSE(vector<int> &arr){
  int n = arr.size();

  // for ans
  vector<int>ans(n);

  stack<int>st;

  for (int i = 0; i <= n-1; i++)
  {
    while(!st.empty() && st.top() >=arr[i]){
      st.pop();
    }
    ans[i] = st.empty()?-1:st.top();

    st.push(arr[i]);
  }
  return ans;
}

int sumSubarrayMins(vector<int> &arr) {
      
  vector<int> nse = 
    findNSE(arr);
  
  vector<int> psee =
    findPSE(arr);
  
  // Size of array
  int n = arr.size();
  
  int mod = 1e9 + 7; // Mod value
  
  // To store the sum
  int sum = 0;
  
  // Traverse on the array
  for(int i=0; i < n; i++) {
      
    // Count of first type of subarrays
    int left = i - psee[i];
    
    // Count of second type of subarrays
    int right = nse[i] - i;
    
    /* Count of subarrays where 
    current element is minimum */
    long long freq = left*right*1LL;
    
    // Contribution due to current element 
    int val = (freq*arr[i]*1LL) % mod;
    
    // Updating the sum
    sum = (sum + val) % mod;
  }
  
  // Return the computed sum
  return sum;
  }