#include<bits/stdc++.h>
using namespace std;

int Celeb(vector<vector<int>>&M){
  int n = M.size();
  int top = 0,down = n-1;
  while(top < down){
    if(M[top][down]==1){
      top++;
    }
    // if down knowns top , it can not be a celeb
    else if(M[down][top] == 1){
      down = down -1;
    }
    // if both does not know eeach other both cannot be celebrity
    else{
      top++;
      down--;
    }
    // return -1 if no celeb is found
    if(top>down) return -1;
    // check if the person pointed by top is celebrity
    for (int i = 0; i < n; i++)
    {
      if(i == top) continue;
      // check if it is not a celebrity
      if(M[top][i]==1 || M[i][top] == 0) return -1;
    } 
  }
  return top;
}