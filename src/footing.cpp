#include "bits/stdc++.h"
using namespace std;
int dist[1000], root[1000];

// Soluzione 1 - O(M * (M + V log V)): 
// per ogni arco e = [u, v, w] eseguo un dijkstra da u a v saltando l'arco e e aggiungo w al risultato
// Soluzione 2 - O(N * (M + V log V)):
// per ogni nodo s faccio un dijkstra e per ogni nodo tengo conto del nodo adiacente a s da cui sono partito

inline int readint(){
    int n = 0;
    int c = getchar_unlocked();
    while(c < '0' || c > '9') c = getchar_unlocked();
    while(c >= '0' && c <= '9'){
        n = n * 10 + c - '0';
        c = getchar_unlocked();
    }
    return n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, M; N = readint(); M = readint();
    vector<vector<pair<int, int>>> adj(N);
    for(int i = 0; i < M; i++){
        int u, v, w;
        u = readint() - 1;
        v = readint() - 1;
        w = readint();
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    int ans = 1e9;
    for(int s = N - 1; s >= 0; s--){
        fill(begin(dist), end(dist), 1e9);
        fill(begin(root), end(root), -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dist[s] = 0;
        pq.emplace(0, s);
        while(!pq.empty()){
            auto [d, x] = pq.top(); pq.pop();
            if(d > dist[x]) continue;
            for(auto [y, w] : adj[x]){
                if(x == s && dist[y] > w && w < ans){
                    dist[y] = w;
                    root[y] = y;
                    pq.emplace(dist[y], y);
                }
                else if(dist[y] > d + w && d + w < ans){
                    root[y] = root[x];
                    pq.emplace(dist[y] = d + w, y);
                } 
                else if(root[x] != root[y] && root[y] != -1)
                    ans = min(ans, d + dist[y] + w);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}