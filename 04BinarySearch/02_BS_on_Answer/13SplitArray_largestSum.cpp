//   concept is same as old question painter partition

#include<bits/stdc++.h>
using namespace std;

int cntStud(vector<int>&a,int pages){
  int stud =1;
  long long pageStud=0;
  for (int i = 0; i < a.size(); i++)
  {
    if(pageStud+a[i]<=pages) pageStud += a[i];
    else {
      stud += 1;
      pageStud = a[i];
    }
  }
  return stud;
}

int findPage(vector<int>&arr,int n ,int m){
  if(m>n) return -1; //when  book is more than no of stud
  int low = *max_element(arr.begin(),arr.end());
  int high = accumulate(arr.begin(),arr.end(),0);
  while(low<=high){
   int mid = (low+high)/2;
   int stud = cntStud(arr,mid);
    if(stud>n){
      low=mid+1;
    }
    else{
      high =mid-1;
    }
  }
  return low;
}

// this is diff from old

int findLargestSumMinimized(vector<int>&a,int k){
  return findPage(a,a.size(),k);
}