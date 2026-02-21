// find the missing no
// a[] = {1,2,3,5};
#include<bits/stdc++.h>
using namespace std;


int missing(int arr[],int n){
  int sum = (n+1)*(n+2)/2;
  int arrSum = 0;
  for (int i = 0; i < n; i++)
  {
    arrSum += arr[i];
  }
  int missNo = sum - arrSum;
  return missNo;
}

// unique no in arr
int unique(int arr1[],int n){
  int a =0 ;
  for (int i = 0; i <= n-1; i++){
    a ^= arr1[i];
  }
  return a;
}

// Two sum
bool TwoSum(int arr2[],int n,int k){ //7 -1 = 
  int more ;
  for (int i = 0; i < n; i++)
  {
    int a = arr2[i];
    more = k - a;
  }
  for (int j= 0; j < n; j++)
  {
    if(arr2[j] == more) return true;
  }
  
  return false;
}



int main(){
  // int arr[] = {1,2,3,5};
  int arr1[] = {1,2,7,7,6,2,1};
  int arr2[] = {1,2,4,5,3};
  int k = 7;
  int n = sizeof(arr2)/sizeof(arr2[0]);
  // int ans = missing(arr,n)
  // cout << ans;
  // int ans = unique(arr1,n);
  int ans = TwoSum(arr2,n,k);
  cout <<ans;
  return 0;
}