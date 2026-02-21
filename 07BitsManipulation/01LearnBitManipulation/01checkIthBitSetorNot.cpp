// check ith bit is Set or not 
#include<bits/stdc++.h>
using namespace std;

bool isSet(int n,int x){
  return ((n&(1<<x))!=0);
}

int main(){
  int n = 10;
  int x =1;
  if(isSet(n,x)) cout << "set";
  else cout << "Bit is not set";
  return 0;
}


