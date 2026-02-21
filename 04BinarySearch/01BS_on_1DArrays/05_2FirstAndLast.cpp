// using binary search
#include<bits/stdc++.h>
using namespace std;

int firstOccur(vector<int>arr,int x){
  int n = arr.size();
  int low=0,high=n-1,first=-1;
  while(low<=high){
    int mid= (low+high)/2;
    if(arr[mid]==x) {
      first = mid;
      high =mid-1;
    }
    else if(arr[mid]<x) high=mid-1;
    else low=mid+1;
  }
  return first;
}
int lastOccur(vector<int>arr,int x){
  int n =  arr.size();
  int low=0,high =n-1,last=-1;
  while(low<=high){
    int mid=(low+high)/2;
    if(arr[mid]==x){
      last = mid ;
      low=mid+1;
    }
    else if(arr[mid]>x) low =mid+1;
    else high = mid-1;
  }
  return last;
}

pair<int,int>ans(vector<int>a,int x){
  int first = firstOccur(a,x);
  if(first == -1) return {-1,-1};
  int last = lastOccur(a,x);
  return {first,last};
}

int main(){
  vector<int>a={1,2,3,4,4,4,5,8};
  int x =4;
  pair<int,int> c = ans(a,x);
  cout <<'{'<<c.first<<','<<c.second<<'}'<<endl;
  return 0;
}