#include<bits/stdc++.h>
using namespace std;
void smallest(int arr[],int n){
  int smallEle = INT_MAX;
  int SecondSmallELe=INT_MAX;
  for(int i = 0;i<n;i++){
    if(arr[i]<smallEle){
      SecondSmallELe=smallEle;
      smallEle=arr[i];
    }
    else if(smallEle<arr[i] && SecondSmallELe>arr[i]) {SecondSmallELe=arr[i];}
  }
    cout << "Smallest element: " << smallEle << endl;
    if (SecondSmallELe == INT_MAX)
      cout << "No second smallest element exists." << endl;
    else
      cout << "Second smallest element: " << SecondSmallELe << endl;
}

  

int main(){
  int arr[] = {1,4,2,5,6,7,3};
  int n= sizeof(arr)/sizeof(arr[0]);
  smallest(arr,n);

  return 0;
}