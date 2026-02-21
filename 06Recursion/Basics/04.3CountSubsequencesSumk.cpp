#include<bits/stdc++.h>
using namespace std;

int fun(int ind,int arr[],int n,int sum,int k){
  if(ind == n ){
    if(sum==k) return 1;
    else return 0 ;
  }
  sum += arr[ind];
  int l = fun(ind+1,arr,n,sum,k);

  sum -= arr[ind];
  int s = fun(ind+1,arr,n,sum,k);

  return l+s;
}

int main(){
  int arr[] = {1,2,1,4};
  int k,sum;
  int n = sizeof(arr)/sizeof(arr[0]);
  cin >> k;
  cout << fun(0,arr,n,0,k);
  return 0;
}