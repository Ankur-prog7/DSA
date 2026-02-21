// find how many times has an array been roated
// Ans:- index of min elem in sorted rotated array

#include<bits/stdc++.h>
using namespace std;

int NOofRotation(vector<int>&a,int x){
  int n = a.size();
  int low=0,high=n-1;
  int ans = INT_MAX;
  int index = -1;

  while (low<=high)
  {
    int mid = (low+high)/2;
    if(a[low]<=a[high]){
      if(a[low]<ans){
        index = low;
        ans =a[low];
      }
      break;
    }
    if(a[low]<=a[mid]){
      if(a[low]<ans){
        index = low;
        ans=a[low];
      }
      low=mid+1;
    }
    else{
      high=mid-1;
      if(a[mid]<ans){
        index = mid;
        ans = a[mid];
      }
    }
  }
  return index;
}

int main(){
  vector<int>arr={7,8,9,1,2,3,4,5,6};
  int x =8;
  cout<<NOofRotation(arr,x);
  return 0;
}