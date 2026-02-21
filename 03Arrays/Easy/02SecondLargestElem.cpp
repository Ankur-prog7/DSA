// Second largest Elem in unsorted array
#include<bits/stdc++.h>
using namespace std;

int slargest(int arr[],int n){
  int lar =INT_MIN, seclar=INT_MIN;
  for(int i=0;i<n;i++){
    if(arr[i]>lar){
      seclar=lar;
      lar=arr[i];
    }
    else if(arr[i]<lar && arr[i]>seclar){ seclar=arr[i];}
  }
  return seclar;
  
}

int main(){
  int arr[] = {1,4,2,5,6,7,3};
  int n= sizeof(arr)/sizeof(arr[0]);
  cout << slargest(arr,n)<<endl;

  return 0;
}