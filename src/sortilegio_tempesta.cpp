#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int N, vector<vector<int>> &adj, int start, int end){
    vector<int> parent(N, -1);
    queue<int> q;
    q.push(start); parent[start] = start;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        if (node == end) break;
        for (int u : adj[node]) {
            if (parent[u] == -1) {
                parent[u] = node;
                q.push(u);
            }
        }
    }
    vector<int> path;
    for (int v = end; v != start; v = parent[v])
        path.push_back(v);
    path.push_back(start);
    reverse(path.begin(), path.end());
    return path;
}

long long atterra(int N, vector<int> U, vector<int> V) {
  vector<vector<int>> adj(N);
  for(int i = 0; i < N - 1; i++){
    int x = U[i], y = V[i];
    adj[x].push_back(y); adj[y].push_back(x);
  }
  vector<int> path = bfs(N, adj, 0, N - 1);
  if((int)path.size() == N) return -1;
  unordered_set<int> S(path.begin(), path.end());
  queue<int> q;
  vector<int> dist (N, -1);
  for(int i = 0; i < N; i++)
    if(!S.count(i)){
      q.push(i);
      dist[i] = 0;
    }
  while (!q.empty()) {
    int s = q.front(); q.pop();
    for (int u : adj[s]) {
      if (dist[u] == -1) {
        dist[u] = dist[s] + 1;
        q.push(u);
      }
    }
  }
  long long ans = 0;
  for(auto u: path)
    ans += 1LL * dist[u];
  return ans;
}