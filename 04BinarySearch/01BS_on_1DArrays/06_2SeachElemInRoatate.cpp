//Search elem in roateed elem with duplicate
#include<bits/stdc++.h>
using namespace std;

bool search(vector<int>&a,int x){
  int n = a.size();
  int low=0,high=n-1;
  while (low<=high){
    int mid =(low+high)/2;
    // for duplicate elem
    if(a[low]==a[mid] && a[mid]==a[high]){
      // if (a[low] == x) return low;      // check before skip
      // if (a[high] == x) return high;    // check before skip
      low++;
      high--;
      continue;
    }
    if(a[mid]==x) return true;
    if (a[low]<=a[mid]){
      if(a[low]<=x && a[mid]>=x){
        high = mid-1;
      }
      else{
        low = mid+1;
      }
    }
    else{
      if(a[mid]<=x && a[high]>=x){
        low = mid+1;
      }
      else{
        high = mid-1;
      }
    }
  }
  return false;
}

int main(){
  vector<int>arr={3,2,1,3,3,3};//this array is properly roated with duplicate elem but {3,2,1,3,3,3} is not coz rotated sorted coz mid is pointing to 1 so it makes right part increasing and left part decreasing
  int x =1;
  cout<<search(arr,x);
  return 0;
}