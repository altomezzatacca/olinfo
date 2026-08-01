#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
using namespace std;
constexpr static int INF = 1e9;
vector<vector<int>> adj;
vector<vector<bool>> C;

inline bool dfs(int source, int sink, vector<int> &parent) {
	fill(begin(parent), end(parent), -1);
    stack<int> s;
    parent[source] = source;
    s.emplace(source);
    while(!s.empty()){
        auto u = s.top(); s.pop();
        for(auto &v: adj[u]){
            if(parent[v] == -1 && C[u][v]){ // unvisited e arco esistente
                parent[v] = u;
                if(v == sink)
                    return 1;
                s.emplace(v);
            }
        }
    }
    return 0;
}
 
inline int maxflow(int source, int sink) {
	int flow = 0;
    vector<int> parent((int)adj.size());
    while(dfs(source, sink, parent) > 0){ // cammino aumentante
        flow++;
        //aggiorno la rete residua
        int current = sink;
        while(current != source){
            int prev = parent[current];
            C[prev][current] = 0;
            C[current][prev] = 1;
            current = prev;
        }
    }
	return flow;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin >> N;
    int V = 2 * N + 2;
    adj.resize(V); // [1, N] -> x, [N + 1, 2N] -> y, 0 -> source, 2N + 1 -> sink
    C.assign(V, vector<bool> (V));
    for(int i = 0, x, y; i < N; i++){
        cin >> x >> y;
        adj[x].emplace_back(y + N);
        adj[y + N].emplace_back(x);
        C[x][y + N] = 1;
        adj[0].emplace_back(x);
        C[0][x] = 1;
        adj[y + N].emplace_back(V - 1);
        C[y + N][V - 1] = 1;
    }
    cout << maxflow(0, V - 1) << "\n";
}