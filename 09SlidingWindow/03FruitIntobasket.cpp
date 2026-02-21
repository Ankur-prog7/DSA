//  There is only one row of fruit trees on the farm, oriented left to right. An integer array called fruits represents the trees, where fruits[i] denotes the kind of fruit produced by the ith tree.
#include<bits/stdc++.h>
using namespace std;

int totalFruit(vector<int> & nums){
  int maxlen = 0;
  int lastfruit = -1, secondlastfruit = -1;
  int currCnt  = 0, lastFruitstreak = 0;

  for(auto fruit : nums){
    if(fruit == lastfruit || fruit == secondlastfruit) currCnt++;
    else currCnt = lastFruitstreak + 1;

    // update streak cnt
    if(fruit == lastfruit) lastFruitstreak++;
    else {
      lastFruitstreak = 1;
      secondlastfruit = lastfruit;
      lastfruit = fruit;
    }
    maxlen = max(maxlen,currCnt);
  }
  return maxlen;
}