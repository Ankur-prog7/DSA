// find the row in 2d array with max 1

#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>arr,int n , int x){
int low=0,high =n-1;
int ans =n;

while(low<=high){
  int mid = (low+high)/2;
  if(arr[mid]>=x) {
    ans= mid;
    high = mid-1;
  }
  else{
    low = mid+1;
  }
}
return ans;
}

int rowWithMax(vector<vector<int>>&a,int n ,int m){
  int cnt_max = 0;
  int index = -1;
  for (int i = 0; i < n; i++)
  {
    int cnt_one = m-lowerBound(a[i],m,1);
    if(cnt_one>cnt_max) {
      cnt_max = cnt_one;
      index = i;
    }
  }
  return index;
}
