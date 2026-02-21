// Divide two integers without using multiplication, division and mod operator

#include<bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor){
  if(dividend == divisor ) return 1;
  if(dividend == INT_MIN  && divisor == -1) return INT_MAX;// overflow case
  if(divisor == 1) return dividend;

  // Variable to store the sign of result
  bool isPositive = true;

  // updating the sign of quotient
  if(dividend >=0 && divisor<0)
  isPositive = false;
  else if (dividend<0 && divisor >0)
  isPositive = false;

  // storing absolute dividend & divisor
  long long n = abs(dividend);
  long long d = abs(divisor);

  long long ans = 0,sum = 0;
  // looping while sum added to divisor is less than or equal to divisor
  while(sum + d <= n){
    ans++;
    sum += d;
  }
  if(ans > INT_MAX && isPositive) return INT_MAX;
  if(ans >INT_MAX && !isPositive) return INT_MIN;

  // return quotient with proper sign
  return isPositive?ans:-1*ans;

}

int main(){
  int dividend = 10, divisor = 3;
  int ans = divide(dividend,divisor);
  cout << "The result of dividing "<<dividend<<" and "<<divisor<<" is "<<ans;
  return 0;
}