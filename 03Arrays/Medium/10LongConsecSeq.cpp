// *******************  optimal ***********************
// Longest Consecutive sequence sum in arrray
#include<bits/stdc++.h>
using namespace std;
int longestSucccessiveElem(vector<int>&a){
  int n = a.size();
  if(n==0) return 0 ;
  int longest = 1;
  unordered_set<int> st;
  for (int i = 0; i < n; i++)
  { 
    st.insert(a[i]);
  }
  for(auto it:st){
    if(st.find(it-1)==st.end()){ //“If there is no smaller consecutive number present in the set.”
      int cnt = 1;
      int x =it;
      while(st.find(x+1) != st.end()){  //“Keep looping while there exists an element that is 1 greater than x in the set.”
        x += 1;
        cnt += 1;

      }
      longest = max(longest,cnt);
    }
  }
  return longest;
}

int main(){
vector<int>a = {7,2,5,1,8,3};
int c = longestSucccessiveElem(a);
  cout << c;
return 0;
}



// ***************better************************

/*

int longest = 1;
int lastSmaller = INT_MIN;
int count = 1;

for (int i = 1; i < n; i++) {
    if (a[i] - 1 == lastSmaller) {  
    “Check if the current number (a[i]) is exactly 1 greater than the last number (lastSmaller).”
        count++;
    } else {
        count = 1; // reset if not consecutive
    }
    lastSmaller = a[i];
    longest = max(longest, count);
}


*/