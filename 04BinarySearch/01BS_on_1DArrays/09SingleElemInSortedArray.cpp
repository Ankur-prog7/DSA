// find single elem in sorted array
// other elem will be in couple and in sorted order

#include<bits/stdc++.h>
using namespace std;

int findUnique(vector<int>&a,int x){
  int n =a.size();
  if(n==1) return a[0];
  if(a[0]!=a[1]) return a[0];
  if(a[n-1]!=a[n-2]) return a[n-1];

  int low=1,high=n-2;
  while (low<=high)
  {
    int mid = (low+high)/2;
    if(a[mid] != a[mid+1] && a[mid] != a[mid-1]){
      return a[mid];
    }
    // we are in left   ******* doubt******
    if((mid%2==1 && a[mid]==a[mid-1])|| (mid%2==0 && a[mid]==a[mid+1])){
      low = mid+1;
    }
    //we are on right
    else{
      high = mid-1;
    }
  }
  return -1;
}


int main(){
  vector<int>arr={1,1,2,2,3,3,4,5,5,6,6};
  int x =8;
  cout<<findUnique(arr,x);
  return 0;
}