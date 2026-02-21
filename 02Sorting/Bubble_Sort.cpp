#include<bits/stdc++.h>
using namespace std;

void bubble(int arr[],int n){
    for(int i=n-1;i>=1;i--){
      for(int j=0;j<=i-1;j++){
        if(arr[j]>arr[j+1]){
          int temp = arr[j+1];
          arr[j+1]=arr[j];
          arr[j]=temp;
        }
      }
    }
}

int main(){
    int arr[]= {2,23,4,3,1};
    int n= sizeof(arr)/sizeof(arr[0]);
    bubble(arr,n);
    for(int i=0;i<n;i++){
      cout<< arr[i]<<" ";
    }
  return 0;
} 