// count the no of set bits
#include<bits/stdc++.h>
using namespace std;

int CountsetBits(int n){
  int cnt = 0;
  while(n){
    n = n&(n-1);
    cnt++;
  }
  return cnt;
}

int main(){
  int n;
  cin >> n;
  cout<< CountsetBits(n);
  return 0;
}