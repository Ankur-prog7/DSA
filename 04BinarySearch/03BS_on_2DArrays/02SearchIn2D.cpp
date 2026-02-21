//whole 2D matrix is sorted where  each row is sorted  individually

#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>&a,int tar){
  int n = a.size();
  int m = a[0].size();
  int low = 0 , high =n*m-1;
  while(low<=high){
    int mid = low+high/2;
    int row = mid/m;
    int col = mid%m;
    if(a[row][col] == tar ) return true;
    else if(a[row][col]<tar) low = mid+1;
    else high = mid-1;
  }
  return false;
}