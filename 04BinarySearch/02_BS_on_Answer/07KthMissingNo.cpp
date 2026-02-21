// find out kth missing no

#include<bits/stdc++.h>
using namespace std;

int missing (vector<int>&a,int k){
  int n =a.size();
  int low =0,high = n-1;
  while (low<=high)
  {
    int mid = (low+high)/2;
    int miss = a[mid]-(mid+1);//current elem - acutal elem at that index
    if(miss < k){
      low=mid-1;
    }
    else{
      high = mid-1;
    }

  }
  return k+high+1;
}