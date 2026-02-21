#include<bits/stdc++.h>
using namespace std;

int SearchFloor(vector<int>a,int n,int x){
  int ans=-1,low=0,high=n-1;//ans=-1 is diff here
  while(low<=high){
    int mid=(low+high)/2;
    if(a[mid]<=x){
      ans = a[mid];//and this line coz 
      low = mid+1;
    }
    else high=mid-1;
  }
  return ans;
}


int main() {
    vector<int> arr = {1, 2, 4, 6, 10};
    int x = 5;
    cout << "Floor of " << x << " is " << SearchFloor(arr, arr.size(), x);
    return 0;
}