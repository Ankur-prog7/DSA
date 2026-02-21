//  majority elem , print all ele which appear more than N/3 times in array ,suppose array of size 8 , N = 8 then elem sholud appear more than 2 times


#include<bits/stdc++.h>
using namespace std;

vector<int>majorityElem(vector<int> v){
  int cnt1 =0, cnt2 = 0;
  int el1 =INT_MIN;
  int el2 =INT_MIN;
  for (int i=0;i<v.size();i++){
    if(cnt1 == 0 && el2 != v[i]){
      cnt1 = 1;
      el1 = v[i];
    }
    else if(cnt2 == 0 && el1 != v[i]){
      cnt2 = 1;
      el2 = v[i];
    }
    else if(v[i]==el1) cnt1++;
    else if(v[i] == el2) cnt2++;
    else{
      cnt1--,cnt2--;
    }
  }
  vector<int> ls;
  cnt1 =0 ,cnt2 = 0;
  for (int i = 0; i < v.size(); i++)
  {
  if(el1 == v[i]) cnt1++ ;
  if(el2 == v[i]) cnt2++;
  }
  int mini = (int)(v.size()/3);
if(cnt1 > mini) ls.push_back(el1);
if(cnt2 > mini) ls.push_back(el2);
sort(ls.begin(),ls.end());
return ls;
}

int main(){
  vector<int>a = {1,2,3,1,1,2,2,2};
  vector<int>t= majorityElem(a);
  for(auto x:t){
    cout<<x <<" ";
  }
  
  return 0;
}