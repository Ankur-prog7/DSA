// find the missing and repeating numbers

// using Xor and bits

#include<bits/stdc++.h>
using namespace std;

vector<int>find(vector<int>a){
  long long n =a.size();
  int xr = 0;
  for (int i = 0; i < n; i++){
    xr = xr^a[i];
    xr = xr^(i+1);
  }
  // normal way to find rightmost set bit
  // int bitNo = 0;
  // while(1){
  //   if(xr & (1<<bitNo)!=0 ){
  //     break;
  //   }
  //   bitNo++;
  // }

  // using bits manipulation
  int num = xr & ~(xr-1);
  int zero=0;
  int one =0;

  // divide array elem in two buckets
  for(int i=0;i<n;i++){
    // part of 1 club
    // if((a[i] & (1 << bitNo))!= 0 )
    if((a[i] & num )!= 0 )
    {
      one = one^a[i];
    }
    // part of 0 club
    else{
      zero = zero^a[i];
    }
  }

  // Divide numbers 1...n in two buckets
  for(int i =1;i<=n;i++){
    // part of 1 club
    if((i&num)!=0){
      one = one^i;
    }
    // part of 0 club
    else{
      zero=zero^i;
    }
  }
  int cnt=0;
  for(int i=0;i<n;i++){
    if(a[i] == zero) cnt++;
  }
  if(cnt==2) return {zero,one};//repeating ,missing
  return {one,zero};
}