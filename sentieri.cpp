#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, A, B;
    cin >> N >> A >> B;
    vector<vector<pair<int, int>>> adj(N);
    for(int i = 0; i < A; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].emplace_back(b, 0);
        adj[b].emplace_back(a, 0);
    }
    for(int i = 0; i < B; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].emplace_back(b, 1);
        adj[b].emplace_back(a, 1);
    }
    vector<int> dist(N, 1e9);
    dist[0] = 0;
    deque<int> q;
    q.push_front(0);
    while(!q.empty()){
        int u = q.front(); q.pop_front();
        for(auto [v, w]: adj[u]){
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                if(w)
                    q.push_back(v);
                else
                    q.push_front(v);
            }
        }
    }
    cout << dist[N - 1];
    return 0;
}