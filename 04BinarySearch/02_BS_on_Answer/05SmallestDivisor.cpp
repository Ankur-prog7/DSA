// Find the smallest divisor given a threshold

#include<bits/stdc++.h>
using namespace std;

int sumByD(vector<int>&a,int div){
  int sum=0;
  for (int i = 0; i < a.size(); i++)
  {
   sum = sum + ceil((double)(a[i])/(double)(div));
  }
  return sum;
}

int smallestDivisor(vector<int>&a,int limit){
  int n =a.size();
  // for case when their is no divisor
  if(n>limit) return -1;
  int low=1,high=*max_element(a.begin(),a.end());
  while(low<=high){
    int mid=(low+high)/2;
    if(sumByD(a,mid)<=limit){
      high=mid-1;
    }
    else{
      low=mid+1;
    }
  }
  return low;
}