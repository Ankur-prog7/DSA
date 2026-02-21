// Set matrix zeroes
// matrixx contain only 0/1 if 0 is present mark the entire row and column of as 0 
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>zeroMatrix(vector<vector<int>> &matrix ,int n,int m){
  int col =1 ;
  // // Step 1: Mark the rows and columns that need to be zeroed
  for (int i = 0; i < n; i++){
  for (int j = 0; j < m; j++){
    if(matrix[i][j]==0){
      matrix[i][0]=0;
      if(j!=0) matrix[0][j]=0;
      else  col = 0;
    }
  }
}
//   Step 2: Set zeros except for first row & column
  for (int i = 1; i < n; i++){
    for (int j = 1; j < m; j++){
      if(matrix[i][j] != 0 ){
        // check for row and column
        if(matrix[0][j]== 0 || matrix[i][0] == 0){
          matrix[i][j] = 0;
        }
      }
    }
  }
  // Step 3: Handle first row
  if(matrix[0][0] == 0){
    for(int j = 0;j<m;j++) matrix[0][j] = 0 ;
  }
  if(col == 0 ){
    for(int i = 0;i<n;i++){
      matrix[i][0]=0;
    }
  }
  return matrix;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}
    };

    int n = matrix.size(); //rows count
    int m = matrix[0].size(); // columns count

    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    cout << "Resultant Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
