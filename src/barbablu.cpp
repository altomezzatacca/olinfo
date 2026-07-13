#include "bits/stdc++.h"
#include <queue>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, M, C, K; cin >> N >> M >> C >> K;
    C--;
    vector<bool> air(N);
    vector<vector<pair<int, int>>> adj(N);
    for(int c; K--; air[c - 1] = 1) cin >> c;
    for(int i = 0; i < M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        if(w > 20) continue;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    vector<int> dist(N, 1e9);
    priority_queue<array<int, 3>, vector<array <int, 3>>, greater<>> pq;
    pq.push({0, 0, 0}); // distanza, ~ossigeno, nodo
    dist[0] = 0;
    while(!pq.empty()){
        auto [d, o, u] = pq.top(); pq.pop();
        if(d > dist[u]) continue;
        for(auto [v, w]: adj[u])
            if(dist[v] > d + w && o + w < 20)
                pq.push({dist[v] = d + w, (air[v] ? 0 : o + w), v});
    }
    cout << (dist[C] == 1e9 ? -1 : dist[C]);
}