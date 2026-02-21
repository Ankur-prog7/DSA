// find peak elem in an array 
// if their are more than 1 peak elem then ans any one of them

#include<bits/stdc++.h>
using namespace std;

int findPeak(vector<int>&a){
  // to find all peak un comment the comments
  // vector<int>ans;
  int n = a.size();
  if(n==1) return 0;//ans.push_back(0)
  if(a[0]>a[1]) return 0;//ans.push_back(0)
  if(a[n-1]>a[n-2]) return n-1;//ans.push_back(n-1)

  int low=1,high=n-2;
  while (low<=high)
  {
    int mid = (low+high)/2;
    if(a[mid]>a[mid-1] && a[mid]>a[mid+1]){
      return mid;//ans.push_back(mid)
    }
    else if(a[mid] >a[mid-1]) low=mid+1;
    else high = mid-1;
  }
  return -1;//return ans;
}

int main(){
  vector<int>arr={7,8,9,1,2};
  cout<<findPeak(arr);
  return 0;
}