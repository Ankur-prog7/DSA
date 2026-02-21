// best time to buy and sell stock
#include<bits/stdc++.h>
using namespace std;
int maximumprofit(vector<int>prices){
  int mini = prices[0];
  int maxProfit = 0;
  int n =prices.size();
  for (int i = 0; i < n; i++)
  {
    int cost = prices[i]-mini;
    maxProfit = max(maxProfit,cost) ;
    mini = min(mini,prices[i]);
  }
  return  maxProfit;
  
}
int main(){
  vector<int>a = {7,2,5,1,8,3};
  int c = maximumprofit(a);
    cout << c ;
  return 0;
}