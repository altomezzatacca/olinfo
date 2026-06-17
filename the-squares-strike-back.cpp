#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; cin >> N;
  unordered_map<int, long long> M;
  while(N--){
    long long x, y; cin >> x >> y;
    M[y - x]++;
  }
  long long ans = 0;
  for(auto u: M)
    if(u.second >= 2){
      long long x = u.second;
      ans += 1LL * (x * (x - 1)) >> 1;
    }
  cout << ans;
}