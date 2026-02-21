// n is given then print Pascal's triangle(n is no of row)

#include<bits/stdc++.h>
using namespace std;

vector<vector<long long>>PascalTriangle(int n){
  vector<vector<long long>>ans;
  for(int i =1;i<=n;i++){
   long long val =1;
   
   vector<long long>ansRow;
   ansRow.push_back(val);

   for(int col =1; col<i ;col++){
    val = val*(i-col)/col;
    ansRow.push_back(val);
   }
   ans.push_back(ansRow);
  }
  return ans;
}

int main(){
  int r = 5;
  vector<vector<long long>> t = PascalTriangle(r);
  for(auto &x :t){
    for(auto row : x){
      cout << row <<" ";
    }
    cout << endl;
    
  }
  return 0;
}