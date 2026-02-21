// ***************Approcah 2***************************
// height = histo[st.top()];
// width = i- (st.top()-1) diff btw curr index and index at top

// NOTE:- here histo[st.top()] , we are treating st.top() as INDEX not using it to give value 
// that is why we will push the elem as st.push(i) not as st.push(histo[i])

#include<bits/stdc++.h>
using namespace std;

int largestRectArea(vector<int>&histo){
  stack<int> st;
  int maxA = 0;
  int n = histo.size();

  // loop through each bar including an imaginary bar at the end 
  for (int i = 0; i <= n; i++)
  {
    //while curr bar is smaller than the top of stack or we reached the end
    while (!st.empty() && (i==n || histo[st.top()] >= histo[i]))
    {
      int height = histo[st.top()];//get the height of the bar at a top of stack
      st.top();//remove that  bar

      int width;
      if(st.empty()){
        width = i;//all bars before were higher
      }else{
        width = i- st.top()-1; // width btw cur indexx and index at a top stack
      }
      // calculate area and update max area
      maxA = max(maxA,width*height);
    }
    //push curr index into stack 
    st.push(i);
  }
  return maxA;
  
}