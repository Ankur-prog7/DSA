// Rotate Matrix by 90
// first tanspose the matrix then reverse the row of matrix

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>rotateMatrix(vector<vector<int>>&m){
 int n = m.size();
//  transpose of matrix
 for (int i = 0; i <=n; i++){
  for(int j = i+1 ;j<=n;j++){
    swap(m[i][j],m[j][i]);
  }
 }
//  reverse of row
  for(int i=0;i<n;i++){
    reverse(m[i].begin(),m[i].end());   
  }
  return m ;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}
    };

    int n = matrix.size(); //rows count
    int m = matrix[0].size(); // columns count

    vector<vector<int>> ans = rotateMatrix(matrix);

    cout << "Resultant Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
