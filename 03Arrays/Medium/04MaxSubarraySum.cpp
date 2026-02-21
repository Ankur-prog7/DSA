// ****************************************************** Kadane's Algorithm ********************************************************************
#include<bits/stdc++.h>
using namespace std;

long long sum(int arr[],int n){
  long long sum =0 ;
  int maxi = LONG_MIN;
  int ansStart = -1,ansEnd=-1,start =0;
  for(int i=0;i<n;i++){
    if(sum==0)  start=i;  // potential new subarray start
    sum += arr[i]; //adds the current elem
  if(sum>maxi){ maxi=sum; //update maximum
    ansStart=start; //mark sub arry start
    ansEnd = i;} //mark subArray End
    if(sum<0) sum =0;//reset if sum is negative
  }
   for (int i = ansStart; i <= ansEnd; i++){
    cout << arr[i] << " ";
   }
   cout << endl;
  return maxi;
} 

int main(){
  int a[]={1,-4,2,5,-1,-3,9,-2};
  int n = sizeof(a)/sizeof(a[0]);
  cout << sum(a,n)<<endl;

}