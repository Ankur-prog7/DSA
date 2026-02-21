// Nth row is given then print all elem of Nth row of Pascal's triangle
// formula used-- value = value*(n-1)/i

#include<bits/stdc++.h>
using namespace std;

vector<long long> getPascalRow(int r){
  vector<long long>row;
  long long value =1;
  row.push_back(value); // pehla elem humesa 1 hoga
  for (int i = 1; i < r; i++)
  {
    // value *= (r-i)/i;   wrong
    value = value*(r-i)/i;
    row.push_back(value);
  }
  return row;
}

int main(){
  int n;
  cin >>n;
  vector<long long>t = getPascalRow(n);
  for(int x:t){
    cout << x;
  }
}