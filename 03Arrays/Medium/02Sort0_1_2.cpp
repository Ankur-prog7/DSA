// sort 0's,1's,2's
#include<bits/stdc++.h>
using namespace std;
void sorted(int arr[],int n){
  int low=0,mid =0,high=n-1;
  while(mid<=high){
    if(arr[mid]==0){
      swap(arr[mid],arr[low]);
      mid++;
      low++;

    }else if(arr[mid]==1){
      mid++;
    }
    else{
      swap(arr[mid],arr[high]);
      high--;
    
    }
  }
}
int main(){
  int arr[] = {2,1,0,0,1,1,2,0,1,0};
  int n = sizeof(arr)/sizeof(arr[0]);
  sorted(arr,n);
  for(int x : arr){
   cout << x <<endl;
  }
  
  return 0;
}