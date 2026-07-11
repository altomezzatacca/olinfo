#include "bits/stdc++.h"
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, M; cin >> N >> M;
    vector<vector<pair<int, int>>> adj(N);
    vector<array<int, 3>> list(M);
    for(int i = 0; i < M; i++){
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        list[i] = {u, v, w};
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    int ans = 1e9;
    for(int i = 0; i < M; i++){
        auto [u, v, w] = list[i];
        vector<int> dist(N, 1e9);
        dist[u] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, u);
        while(!pq.empty()){
            auto [d, x] = pq.top(); pq.pop();
            if(dist[x] < d) continue;
            for(auto [y, ww]: adj[x]){
                if((x == u && y == v) || (x == v && y == u)) continue;
                if(dist[y] > d + ww && d + ww < ans)
                    pq.emplace(dist[y] = d + ww, y);
            }
        }
        ans = min(ans, dist[v] + w);
    }
    cout << ans << "\n";
}