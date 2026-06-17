#include <bits/stdc++.h>
using namespace std;
constexpr static int macs = 2e6 + 1;
constexpr static int mid = 1e6;

int main() {
  int N, P, Q; cin >> N >> P;
  vector<int> V(macs), pref(macs);
  vector<int> S(N), F(N);
  for(auto &u: S) cin >> u;
  for(auto &u: F) cin >> u;
  for(int i = 0; i < N; i++)
    if(F[i] == P) V[S[i] + mid]++;
  pref[0] = V[0];
  for(int i = 1; i < macs; i++) pref[i] = pref[i - 1] + V[i];  
  cin >> Q;
  while(Q--){
    int l, r, k; cin >> l >> r >> k;
    l += mid; r += mid;
    int x = (l == 0 ? pref[r] : pref[r] - pref[l - 1]);
    cout << (x >= k ? "YES" : "NO") << "\n";
  }
}