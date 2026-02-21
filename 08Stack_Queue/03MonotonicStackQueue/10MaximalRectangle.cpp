// in each row make histogram with 1's ex 
/*1 1 0 0
  0 1 1 0
  .                                    _ 1 _ _
  now histo gram will look like this  _ 1 1 _
*/

#include<bits/stdc++.h>
using namespace std;

class Soln{

private:
int largeRectangleArea(vector<int> &height){
  int n = height.size();
  stack<int>st;
  int largestArea = 0;
  
  int area;
  int nse,pse;

  for (int i = 0; i < n; i++)
  {
    // pop unilt top elem is not smaller the curr elem or stack is empty
    while (!st.empty() && height[st.top()] >= height[i])
    {
      // get the index of top of stack
      int ind = st.top();
      st.pop();
      // update the index of prev smaller elem
      pse = st.empty() ? -1:st.top();

      // next smaller elem index for the popped elem is curr index
      nse =i;

      // cal the area of the popped elem
      area = height[ind]*(nse-pse-1);

      // update the max area
      largestArea = max(largestArea,area);
    }
    //push the curr index in stack
    st.push(i);
  }
  
  // for elem that are not poped from stack
  while (!st.empty())
  {
    // nse for such elem is size of array
    nse =n ;
    // get the index of top of stack
    int ind = st.top();
    st.pop();

    // /uodate the prev smaller elem
    pse = st.empty()?-1:st.top();

    // cal the area of the popped elem 
    area = height[ind]*(nse-pse-1);

    // update the max area
    largestArea = max(largestArea,area);
  }
  return largestArea;
}

public:
// funcn to find thr largets rectangle area containing all 1's
int maxAreaOfSubMatrix(vector<vector<int>> &matrix){
  // determone the size of matrix 
  int n = matrix.size();
  int m = matrix[0].size();
  //prefix sum to store height for diff ground level
  vector<vector<int>>prefixSum(n,vector<int>(m));
  // fill up the prefix sum atrix colmn wise
  for (int j = 0; j < m; j++)
  {
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += matrix[i][j];
      // if no base is present
      if(matrix[i][j]==0) {
        prefixSum[i][j] = 0;
        sum =0;
      }
      // store the height
      prefixSum[i][j] = sum;
    }
  }
  // to store the max area
  int maxArea = 0;

  // traverse for diff levels of ground
  for (int i = 0; i < n; i++)
  {
    // get the largesr area of curr level
    int area = largeRectangleArea(prefixSum[i]);

    // update the max area 
    maxArea = max(area,maxArea);
  }
  
  return maxArea;
}
};
