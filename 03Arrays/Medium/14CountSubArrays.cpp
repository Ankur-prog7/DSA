// count subarray with given sum k 
#include<bits/stdc++.h>
using namespace std;

int subArrayfinder(vector<int> &arr ,int k){
  unordered_map<int,int> mpp;
  mpp[0] = 1;
  int preSum  =0 ,cnt = 0;

  for(int i = 0;i<arr.size();i++){
    preSum += arr[i]; //s
    int remove = preSum - k; // s-k

    cnt += mpp[remove];// Count all the previous prefix sums that can form a subarray with current prefix sum = k
    
     mpp[preSum] += 1; //“I’ve seen this prefix sum one more time.”

  }
  return cnt;
}

int main(){
  vector<int> a = {3,-3,1,1,1};
  int  k = 3;
  cout << subArrayfinder(a,k);
  return 0;
}