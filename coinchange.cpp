#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<long long> A = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000};
  vector<long long> T (15, 0);
  long long sum = 0;
  for(int i = 0; i < 15; i++){
    long long x; cin >> x;
    sum += x * A[i];
  }
  int ix = 14;
  while(sum > 0){
    if(A[ix] > sum) ix--;
    else {
      T[ix] = sum / A[ix];
      sum -= A[ix] * T[ix];
    }
  }
  for(auto u : T) cout << u << " ";
  
}