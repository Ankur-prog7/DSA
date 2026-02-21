// find the no that appears odd number of times 
#include<bits/stdc++.h>
using namespace std;

int SingleNo(vector<int>&a){
  int Xor = 0;
  for (int i = 0; i < a.size(); i++)
  {
    Xor ^= a[i]; 
  }
  return Xor;
}
int main(){
  vector<int> a = {1,2,2,1,5,4,3,3,4};
  cout<<SingleNo(a);
  return 0;
}