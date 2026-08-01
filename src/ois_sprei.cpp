#include <bits/stdc++.h>
using namespace std;
constexpr static int inf = 2e9;
static int N, M, B;
// minimum vertex cover in grafo bipartito -> maximum matching -> maxflow
// i nodi sono bipartiti in base alla parità della somma delle loro coordinate
// faccio arbitrariamente partire gli archi dai punti di parità pari

inline int bfs(int source, int sink, vector<vector<int>> &adj, vector<map<int, bool>> &C, vector<int> &parent){
    fill(begin(parent), end(parent), -1);
    stack<int> s;
    parent[source] = source;
    s.emplace(source);
    while(!s.empty()){
        auto u = s.top(); s.pop();
        for(auto &v: adj[u]){
            if(parent[v] == -1 && C[u][v]){
                parent[v] = u;
                if(v == sink)
                    return 1;
                s.emplace(v);
            }
        }
    }
    return 0;
}

inline int maxflow(int source, int sink, vector<vector<int>> &adj, vector<map<int, bool>> &C){
    int flow = 0;
    vector<int> parent(N + 2);
    while(bfs(source, sink, adj, C, parent)){
        flow++;
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

int main() {
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    cin >> N >> M >> B;
    vector<vector<int>> adj(N + 2); // 0 -> source, [1, N] -> punti, N + 1 -> sink
    vector<map<int, bool>> C(N + 2);
    map<vector<int>, int> ids;
    vector<vector<int>> coords(N, vector<int> (M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
            cin >> coords[i][j];
        ids[coords[i]] = i + 1;
    }
    vector<int> V;
    for(int i = 0; i < N; i++){
        V = coords[i];
        int ix = i + 1;
        int sum = 0;
        for(auto u: V){
            sum += u;
            sum %= 2;
        }
        if(sum){ 
            adj[ix].emplace_back(N + 1);
            adj[N + 1].emplace_back(ix);
            C[ix][N + 1] = 1;
            continue; // non duplico gli archi
        } else {
            adj[ix].emplace_back(0);
            adj[0].emplace_back(ix);
            C[0][ix] = 1;
        }
        for(int j = 0; j < M; j++){
            V[j]++;
            auto it = ids.find(V);
            if(it != ids.end()){
                adj[ix].emplace_back(ids[V]);
                adj[ids[V]].emplace_back(ix);
                C[ix][ids[V]] = 1;
            }
            V[j] -= 2;
            it = ids.find(V);
            if(it != ids.end()){
                adj[ix].emplace_back(ids[V]);
                adj[ids[V]].emplace_back(ix);
                C[ix][ids[V]] = 1;
            }
            V[j]++;
        }
    }
    cout << maxflow(0, N + 1, adj, C) << "\n";
    return 0;
}
