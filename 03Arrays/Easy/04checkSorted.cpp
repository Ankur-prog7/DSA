#include<bits/stdc++.h>
using namespace std;

bool Sortedcheck(int arr[],int n){
  for (int i = 0; i < n; i++)
  {
    if(arr[i] > arr[i+1]){
      return false;
    }
  }
  return true;
}

// remove duplicates in sorted array  2,3,3,4,5 ------------------IMP------------
int removeDuplicate(int arr[],int n){
  if (n==0) return 0;
  int j = 0;
  for (int i = 0; i < n; i++)
  {
    if(arr[i] != arr[i+1]){

      arr[j] = arr[i];
      j++;
    }
  }
  return j;
}
// move zeroes to end 3 0 4 0 5 --> 3 4 5 0 0
int moveZeroToEnd(int arr[],int n){
  int j = 0;
  for(int i = 0 ; i<n ; i++){
    if(arr[i]!=0){
      swap(arr[i],arr[j]);
      j++;
    } 
    
  }
  return j;
}


int main(){
  int arr[] = {1,0,2,0,4,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  int newlen = removeDuplicate(arr,n);
  moveZeroToEnd(arr,n);
  
  // if(Sortedcheck(arr,n)==false) cout << "False";
  // else cout<<"True";
  for (int i = 0; i < n; i++)
  {
     cout << arr[i];
  }
  
  return 0;
}

