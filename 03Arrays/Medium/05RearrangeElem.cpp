// Re-aarange elem by sign
// {1,12,5,-2,-3,-6} ---> {post,neg,post,neg,...}-->{1,-2,12,-3,5,-6}
#include<bits/stdc++.h>
using namespace std;
vector<int>RerrangeArray(vector<int>nums){
  int n = nums.size();
  vector<int>arr(n);
  int neg =1,pos= 0;
  for (int i = 0; i < n; i++)
  {
    if(nums[i]<0){
      arr[neg]=nums[i];
      neg += 2;
    }
    else{
      arr[pos]=nums[i];
      pos+=2;
    }
  }
  return arr;
}

int main(){
  vector<int>a = {1,12,5,-2,-3,-6};
  vector<int>c = RerrangeArray(a);
  for(int arr : c){
    cout << arr << ',';
  }
  return 0;
}