// print all subsequence whose sum is k
#include<bits/stdc++.h>
using namespace std;

void fun(int ind,vector<int>&a,int arr[],int n,int k,int sum){
  // int sum=0; if ye yaha rha toh hrr baar ye 0 set hoga
  if(ind == n ){
    if(sum == k){
      for(auto it:a){
        cout << it << " ";
      }  
      cout<<endl; 
    }
    return;
  }
  //take
  a.push_back(arr[ind]);
  sum += arr[ind];
  fun(ind+1,a,arr,n,k,sum);
  //not take
  a.pop_back();
  sum -= arr[ind];
  fun(ind+1,a,arr,n,k,sum);
}

int main(){
  int k;
  vector<int>a;
  int arr[] = {1,2,1,4};
  int n = sizeof(arr)/sizeof(arr[0]);
  cin >> k; //btw 1-4
  int sum = 0 ;
  fun(0,a,arr,n,k,0);
  return 0;
}