// print matrix in spiral manner

#include<bits/stdc++.h>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>>&m){
  int r = m.size();
  int c = m[0].size(); //count columns
  int left = 0,right = c-1;
  int top = 0 ,bottom=r-1;
  vector<int> ans;

  while(top <= bottom && left <= right){
  // right-->left
  for(int i = left;i<=right;i++){
    ans.push_back(m[top][i]);  
  }
  top++;
  //top-->bottom
  for(int i = top;i<=bottom;i++){
    ans.push_back(m[i][right]);
  }
   right--;
  // right-->left
  if( top <= bottom){  //Ensures there’s still an unvisited row left
  for(int i = right;i>=left;i--){
    ans.push_back(m[bottom][i]);
  }
  bottom--;
  }
  if(left <= right){ //nsures there’s still an unvisited column left
      for(int i = bottom;i>=top;i--){
      ans.push_back(m[i][left]);
    }
    left++;
  }
  }

  return ans;
}

int main() {
  vector<vector<int>> matrix = {
    {1, 2, 3},
    {4, 0, 6},
    {7, 8, 9}
  };
  vector<int> ans = spiralMatrix(matrix);

  cout << "Resultant Matrix:" << endl;
  for (auto x : ans) {
    cout << x << " ";
  }

  return 0;
}
