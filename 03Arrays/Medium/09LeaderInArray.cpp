// Leaders in an Array problem or Superior Elements
// elem of right should be minimun from that elem
#include<bits/stdc++.h>
using namespace std;

vector<int> superiorElem(vector<int>&a){
  vector<int> ans;
  int maxi = INT_MIN;
  int n = a.size();
  for (int i = n-1; i >= 0; i--)
  {
    if(a[i]>maxi){
      
      ans.push_back(a[i]);
    }
    maxi = max(maxi,a[i]);
  }
  sort(ans.begin(),ans.end());
  return ans;
}

int main(){
vector<int>a = {7,2,5,1,8,3};
vector<int> c = superiorElem(a);
for(int arr : c)
  cout << arr << ',' ;
return 0;
}