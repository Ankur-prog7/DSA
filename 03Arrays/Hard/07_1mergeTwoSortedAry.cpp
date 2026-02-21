// merge two sorted arrfay without extra space
#include<bits/stdc++.h>
using namespace std;


//using two pointer approach
void merge(long long a1[],long long a2[],int n,int m){
  int left = n-1;
  int right=0;
  while(left>=0 && right<m){
    if(a1[left]> a2[right]){
      swap(a1[left],a2[right]);
      left--,right++;
    }
    else{
      break; //coz arrays are already sorted so ek baar ek baar case false hua toh uske badd humesha hoga
    }
  }
    sort(a1,a1+n);
    sort(a2,a2+n) ;
} 
int main(){
  long long a1[]={6,7,8,9};
  long long a2[]={1,2,3,4,5};
  int n= sizeof(a1)/sizeof(a1[0]);
  int m= sizeof(a2)/sizeof(a2[0]);
  merge(a1, a2, n, m);

  cout <<"Array 1: "<< endl;
  for (int i = 0; i < n; i++){
    cout << a1[i] << ",";
    
  }
  cout << endl;
  cout << "Array 2: "<<endl;
  for (int i = 0; i < m; i++){
    cout << a2[i] << " ";
  }


  return 0;

}