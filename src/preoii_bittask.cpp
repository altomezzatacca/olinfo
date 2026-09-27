#include "bits/stdc++.h"
using namespace std;

vector<int> assegna(int N, int M, vector<vector<int>> S) {
  int &n = N, &m = M;
  vector<bool> ok_pair(n - 1);
  vector<vector<int>> adj(m);
  vector<bool> used(m);
  vector<int> boo(m);
  vector<int> ans(m);
  vector<bool> tot(m);
  int n_tot = 0;
  auto conts = [&](int i, int v) -> bool {
    int l = 0, r = S[i].size();
    while (l < r) {
      int mm = (l + r) >> 1;
      S[i][mm] < v ? l = mm + 1 : r = mm;
    }
    return (l < (int)S[i].size() && S[i][l] == v);
  };
  for (int i = 0; i < n; i++)
    for (auto u : S[i])
      if (!tot[u])
        tot[u] = 1, n_tot++;
  for (int i = 0; i < n - 1; i++) {
    for (auto j : S[i + 1])
      if (!conts(i, j))
        boo[j]++;
    for (auto j : S[i])
      if (!conts(i + 1, j))
        adj[j].emplace_back(i);
  }
  stack<int> s;
  for (int i = 0; i < m; i++)
    if (boo[i] == 0 && tot[i])
      s.emplace(i);
  for (int k = n_tot - 1; k >= 0; k--) {
    if (s.empty())
      return {};
    int sub = s.top();
    s.pop();
    used[sub] = 1;
    ans[sub] = k;
    for (auto i : adj[sub]) {
      if (ok_pair[i])
        continue;
      ok_pair[i] = 1;
      for (auto j : S[i + 1]) {
        if (used[j])
          continue;
        if (!conts(i, j)) {
          boo[j]--;
          if (boo[j] == 0)
            s.emplace(j);
        }
      }
    }
  }
  for (int i = 0; i < m; i++)
    if (!used[i])
      ans[i] = n_tot++;
  return ans;
}
