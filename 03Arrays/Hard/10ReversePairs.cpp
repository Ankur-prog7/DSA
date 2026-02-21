//reversw elem 
// condition--> i<j && a[i]>2*a[j]
// here merge sort algo is use

#include<bits/stdc++.h>
using namespace std;

  int cnt=0;
  void merge(vector<int> &arr,int low,int mid,int high){
  vector<int> temp;
  int left = low;
  int right = mid+1;
  while(left <= mid && right <=high){
    if(arr[left] <= arr[right]){
      temp.push_back(arr[left]);
      left++;
    }
    else{
      temp.push_back(arr[right]);
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
}
int counPairs(vector<int>&a,int low,int mid,int high ){
  int right = mid+1;
  int cnt = 0;
  for (int i = low; i <= mid; i++)
  {
    while(right<= high && a[i]>2*a[right]) right++;
    cnt += (right -(mid+1));
  }
  return cnt;
}
int mS(vector<int> &arr,int low,int high){
  int cnt=0;
  if(low >= high) return cnt;
  int mid = (low + high)/2;
  cnt+=mS(arr,low,mid);
  cnt+=mS(arr,mid+1,high);
  cnt+=counPairs(arr,low,mid,high);
  merge(arr,low,mid,high);
  return cnt;
}

int team(vector<int>&skill,int n){
  return mS(skill,0,n-1);
}

int main(){
  vector<int> arr = {5,2,8,1,4};
  int n=arr.size();
  int inverse=team(arr,n);

  cout << "Inversion Count = " << inverse << endl;

  for(auto x:arr)
  cout << x <<" ";
  cout << endl;
  return 0;
}