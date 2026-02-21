// Given two integers L and R. Find the XOR of the elements in the range [L , R].
#include<bits/stdc++.h>
using namespace std;
class soln{
private:
int XORtillN(int n){
  if(n%4 == 1) return 1;
  if(n%4 == 2) return n+1;
  if(n%4 == 3) return 0;
  return n;

}
  
public:
int findRangeXOR(int l,int r){
  return XORtillN(l-1)^XORtillN(r);
}
};
