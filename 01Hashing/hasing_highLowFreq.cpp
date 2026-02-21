#include<bits/stdc++.h>
using namespace std;

void freq(int arr[], int n ){

  int minEle = 0,maxEle =0,minFreq =0, maxFreq=n;
  vector<bool> visited (n,false);

  for(int i =0;i<n;i++){
    if(visited[i]==true){
      continue;
    }
    int count = 1;
    for(int j = i+1;j<n;j++){
      if(arr[i]==arr[j]){
        visited[j]=true;
        count++;
      }
    }
    cout << arr[i] << "->" << count << endl;

    if(count > maxFreq){
      maxEle = arr[i];
      maxFreq = count;
    }

    if(count < minFreq){
      minEle = arr[i];
      minFreq = count;
    }
  }
  cout << "Highest freq of element "<< maxEle << "->" << maxFreq<<endl;
  cout << "Lowest freq of element "<< minEle << "->" << minFreq<<endl;
}

int main(){

  int arr [] = {1,2,13,4,1};
  int n = sizeof(arr)/sizeof(arr[0]);
  freq(arr,n);

  return 0;

}