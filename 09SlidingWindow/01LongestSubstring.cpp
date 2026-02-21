// Length of Longest Substring without any Repeating Character
#include<bits/stdc++.h>
using namespace std;

int longestNonRepeatingSubstring(string &s){
  int n = s.size();

  int hashLen = 256;
  int hash[hashLen];
  for (int i = 0; i < n; i++)
  {
    hash[i] = -1;
  }
  int l =0, r=0,maxLen = 0;
  while(r<n){
    // If current character s[r] is already in the substring*
    if(hash[s[r]]!=-1){
      // move left pointer to right of last occurance of s[r]
      l =max(hash[s[r]] + 1,l);
    }
    // cal the current substring length 
    int len = r-1+1;
    // update max len found so far
    maxLen = max(len,maxLen);
    
    hash[s[r]] = r;
    r++;
  }
  return maxLen;
}