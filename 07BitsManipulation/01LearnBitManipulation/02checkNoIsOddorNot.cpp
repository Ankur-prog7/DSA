// check if a no is odd or not
#include<bits/stdc++.h>
using namespace std;

bool isOdd(int n){
  return (n&1);
}

int main(){
  int n = 3;
  if(isOdd(n)) cout << "odd";
  else cout << "even";
  return 0;
}
