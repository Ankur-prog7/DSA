// find the index by applying bs

  #include<bits/stdc++.h>
  using namespace std;
  // Iterative
  // int serach(vector<int>arr,int target){
  //   int n= arr.size();
  //   int low =0,high=n-1;
  //   while(low<=high){
  //   int mid = (low+high)/2;
  //     if(arr[mid]==target) return mid;
  //     else if(arr[mid]<target) return mid+1;
  //     else return mid-1;
  //   }
  //   return -1;
  // }

  // recursive
  int bs(vector<int>&arr,int low,int high,int target){
    if(low>high) return -1;
    int mid = (low+high)/2;
    if(arr[mid]==target) return mid;
    else if(target > arr[mid]) return bs(arr,mid+1,high,target);
    return bs(arr,low,mid-1,target);
  }
  int search(vector<int>&arr,int target){
  return bs(arr,0,arr.size()-1,target);
}
