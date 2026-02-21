// ********************* APPROACH-1 ************************
#include<bits/stdc++.h>
using namespace std;

int largestRectArea(vector<int> &height){
  int n = height.size();
  stack<int>st;

  int LeftSmall[n], RightSmall[n];

  // compute Nearest Smaller to left (NSL) for each bar
  for (int i = 0; i < n; i++)
  {
    // pop until a smaller elem is found or stack is empty
    while (!st.empty() && height[st.top()] >= height[i])
    {
      st.top();
    }
    // if stack is empty , no smaller elem on the left
    LeftSmall[i] = st.empty()?0:st.top()+1;

    // Push curr index to stack 
    st.push(i);

  }
  // clear stack to reuse for NSR
  while(!st.empty()) st.pop();

  // compute Nearest Smaller to Right (NSR) for each bar
  for (int i = n-1; i >= 0; i--)
  {
    while(!st.empty() && height[st.top()] >= height[i]){
      st.pop();
    }

    // if stack is empty , no smaller to the right 
    RightSmall[i] = st.empty()?n-1:st.top()-1;
    st.push(i);
  }
  int maxA =0;
  for (int i = 0; i < n; i++)
  {
    int width = RightSmall[i] - LeftSmall[i] +1;
    maxA = max(maxA,height[i]*width);
  }
  return maxA;
  
}