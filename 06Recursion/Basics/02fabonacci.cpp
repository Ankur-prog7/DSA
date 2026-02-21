#include<bits/stdc++.h>
using namespace std;

int fun(int n){
  if(n<=1) return n;
  return fun(n-1)+fun(n-2); //fun(n-2) runs only after fun(n-1) finishes and returns a value.
}

int main(){
  int a;
  cin>>a;
  cout<<fun(a);
  return 0;
}
// at n=4; OUTPUT =3
// 0 1 1 2 3 , therefor at n = 4 we are getting 3
