// pow(x,n) , pow(2,10)=2^10=1024
#include<bits/stdc++.h>
using namespace std;

double myPow(double x,int n){
  double ans =1.0;
  long long nn = n;
  if(nn<0)nn = -1*nn;
  while(nn>0){
    if(nn%2){
      ans = ans*x;//2^5 --> ans = 1*2
      nn = nn-1;
    }
    else{
      x = x*x;
      nn= nn/2;
    }
  }
  if(n<0)ans = 1.0/ans;
  return ans;
}

int main(){
  double x = 2;
  int n = 5;
  cout << myPow(x,n);
  return 0;
}