// number of sub array with xor k
// a xor a = 0
#include<bits/stdc++.h>
using namespace std;

int subArray(vector<int> a,int k){
  int xr = 0;
  map<int,int>mpp;
  mpp[xr]++; //It increases the frequency (count) of the element xr.
  int cnt = 0;
  for(int i=0;i<a.size();i++){
    xr = xr^a[i];
    int x = xr ^ k;
    cnt += mpp[x];//Add how many times the value x has appeared before.
    mpp[xr]++;//Add how many times the value x has appeared before.
  }
  return cnt;
}

int main(){
  vector<int>a = {2,4,1,3,8,5,6};
  int target;
  cin >> target;
  cout << subArray(a,target);
  cout<<endl;
  return 0;
}