#include<bits/stdc++.h>
using namespace std;

// a no is lucky no if it is smallest in row and greatest in column
vector<int>LuckyNo(vector<vector<int>>&arr){
  int r = arr.size();
  int c = arr[0].size();
  vector<int>ans;
  for (int i = 0; i < r; i++)
  { 
    int minInRow = INT_MAX;
    int col = 0;
    for (int j = 0; j < c; j++)
    {
      if(arr[i][j] < minInRow){ // 3 4 5
        minInRow = arr[i][j];
        col = j;
      }
    }
    int maxInCol = true;
    for (int k = 0; k < r; k++)
    {
      if(arr[k][col] > minInRow){
        maxInCol = false;
        break;
      }
    }
    if(maxInCol) ans.push_back(maxInCol);

  }
  return ans;
}