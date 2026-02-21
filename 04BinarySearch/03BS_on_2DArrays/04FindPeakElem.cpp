// elem should be max in its surrounding
#include<bits/stdc++.h>
using namespace std;

int findMax(vector<vector<int>>&a,int n,int m ,int col){
  int MaxValue = -1;
  int index = -1;
  for (int i = 0; i < n; i++)
  {
    if(a[i][col]>MaxValue){
      MaxValue = a[i][col];
      index = i;
    }
    
  }
  return index;
}

vector<int> findPeakGrid(vector<vector<int>>&a){
  int n = a.size();
  int m = a[0].size();
  int low = 0,high =n-1;
  while(low<=high){
    int mid = (low+high)/2;
    int maxRowIndex = findMax(a,n,m,mid);
    int left =mid-1 >= 0 ? a[maxRowIndex][mid-1]:-1;
    int right = mid+1 <m ? a[maxRowIndex][mid+1]:-1;
    if(a[maxRowIndex][mid] > left && a[maxRowIndex][mid]>right){
      return {maxRowIndex,mid};
    }
    else if(a[maxRowIndex][mid]<left){
      high = mid-1;
    }
    else{
      low = mid+1;
    }
  }
  return {-1,-1};
}