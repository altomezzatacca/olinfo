#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
using namespace std;
constexpr array<int, 4> dx = {0, -1, 0, +1};
constexpr array<int, 4> dy = {-1, 0, +1, 0};
constexpr static int INF = 1e8;

inline bool bfs(int source, int sink, vector<vector<int>> &adj, vector<map<int, int>> &C, vector<int> &parent) {
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
 
inline int maxflow(int source, int sink, vector<vector<int>> &adj, vector<map<int, int>> &C) {
	int flow = 0;
    vector<int> parent((int)adj.size());
    while(bfs(source, sink, adj, C, parent)){
        flow++;
        //aggiorno la rete residua
        int current = sink;
        while(current != source){
            int prev = parent[current];
            C[prev][current]--;
            C[current][prev]++;
            current = prev;
        }
    }
	return flow;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // input
    int N, M;
    cin >> N >> M;
    vector<vector<char>> G(N, vector<char> (M)); // griglia di input
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> G[i][j];
    
    // funzione per determinare se una cella esiste o meno
    auto exists = [&](int x, int y) -> bool {
        return 0 <= x && x < N && 0 <= y && y < M;
    };

    // rendo acqua i punti di domanda 
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(G[i][j] == '?')
                for(int k = 0; k < 4; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(exists(nx, ny) && G[nx][ny] == '1')
                        G[i][j] = '0';
                }

    //dfs nel main
    vector<vector<bool>> visited(N, vector<bool> (M));
    function<void(int, int)> dfs = [&](int x, int y) {
        visited[x][y] = true;
        for(int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(exists(nx, ny) && !visited[nx][ny] && G[nx][ny] == '1')
                dfs(nx, ny);
        }
    };
    
    // numero di isole presenti nell'input    
    int count = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(G[i][j] == '1' && !visited[i][j]){
                count++;
                dfs(i, j);
            }
    
    // assegno un indice ai restanti '?'
    int V = 0;
    vector<vector<int>> grid_to_index(N, vector<int> (M));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(G[i][j] == '?')
                grid_to_index[i][j] = V++;
    int source = V++; // source -> V - 2
    int sink = V++; // source --> V - 1

    vector<vector<int>> adj(V);
    vector<map<int, int>> C(V); // o unordered map ?
    auto add_edge = [&](int a, int b) -> void{
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
        C[a][b] = 1;
    };

    // costruisco il grafo bipartito
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            if(G[i][j] != '?') continue;
            int ix = grid_to_index[i][j];
            if((i + j) % 2){
                add_edge(source, ix);
                for(int k = 0; k < 4; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(exists(nx, ny) && G[nx][ny] == '?')
                        add_edge(ix, grid_to_index[nx][ny]);
                }
            } else {
                add_edge(ix, sink);
            }
        }
    int max_independent_set = V - 2 - maxflow(source, sink, adj, C);
    cout << count + max_independent_set << "\n";
}