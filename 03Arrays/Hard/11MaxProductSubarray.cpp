// find max product subarray


#include<bits/stdc++.h>
using namespace std;
int subArray(vector<int>&arr){
  int pre=1,suff=1;
  int ans = INT_MIN;
  int n = arr.size();
  for(int i=0;i<n;i++){
    if(pre==0)pre =1;
    if(suff == 0) suff=1;

    pre=pre*arr[i];
    suff=suff*arr[n-1-i];
    ans=max(ans,max(pre,suff));
  }
  return ans;
}

int main(){
  vector<int>a={1,4,-2,0,5,3};
  int t = subArray(a);
  // for(auto x:t)
  cout<<t;
}