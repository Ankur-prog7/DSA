// find min no of days to make M bouquets
#include<bits/stdc++.h>
using namespace std;

bool Possible(vector<int>&a,int day,int m,int k){
  int cnt=0, noOfB=0;
  for (int i = 0; i < a.size(); i++)
  {
    if(a[i]<=day) { cnt++;}
    else{
      noOfB += (cnt/k);
      cnt=0;
    }
  }
  noOfB += (cnt/k);
  return noOfB>=m; //returns either true or false.
  // If noOfB ≥ m → it returns true
}

int roseGarden(vector<int>&a,int r,int b){

  // 1LL converts the whole multiplication chain to long long
  long long val = r*1LL*b;//this line is forcing the entire multiplication to be done in long long to avoid integer overflow.
  if(val>a.size()) return -1;
  int mini = INT_MAX,maxi=INT_MIN;
  for (int i = 0; i < a.size(); i++)
  {
  mini =min(mini,a[i]);
  maxi=max(maxi,a[i]);
  }
  int low=mini,high =maxi;
  while(low<=high){
    int mid=(low+high)/2;
    if(Possible(a,mid,r,b)){
      high = mid-1;
    }
    else low =mid+1;
  }
  return low;
}



// NOTE  if r and b are int, then to convert it into long long we use 1LL*a*b

// or long long val = (long long)r * b;
