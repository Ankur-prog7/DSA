// find  max no or integer which on squaring <=n
// find floor of sqrt using BS

#include<bits/stdc++.h>
using namespace std;

int SquareRoot(int x){
  int low=1,high=x;
  while(low<=high){
    long long mid = (low+high)/2;
    long long square = (mid*mid);
    if(square<=x){
      low=mid+1;
    }
    else{
      high=mid-1;
    }
  }
  return high;
}

int main(){
  int x=18;
  cout<<SquareRoot(x);
  return 0;
}