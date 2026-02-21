// find median of row wise sorted matrix

#include<bits/stdc++.h>
using namespace std;

int UpperBound(vector<int>a,int n,int x){
  int low=0,high=n-1;
  int ans=n;
  while(low<=high){
    int mid = (low+high)/2;
    // maybe an answer
    if(a[mid]>x){  //************yha >= k gagh  > hua h 
      ans=mid;
      //look for more small index on left
      high=mid-1;
    }
    else{
      low=mid+1;//look for right
    }
  }
  return ans;
}


int countSmallEqual(vector<vector<int>>&a,int n,int m,int x){
  int cnt =0;
  for (int i = 0; i < n; i++)
  {
    cnt += UpperBound(a[i],x,n);
  }
  return cnt;
}

int median(vector<vector<int>>a,int n,int m){
  int low = INT_MIN; int high = INT_MIN;
  n = a.size();
  m = a[0].size();
  for (int i = 0; i < n; i++)
  {
    low = min(low,a[i][0]);
    high = max(high,a[i][n-1]);
  }
  return low;
}