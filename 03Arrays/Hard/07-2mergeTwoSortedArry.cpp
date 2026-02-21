// merge two sorted arrfay without extra space
#include<bits/stdc++.h>
using namespace std;
 
// using gap method

void swapGreater(long long a1[],long long a2[] ,int ind1, int ind2 ){
  if(a1[ind1]>a2[ind2]){
    swap(a1[ind1],a2[ind2]);
  }
}

void merge(long long a1[],long long a2[] ,int n, int m){
  int len = (n+m);
  int gap = (len/2)+(len%2);
  while(gap>0){
    int left =0;
    int right = left + gap;
    while(right < len){
      //comparing a1 and a2 elems
      if(left<len &&  right >=n){
        swapGreater(a1,a2,left,right-n);
      }
      // comparing a2 and a2 elems
      else if(left >= 0){
        swapGreater(a1,a2,left-n,right-n);
      }
      // comparing a1 and a1
      else{
        swapGreater(a1,a1,left,right);
      }
      left++,right++;
    }
    if(gap==1)break;
    gap = (gap/2)+(gap%2);
  }
}