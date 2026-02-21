// check is no is power of 2 or not
#include<bits/stdc++.h>
using namespace std;
 
bool isPowerof2(int N){
  return (N&(N-1))==0;
}

int main(){
  int n;
  cin >> n;
  if(isPowerof2(n)) cout<<  "power of 2";
  else cout<< "Not power of 2";
  return 0;
}