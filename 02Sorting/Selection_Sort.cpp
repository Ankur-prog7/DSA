#include<bits/stdc++.h>
using namespace std;

void sele(int arr[],int n){
  for(int i=0;i<=n-2;i++){
    int min = i;

    for(int j=i+1;j<n;j++){
      if(arr[j]<arr[min]){
       min =j;
      }

    }
     int temp = arr[min];
      arr[min]=arr[i];
      arr[i]=temp;
  }
}

int main(){
  int arr[] = {6,4,5,2,9};
  int n = sizeof(arr)/sizeof(arr[0]);
  sele(arr,n);
  for(int i=0;i<n;i++){
    cout << arr[i] <<" ";
  }
 return 0;
}