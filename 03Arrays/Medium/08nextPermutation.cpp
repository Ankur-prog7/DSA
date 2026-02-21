#include<bits/stdc++.h>
using namespace std;
vector<int>nextPermn(vector<int> &A){
  int ind =-1;
  int n = A.size();
  // Step 1: Find the first decreasing element from the end
  for(int i = n-2;i>=0;i--){
    if(A[i]<A[i+1]){
      ind = i;
      break;
    }
  }
  // Step 2: If no such element found → array is in descending order
  if(ind == -1){
    reverse(A.begin(),A.end());
      return A;
    }
  // Step 3: Find the smallest element greater than A[ind] from the end
  for(int i = n-1;i>ind;i--){
    if(A[i]>A[ind]){
      swap(A[i],A[ind]);
      break;
    }
    }
  // Step 4: Reverse the right part
  reverse(A.begin()+ ind+1,A.end());
  return A;
}
