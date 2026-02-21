// Calculate and return the sum of all subarray ranges of nums.
#include<bits/stdc++.h>
using namespace std;

// funcn to find Next Greatest elem +++++++++++++++++
vector<int> findNSE(vector<int> &arr){
  int n = arr.size();

  // for ans
  vector<int>ans(n);

  stack<int>st;

  for (int i = n-1; i >= 0; i--)//change
  {
    while(!st.empty() && st.top()>=arr[i]){ //">="
      st.pop();
    }
    ans[i] = st.empty()?-1:st.top();

    st.push(arr[i]);
  }
  return ans;
}


// funcn to find Next Greatest elem +++++++++++++++++
vector<int> findNGE(vector<int> &arr){
  int n = arr.size();

  // for ans
  vector<int>ans(n);

  stack<int>st;

  for (int i = n-1; i >= 0; i--) //change
  {
    while(!st.empty() && st.top()<=arr[i]){ //"<=" is used
      st.pop();
    }
    ans[i] = st.empty()?-1:st.top();

    st.push(arr[i]);
  }
  return ans;
}

// funcn to find Previous Greatest elem +++++++++++++++++
vector<int> findPSE(vector<int> &arr){
  int n = arr.size();

  // for ans
  vector<int>ans(n);

  stack<int>st;

  for (int i = 0; i <= n-1; i++) //change 
  {
    while(!st.empty() && st.top() >=arr[i]){ //">" is used
      st.pop();
    }
    ans[i] = st.empty()?-1:st.top();

    st.push(arr[i]);
  }
  return ans;
}

// funcn to find Previous Smallest elem +++++++++++++++++
vector<int> findPGE(vector<int> &arr){
  int n = arr.size();

  // for ans
  vector<int>ans(n);

  stack<int>st;

  for (int i = 0; i <= n-1; i++) //bit of change
  {
    while(!st.empty() && st.top() <= arr[i]){ //'<=' is use
      st.pop();
    }
    ans[i] = st.empty()?-1:st.top();

    st.push(arr[i]);
  }
  return ans;
}

// funciton to find  min sum of subarray-----------------
long long sumSubarrayMins(vector<int> &arr) {
    
  vector<int> nse = findNSE(arr);
  
  vector<int> psee = findPSE(arr);
  
  // Size of array
  int n = arr.size();
  
  // To store the sum
  long long sum = 0;
  
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
    long long val = (freq*arr[i]*1LL);
    
    // Updating the sum
    sum += val;
  }
  
  // Return the computed sum
  return sum;
}


// funciton to find  max sum of subarray------------------
long long sumSubarrayMaxs(vector<int> &arr) {
    
  vector<int> ngse = findNGE(arr);
  
  vector<int> pgee = findPGE(arr);
  
  // Size of array
  int n = arr.size();
  
  // To store the sum
  long long sum = 0;
  
  // Traverse on the array
  for(int i=0; i < n; i++) {
      
    // Count of first type of subarrays
    int left = i - pgee[i];
    
    // Count of second type of subarrays
    int right = ngse[i] - i;
    
    /* Count of subarrays where 
    current element is minimum */
    long long freq = left*right*1LL;
    
    // Contribution due to current element 
    long long val = (freq*arr[i]*1LL);
    
    // Updating the sum
    sum += val;
  }
  
  // Return the computed sum
  return sum;
}


// function to find sum of ranges*******************
long long subArrayRanges(vector<int> &arr) {

// Return the result
return ( sumSubarrayMaxs(arr) - 
  sumSubarrayMins(arr) );
}
