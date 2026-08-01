#include <bits/stdc++.h>
using namespace std;

void solve(int t) {
  int N;
  cin >> N;
  long long K1 = 0, K2 = 1e18;
  vector<int> W(N);
  for (int i = 0; i < N; i++)
    cin >> W[i];
  vector<vector<long long>> rows = {{}};
  vector<long long> len;
  int l = 0;
  for(int i = 0; i < N; i++){
    if(W[i] == -1) {
      len.emplace_back(l + (int)rows.back().size() - 1);
      l = 0;
      rows.push_back({});
    }
    else {
      rows.back().emplace_back(W[i]);
      l += W[i];
    }
  }
  len.emplace_back(l + (int)rows.back().size() - 1);
  for(auto u: len)
    K1 = max(K1, u);
  for(int i = 0; i < (int)rows.size() - 1; i++)
    K2 = min(K2, len[i] + rows[i + 1][0]);
  cout << "Case #" << t << ": " << K1 << " " << K2 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve(t);
    }
    return 0;
}