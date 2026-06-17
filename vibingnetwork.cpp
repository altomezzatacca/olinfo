#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N, T, K;
  cin >> N >> T >> K;
  N *= 67;
  vector<long long> V(T);
  for(auto &u: V) {cin >> u; u *= 100;}
  vector<int> pref(T);
  if(V[0] >= N) pref[0] = 1;
  for(int i = 1; i < T; i++)
    if(V[i] >= N)
      pref[i] = 1 + pref[i - 1];
  int ans = -1;
  for(int i = K - 1; i < T; i++)
    if(pref[i] == K) {ans = i - K + 2; break;}
  cout << ans;
}