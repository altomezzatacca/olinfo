#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T; cin >> T;
    for(int test = 1; test <= T; test++){
        int N, M; cin >> N >> M;
        vector<vector<int>> adj(N);
        for(int i = 0, x, y; i < M; i++){
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        vector<int> C(N);
        for(int i = 0; i < N; i++)
            cin >> C[i];
        vector<int> dist(N, 1e9), coin(N);
        dist[0] = 0;
        deque<pair<int, int>> pq;
        pq.push_front({0, 0});
        while(!pq.empty()){
            auto [d, u] = pq.front(); pq.pop_front();
            if(d > dist[u]) continue;
            for(auto v: adj[u]){
                if(coin[u] >= C[u]){
                    if(dist[v] > dist[u]){
                        pq.push_front({dist[v] = dist[u], v});
                        coin[v] = 0;
                    }
                } else {
                    if(dist[v] > dist[u] + 1){
                        pq.push_back({dist[v] = dist[u] + 1, v});
                        coin[v] = coin[u] + 1;
                    } else if(dist[v] == dist[u] + 1){
                        if(coin[v] < coin[u] + 1){
                            pq.push_back({dist[v], v});
                            coin[v] = coin[u] + 1;
                        }
                    }
                }
            }
        }
        cout << "Case #" << test << ": " << dist[N - 1] << endl;
    }
}