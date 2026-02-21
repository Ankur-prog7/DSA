// Rotate an array with k index
#include<bits/stdc++.h>
using namespace std;

// optimal

// void rotateKtimes(int arr[],int n,int k){  //m-1
//   k = k%n ; // to make rotation under size of array , ex k = 8 and size of array is 5 then rotation(k) will be k =3 by k=k%n
//   // reverse(arr + start, arr + end + 1); here end and start is index that's why we included + 1
//   reverse(arr,arr+n); //reverse full array
//   reverse(arr,arr+k); // reverse from 0 to k-1
//   reverse(arr+k,arr+n); // reverse from k to n-1
// }

//  v[(i+k)%n] //when i = 0, 3%5 = 3, when i = 1 ,4%5=4,when i = 2, 5%5=0.........
void rotateKtimes(vector<int>&v,int k){  //{8,1,2,3,6}
  int n = v.size();
  k = k%n;
  if(k==0) return;
  int cnt  = 0;
  for (int i = 0; i < n; i++)
  {
    int prev = v[i]; 
    int indx = i;

    while(i!=indx){
    int nxt = (i+k)%n;
    swap(v[nxt],prev);
    indx = nxt;
    cnt ++;
    }
 
  }

}


// check if array is roted and sorted 1 2 3 4 - 4 1 2 3 



int main(){
  // int arr[] = {8,1,2,3,6};
  // int n = sizeof(arr)/sizeof(arr[0]);
  vector<int> v = {8,1,2,3,6};
  int k =3;
  // rotateKtimes(arr,n,k);
  rotateKtimes(v,k);
  // for(int i = 0;i<n;i++){
  //   cout <<arr[i]<< " ";
  // }

  for(auto x:v){
    cout << x << " ";
  }
  return 0;
}