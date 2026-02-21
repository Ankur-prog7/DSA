// return the min integer K such that KOKo can eat all bananas within h hours 

#include<bits/stdc++.h>
using namespace std;
//finding max elem in array
int findMax(vector<int>&a){
  int maxi = INT_MIN;
  int n= a.size();
  for (int i = 0; i < n; i++)
  {
    maxi = max(maxi,a[i]);
  }
  return maxi;
}



//total time taken by koko to eat  bananas
int CalcTotalHrs(vector<int>&a,int h){
  int totalH =0;
  int n=a.size();
  for (int i = 0; i < n; i++)
  {
    totalH += ceil((double)a[i]/(double)h);//Useful when you want accurate results instead of integer division.
  }
  return totalH;
}

int minRateToEatBananas(vector<int>a,int h){
  int low=1,high=findMax(a);
  while(low<=high){
    int mid = (low+high)/2;
    int totalH = CalcTotalHrs(a,mid);
    if(totalH<=h){
      high=mid-1;
    }
    else{
      low=mid+1;
    }
  }
  return low;
}


// NOTE (double)a → 5.0
// (double)h → 2.0
// ceil(13 / 5) = ceil(2.6) = 3 hours
