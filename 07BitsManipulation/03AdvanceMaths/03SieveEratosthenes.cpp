#include<bits/stdc++.h>
using namespace std;

vector<int> primesInRange(vector<vector<int>>&queries){
  if(queries.empty()){
    return {};
  }
  int maxVal = 0;
for(const auto & query : queries){
  maxVal = max(maxVal,query[1]);
}
vector<bool> isPrime(maxVal + 1, true);
isPrime[0] = isPrime[1] = false;  // 0 and 1 are not primes
for (int p = 2; p * p <= maxVal; ++p) {
  if (isPrime[p]) {
    for (int i = p * p; i <= maxVal; i += p) {
      isPrime[i] = false;
    }
  }
}

vector<int> primeCount(maxVal + 1, 0);
for (int i = 1; i <= maxVal; ++i) {
  primeCount[i] = primeCount[i - 1];
  if (isPrime[i]) {
    primeCount[i]++;
  }
}

vector<int> result;
for (const auto& query : queries) {
  int start = query[0];
  int end = query[1];
  if (start == 0) {
    result.push_back(primeCount[end]);
  } else {
    result.push_back(primeCount[end]-primeCount[start -1]);
  }
}

return result;
}

