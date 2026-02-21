// ******************************************************* Moore's Voting Algorithm *************************************************************
// if elem appear more than N/2 where N is length of array
#include<bits/stdc++.h>
using namespace std;
int majority(vector<int>&arr){
  int cnt =0;
  int el;
  for(int i=0;i<arr.size();i++){
    if(cnt == 0){ //in loop starting
      el=arr[i];
      cnt =1;
    }
    else if(arr[i]==el) cnt++; //if next elemnt is same as prev
    else cnt--;
    // till here we have - find a candidate that might be the majority element
  }

  // suppose {1,2,3} then cnt have value 1 yoh first loop usko majority declare krega   so to verify actually
  //  second loop will tell 3 occur 1 time and 1>3/2 --> therefore  false 
  int cnt1=0;
  for(int i=0;i<arr.size();i++){
    if(arr[i]==el) cnt1++;
  }
  if(cnt1>(arr.size())/2 ) return el;
  return -1;
}

int main(){
  vector<int>a={1,2,4,1,1,1,2,1};
  cout<<majority(a) << endl;
}