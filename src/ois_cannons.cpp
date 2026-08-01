#include <bits/stdc++.h>
using namespace std;
constexpr static int INF = 1e9;

int main() {
  int N; cin >> N;
  vector<int> T(N);
  for(int i = 0; i < N; i++)
    cin >> T[i];
  vector<int> dist(N, INF);
  dist[0] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  pq.push({0, 0});
  while(!pq.empty()){
    int u = pq.top().second; pq.pop();
    if(dist[T[u]] > dist[u])
      pq.push({dist[T[u]] = dist[u], T[u]});
    int v = u - 1;
    if(v >= 0 && dist[v] > dist[u] + 1)
      pq.push({dist[v] = dist[u] + 1, v});
    v = u + 1;
    if(v < N && dist[v] > dist[u] + 1)
      pq.push({dist[v] = dist[u] + 1, v});
  }
  cout << dist[N - 1];
}