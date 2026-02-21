#include<bits/stdc++.h>
using namespace std;

int main() {
  cout << "Enter no of elem in array" <<endl;
  int n;  
  cin >> n;
  int arr[n];
  // vector <int> arr(n); good method
  cout<< "Enter element of array"<< endl;
  for(int i=0; i < n ;i++){
    cin >> arr[i];
  }


  //pre compute

  int hash[13] = {0};  //yaha all 13 elem me 0 pre store krr rhe
  for (int i =0;i<n;i++){
    hash[arr[i]] +=1;
    // hash[arr[i]]++;
  }
 
  cout<<"Enter no of queries"<<endl;
  int q;  //here q is for queries means how many time we have to check
  cin >> q;
  while(q--){
    cout<< "Enter your no you whose no of repitition you want"<< endl;
    int num;   // no we have to check that how many time it is repeated
    cin >> num;

    //fetch
    cout<<hash[num]<< endl;
  }
  return 0;
}