#include<bits/stdc++.h>
using namespace std;

void freq(int arr[] , int n){
   
  int minEle=0,minFreq=n,maxEle=0,maxFreq =0;

   
  unordered_map<int,int> mpp;
  for(int i=0;i<n;i++){
     mpp[arr[i]]++;
  }

  for(auto it:mpp){
    int count= it.first;
    int elem = it.second;

    if(count > maxFreq){
      maxEle = elem;
      maxFreq = count;
    }

    if(count < minFreq){
      minEle = elem;
      minFreq = count;
    }
  }
    cout<< "highest freq of elem " <<maxEle << "->" << maxFreq << endl;
    cout<< "lowest freq of elem " <<minEle<< "->" << minFreq << endl;
}

int  main(){
  int arr[]={2,1,4,1,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  freq(arr,n);
  return 0;
}