// find Nth root of M
#include<bits/stdc++.h>
using namespace std;
// this code fot m^n and include overflow cases
int func(int mid,int n,int m){
  long long ans=1;
  for (int i = 0; i <=n; i++)
  {
    ans = ans*mid;
    if(ans>m) return 2;
  }
  if(ans==m) return 1;
  return 0;
}

/* mid^n
int funcn(int mid,int n){
long long ans =1;
while(n>0){
if(n>0){
if(n%2==1){
ans = ans*mid;
n--; 
}
else{
mid = mid*mid;
n=n/2;}
}
}return ans;
}
*/

int NthRoot(int n,int m){
  int low=1,high =m;
  while(low<=high){
    int mid = (low+high)/2;
    int midN = func(mid,n,m);
    if(midN==1){
      return mid;
    }
    else if(midN==0) low=mid+1;
    else high = mid-1;
  }
  return -1;
}

