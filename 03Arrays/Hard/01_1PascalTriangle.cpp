// Given r & c then tell elem at that place
// formula used ---> result = result*(n-i)*(i+1)
#include<bits/stdc++.h>
using namespace std;

long long NcR(int n,int r){
  long long  result =1;
  r = min(r,n-r); //coz nCr = nCn-r coz if r>n n-r will be negative

  // finding nCr
  for (int i = 0; i < r; i++)
  {
    result = result*(n-i);
    result=result/(i+1);
  }
  return result;
}

int main()
{
  int r,c;
  cin >> r>>c;
  cout<<NcR(r-1,c-1); // to get the elem at that location pass r-1,c-1
  return 0;
}