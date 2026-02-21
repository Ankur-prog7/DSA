// return coordinate of target elem
// here individual row and column are sorted

#include<bits/stdc++.h>
using namespace std;

bool searchElem(vector<vector<int>>&a,int target){
  int n = a.size();
  int m = a[0].size();
  int row = 0,col = m-1;
  while(row < n && col >= 0){
    if(a[row][col] == target) return true;
    else if(a[row][col] < target ) row++;
    else col--;
  }
  return false;
}