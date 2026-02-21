// find least capacity to ship the packages within D days

#include<bits/stdc++.h>
using namespace std;

int findDays(vector<int>&weight,int cap){
  int days =1,load=0;
  for (int i = 0; i < weight.size(); i++)
  {
    if(weight[i]+load>cap){
      days+=1;
      load=weight[i];
    }
    else{
      load+= weight[i];
    }
  }
  return days;
}

int leastWeightCap(vector<int>&weig,int d){
  int low =*max_element(weig.begin(),weig.end());
  int high =accumulate(weig.begin(),weig.end(),0);
  while(low<=high){
    int mid=(low+high)/2;
    int numOfDays = findDays(weig,mid);
    if(numOfDays<=d){
      high = mid-1;
    }
    else{
      low=mid+1;
    }
  }
  return low;
}