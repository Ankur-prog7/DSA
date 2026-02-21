// minimum in roated sorted array
#include<bits/stdc++.h>
using namespace std;  

int findMin(vector<int>&a,int x){
  int n = a.size();
  int ans =INT_MAX;
  int low=0,high=n-1;
  while(low<=high){
    int mid = (low+high)/2;
    if(a[low]<a[high]){ // if array is sorted 
      ans=min(ans,a[low]);
      break;
    }
    if(a[low]<=a[mid]){
      ans = min(ans,a[low]);
      low=mid+1;//so that we can shift to another part to check for min
    }
    else{
      high = mid-1;//so that we can shift to another part to check for min
      ans = min(ans,a[mid]);
    }
  }
  return ans;
}

int main(){
  vector<int>arr={7,8,9,1,2,3,4,5,6};
  int x =8;
  cout<<findMin(arr,x);
  return 0;
}