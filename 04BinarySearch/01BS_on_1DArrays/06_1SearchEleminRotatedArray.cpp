// Search elem in rotated array for unique elem
#include<bits/stdc++.h>
using namespace std;

int search(vector<int>&a,int x){
  int n = a.size();
  int low=0,high=n-1;
  while(low<=high){
    int mid=(low+high)/2;
    if(a[mid]==x) return mid; // dhyan dena idhr lala
    if(a[low]<=a[mid]){
      if(a[low]<=x && x<=a[mid]){
        high=mid-1;
      }
      else{
        low=mid+1;
      }
    }
    else{
      if(a[mid]<=x && a[high]>=x){
        low=mid+1;
      }
      else{
        high = mid-1;
      }
    }
  }
  return -1;
}

int main(){
  vector<int>arr={7,8,9,1,2,3,4,5,6};
  int x =8;
  cout<<search(arr,x);
  return 0;
}