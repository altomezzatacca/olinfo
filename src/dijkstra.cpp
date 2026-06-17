#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int N, M; cin >> N >> M;
  int S, T; cin >> S >> T;
  vector<vector<pair<ll, ll>>> adj(N + 1);
  for(int i = 0; i < M; i++){
    ll x, y, p; cin >> x >> y >> p;
    adj[x].push_back({y, p});
  }
  vector<bool> visited(N + 1);
  vector<ll> D(N + 1, -1);
  priority_queue<pair<ll, ll>, vector<pair<ll,ll>>, greater<>> pq;
  D[S] = 0;
  pq.push({0, S});
  while(!pq.empty()){
    auto [d, node] = pq.top(); pq.pop();
    if(visited[node]) continue;
    visited[node] = 1;
    for (auto [b, w] : adj[node])
      if (D[b] > D[node] + w || D[b] == -1)
        pq.push({D[b] = D[node] + w, b});
  }

  cout << D[T];

  return 0;
}