// set/uunset the rightmost unset bit

#include<bits/stdc++.h>
using namespace std;

int UnsetRightMostBit(int n){
  return (n&n-1);
}
int setRightMostBit(int n){
  return (n|1);
}

int main(){
  int n;
  cin >> n;
  cout << UnsetRightMostBit(n)<<endl;
  cout<< setRightMostBit(n);
  return 0;
}