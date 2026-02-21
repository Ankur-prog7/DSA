// find the missing and repeating numbers

// using maths

#include<bits/stdc++.h>
using namespace std;

vector<int>find(vector<int>&a){
  long long n = a.size();
  // S-Sn =x-y ,Sn->sum of first n elem,S-->summ of array elem
  // S2-S2N ,S->sum of square of array elem ,S2N--> sum of square of array elem
  long long SN = (n*(n+1)/2);
  long long S2N = (n*(n+1)*(2*n+1))/6; 
  long long S =0,S2 =0;
  for (int i = 0; i < n; i++){
    S+=a[i];
    S2 += (long long )a[i] * (long long)a[i];
  }
  long long val1 = S - SN; //x-y
  long long val2 = S2 - S2N;//x^2-y^2
  val2 = val2/val1;//x+y
  long long x = (val1 + val2)/2;
  long long y = x-val1;

  
  return {(int)x,(int)y};
  
}