#include<bits/stdc++.h>
using namespace std;
vector<int> sum(vector<int>arr,int n,int target){
  map<int,int>mpp;
  for(int i=0;i<n;i++){
    int a = arr[i];
    int more = target-a;
    if(mpp.find(more)!=mpp.end()){
      return {mpp[more],i};
    }
    mpp[a]=i;
  }
  return {-1,-1};
}