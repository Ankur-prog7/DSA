// print 1st subsequence whose sum is k
#include<bits/stdc++.h>
using namespace std;

bool fun(int ind, vector<int>&a,int arr[],int n , int sum,int k){
  if(ind == n ){
    if(sum==k){
      for(auto it:a){
        cout<< it << " ";
      }
      cout << endl;
      return true;
    }
    else return false;
  }
  // take
  a.push_back(arr[ind]);
  sum += arr[ind];
  if(fun(ind+1,a,arr,n,sum,k)==true) return true;
  
  //  not take 
  a.pop_back(); // here order of sum and pop wll not matter because pop will remove from 'a' ,and sum - will subtract the sum from elem of arr 
  sum -= arr[ind];
  if(fun(ind+1,a,arr,n,sum,k) == true ) return true; //this will only run if 1st call will return false
  
  return false;
}

int main(){
  int k;
  vector<int>a;
  int arr[] = {1,2,1,4};
  int n = sizeof(arr)/sizeof(arr[0]);
  cin >> k; //btw 1-4
  int sum = 0 ;
  fun(0,a,arr,n,0,k);
  return 0;
}
