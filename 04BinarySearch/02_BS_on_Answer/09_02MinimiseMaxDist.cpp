// ****************    HARD      ************************
// Minimise max distance btw gas stations


#include<bits/stdc++.h>
using namespace std;

int numOfGasStationReqd(long double dist,vector<int>&a){
  int cnt=0;
  for (int i = 0; i < a.size(); i++)
  {
    int numInBtw =((a[i]-a[i-1])/dist);
    if((a[i]-a[i-1])/dist == numInBtw*dist){
      numInBtw--;
    }
    cnt+=numInBtw;
  }
  return cnt;
}

long double minimiseMaxDist(vector<int>&a,int k){
  int n=a.size();
  long double low=0;
  long double high= 0;
  for (int i = 0; i < n-1; i++)
  {
    high = max(high,(long double)(a[i+1]-a[i]));
  }
  
  long double diff = 1e-6;
  while(high-low>diff){
    long double mid = (low+high)/(2.0);
    int cnt = numOfGasStationReqd(mid,a);
    if(cnt>k){
      low=mid;
    }
    else{
      high=mid;
    }
  }
  return high;
}