#include<bits/stdc++.h>
using namespace std;

void fun(vector<int>&a,int arr[] ,int ind,int n){
  // int n = sizeof(arr[0])/sizeof(arr);// this is wrong coz now arr has become pointer so this give size of pointer
  if(ind == n) {
    for(auto it:a){
      cout<< it << "{}";
    }
    if(a.size()==0) cout<< " ";
    cout<<endl;
    return ;
  }
  // take
  a.push_back(arr[ind]);
  fun(a,arr,ind+1,n);
  // not take
  a.pop_back();
  fun(a,arr,ind+1,n);
}

int main(){
  int arr[] = {3,1,2};
  int n = sizeof(arr)/sizeof(arr[0]);
  vector<int>ds;
  fun(ds,arr,0,n);
}



/*
#include<bits/stdc++.h>
using namespace std;

int fun(int ind,vector<int>a,int arr[],int n){
  if(ind==n){
  cout<<ds;
  return;
  }
  a.push_back(arr[ind]);
  fun(ind+1,a,arr,n);
  a.pop_back();
  fun(ind+1,a,arr,n);
}

*/