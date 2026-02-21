// rearrange elem by sign if elem left then add them without alternating order
// {1,2,3,-2,-3,5,-9,6} here 5-->positive,3-->negative 2extra postive should be added in array 
// {1,-2,2,-3,3,-9,5,6} 

#include<bits/stdc++.h>
using namespace std;

vector<int>Rearrange(vector<int>nums){
  vector<int>pos,neg;
  int n = nums.size();
  // neg and pos me elem le rhe 
  for(int i =0;i<n;i++){  
    if(nums[i] > 0){
      pos.push_back(nums[i]);
    }
    else{
      neg.push_back(nums[i]);
    }
  } 
    // if pos ka size jyda h toh 
  if(pos.size() > neg.size()){
    for(int i =0;i<neg.size();i++){
      nums[2*i]=pos[i];
      nums[2*i+1] =neg[i];
    }
    int index = neg.size()*2; //6th elm
    for (int i = neg.size(); i < pos.size() ; i++)//(i !< n) neg.size()-->3,pos.size()-->5
    {
      nums[index]=pos[i];
      index++;
    }
    
  }
  else{
    if(pos.size() < neg.size()){
      for(int i =0;i<pos.size();i++){
        nums[2*i]=pos[i];
        nums[2*i+1] =neg[i];
      }
      int index = pos.size()*2;
      for (int i = pos.size(); i < neg.size(); i++)
      {
        nums[index]=neg[i];
        index++;
      }
    }
  }

 return nums;
}
int main(){
  vector<int>a = {1,2,3,-2,-3,5,-9,6};
  vector<int>c = Rearrange(a);
  for(int arr : c){
    cout << arr << ',';
  }
  return 0;
}
