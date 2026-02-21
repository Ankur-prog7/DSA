// check palindrome without converting to string 
// coz in string in c++ we can do  
// string s = to_string(x);
// return s == string(s.rbegin(), s.rend());
#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(int x){
  if(x<0 || (x%10==0 && x!=0)) return false;
 int reverseHalf = 0;
 while(x>reverseHalf){
    int digit = x%10;
    reverseHalf=reverseHalf*10 +digit;
    x/=10;
 }
 return (x == reverseHalf || x == reverseHalf/10);

}
int main(){
  int n;
  cin >> n;
  cout << isPalindrome(n)<< endl;
  return 0;
}