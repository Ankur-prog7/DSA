#include<bits/stdc++.h>
using namespace std;

bool fun(int i,string a){
  if(i >= a.size()/2) return true;
  if(a[i]!=a[a.size()-i-1]) return false;
  return fun(i+1,a);
}

int main(){
  string a = "MADSM";
  bool ans = fun(0,a);
  cout<< (ans?"true":"false");
  // cout<<boolalpha<<ans;
  return 0;
}