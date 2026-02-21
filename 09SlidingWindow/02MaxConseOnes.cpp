// Max Consecutive Ones III
// return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
#include<bits/stdc++.h>
using namespace std;

int longestOnes(vector<int> &nums,int k){
  int left = 0; // left ponter
  int zeroCnt = 0 ; // count zero in current window
  int maxLen = 0; // store max valid window length
  for (int i = 0; i < nums.size(); i++)
  {
    if(nums[i] == 0) zeroCnt++;
    if(zeroCnt > k ) {
      if(nums[left] == 0) zeroCnt--;
      left++; // Shrink the window from left
    }
    maxLen = max(maxLen , i-left +1);//i-left+1 --> length of currnt window
  }
  
  return maxLen;
}