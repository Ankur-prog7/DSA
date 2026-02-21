// The optimal approach uses two pointers ,without extra space for arrays

//  If the left height is smaller or equal to the right height, the trapped water depends on the left side's maximum; otherwise, it depends on the right side's maximum. 

#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>&height){
  int n = height.size();

  // initialixe two pointer both size
  int left = 0;
  int right = n-1;

  // variable to track max height
  int maxLeft = 0;
  int maxRight = 0;

  // variable to store total water
  int totalWater =0;

  // iterate unit left pointer cross the right pointer
  while(left<=right){
    // if left bar is smaller or equal to right bar
    if(height[left] <= height[right]){
      // if curr left bar is higher than maxleft, update maxLeft
      if(height[left]>= maxLeft) maxLeft = height[left];
      else {
        // water is trapped on left coz maxLeft is less than curr left
        totalWater += maxLeft - height[left];
      }
      left++;
    }
    else{
      // if curr right bar is higher than maxRight,update maxRight
      if(height[right] >= maxRight) maxRight = height[right];
      else{
        // water is trapped in diff btw maxRight and currHeight
        totalWater += maxRight - height[right];
      }
      right--;
    }
  }
  return totalWater;
}