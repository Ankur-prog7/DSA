#include<bits/stdc++.h>
using namespace std;

void countFreq(int arr[],int n){
  vector<bool>visited (n,false);
  for(int i =0;i<n;i++){
    if(visited[i]==true){
      continue;
    }

    int count = 1;
    for(int j=i+1;j<n;j++){
      if(arr[i]==arr[j]){
        visited[j] = true;
        count++;
      }
    }
    cout <<arr[i]<< "->" <<count <<endl;
  }
}

int main(){
  cout<< "Enter no of elem of array"<< endl;
  int n ;
  cin>>n;
  int arr[n];
  cout<< "Enter  elem of array"<< endl;
  for(int i =0 ;i<n;i++){
    cin >> arr[i];
  } 
  countFreq(arr,n);
  
  return 0;
}