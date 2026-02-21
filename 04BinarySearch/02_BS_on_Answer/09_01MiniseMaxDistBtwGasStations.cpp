// ****************    HARD      ************************
// Minimise max distance btw gas stations

#include<bits/stdc++.h>
using namespace std;

long double minimiseMaxDist(vector<int>&a,int k){
  int n = a.size();
  vector<int>howMany(n-1,0);
  for(int gasStations=1;gasStations <=k;gasStations++){
    long double maxSection=-1;
    int maxInd=-1;
    for (int i = 0; i < n-1; i++)
    {
    long double diff= (a[i+1]-a[i]);
    long double sectionLength = diff/(long double)(howMany[i]+1);
    if(sectionLength>maxSection){
      maxSection=sectionLength;
      maxInd=i;
    }
    }
    howMany[maxInd]++;
  }
}