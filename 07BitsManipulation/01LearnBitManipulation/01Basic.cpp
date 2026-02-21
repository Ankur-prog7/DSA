#include<bits/stdc++.h>
using namespace std;

// int convert2decimal(string s){
//   int len = s.size();
//   int num=0,p2=1;
//   for (int i=len-1; i>=0; i--)
//   {
//     if(s[i] =='1'){
//       num = num+p2;
//     }
//     p2 = p2*2;
//   }
//    return num;
// }
 
string convert2binary(int n){
  if(n==0) return "0";
  string res=" ";
  while(n>0){
    if(n%2==0) res += "0";
    else res += "1";
    n=n/2;
  }
  reverse(res.begin(),res.end());
  return res;
}

int convert2decimal(string s){
  int ans = 0;
  for(char c:s){
    ans = ans*2+('c'-0);
  }
  return ans;
}

int main(){
  int n;
  cin >> n;
  cout<<convert2binary(n);
  return 0;
}



// m--2
// int convert2decimal(string s){
//   int num = 0;
//   for(char c:s){
//     num = num*2 +(c-'0');
//   }
// }


