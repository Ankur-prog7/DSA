#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>&a,int x){
  int n = a.size();
  int low =0,high=n-1,ans=n;
  while(low<=high){
    int mid=(low+high)/2;
    if(a[mid]>=x){
      ans = mid;
      high = mid-1;
    }
    else  low=mid+1;
  }
  return ans;
}

int UpperBound(vector<int>&a,int x){
  int n = a.size();
  int low=0,high=n-1,ans=n;
  while(low<=high){
    int mid =(low+high)/2;
    if(a[mid]>x){
      ans = mid;
      high = mid-1;
    }
    else{
      low = mid+1;
    }
  }
  return ans;
}

pair<int,int> firstAndLastPos(vector<int>&a,int x){
  int n =a.size();
  int lb = lowerBound(a,x);
  if(lb==n||a[lb]!=x) return {-1,-1};
  return {lb,UpperBound(a,x)-1};
}

int main(){
  vector<int>a={1,2,3,3,3,3,5,7,9};
  int x=3;
  pair<int,int> c = firstAndLastPos(a,x);
  cout << '{'<< c.first<< ','<< c.second<< '}' <<endl;
  
  return 0;
}