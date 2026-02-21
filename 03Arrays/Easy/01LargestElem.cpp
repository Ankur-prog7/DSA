// Largest Elem in array
#include<bits/stdc++.h>
using namespace std;

int largest(int arr[],int n){
  int lar =0;
  for(int i=0;i<n;i++){
    if(arr[i]>lar){
      lar = arr[i];
    }
  }
  return lar;
}
int main(){
  int arr[] = {1,2,4,7,3,9,5,15,2};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout << largest(arr,n) << endl;
  return 0;
}