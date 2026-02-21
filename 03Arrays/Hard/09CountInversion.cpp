// count inversion in an Array where i<j & a[i]>a[j]
// algo of merge sort is used here

#include<bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr,int low,int mid,int high){
  vector<int> temp;
  int left = low;
  int right = mid+1;

  int cnt = 0;
  while(left <= mid && right <=high){
    if(arr[left] <= arr[right]){
      temp.push_back(arr[left]);
      left++;
    }
    else{
      temp.push_back(arr[right]);
      cnt += (mid-left+1);
      right++;
    }
  }
  while(left<=mid){
    temp.push_back(arr[left]);
    left++;
  }
  while(right<=high){
    temp.push_back(arr[right]);
    right++;
  }
  for(int i=low;i<=high;i++){
    arr[i] = temp[i-low];  //here i will goes like low+1,low+2...
  }
  return cnt;
}
int mS(vector<int> &arr,int low,int high){
  int cnt = 0;
  if(low >= high) return 0;
  int mid = (low + high)/2;
  cnt += mS(arr,low,mid);
  cnt+= mS(arr,mid+1,high);
  cnt+= merge(arr,low,mid,high);
  return cnt;  
}

int numberOfInversion(vector<int>&a){
 return mS(a,0,a.size()-1);
}

int main(){
  vector<int> arr = {5,2,8,1,4};
  int inverse=numberOfInversion(arr);

  cout << "Inversion Count = " << inverse << endl;

  for(auto x:arr)
  cout << x <<" ";
  cout << endl;
  return 0;
}