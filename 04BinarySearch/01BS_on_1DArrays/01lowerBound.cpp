#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>a,int n,int x){
  int low=0,high=n-1;
  int ans=n;
  while(low<=high){
    int mid = (low+high)/2;
    // maybe an answer
    if(a[mid]>=x){
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