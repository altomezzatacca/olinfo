#include "bits/stdc++.h"
using namespace std;

int illumina(int N, int M, vector<int> H, vector<int> A, vector<int> B, vector<int> L) {

    int &n = N, &m = M;

	int ans = 0;
    vector<set<pair<int, int>>> adj(n); // b, l[a-b]; metto solo gli archi non \textit{triviali}
    vector<bool> visited(n);
    queue<int> q;

    for(int e = 0; e < m; e++){
        int &u = A[e], &v = B[e], &l = L[e];
        if(H[u] < H[v]) swap(u, v);
        if(l < H[v]){continue; // è un arco inutile
        } else if(l >= H[v] && l < H[u]){ // può contenere solo v -> greedy
            if(visited[v]) continue;
            ans++;
            visited[v] = 1;
            q.emplace(v);
        } else if(l >= H[u] + H[v]){ // può contenere entrambi gli archi -> greedy
            if(!visited[u]){
                ans++;
                visited[u] = 1;
                q.emplace(u);
            }
            if(!visited[v]){
                ans++;
                visited[v] = 1;
                q.emplace(v);
            }
        } else if(l >= H[u] && l < H[u] + H[v]){
            adj[u].insert({v, e});
            adj[v].insert({u, e});
        }
    }

    while(!q.empty()){ // propago greedily finchè posso
        auto u = q.front(); q.pop();
        while(!adj[u].empty()){
            auto [v, e] = *begin(adj[u]);
            adj[u].erase({v, e});
            adj[v].erase({u, e});
            if(visited[v]) continue;
            ans++;
            visited[v] = 1;
            q.emplace(v);
        }
    }

    for(int i = 0; i < n; i++)
        if(!visited[i] && (int)adj[i].size() == 1) // ha una sola via possibile
            q.emplace(i);

    while(!q.empty()){
        auto u = q.front(); q.pop();
        if(adj[u].empty()) continue;
        auto [v, e] = *begin(adj[u]);
        adj[u].erase({v, e});
        adj[v].erase({u, e});
        if((int)adj[v].size() == 1) q.push(v);
        ans++;
    }

    for(int i = 0; i < n; i++)
        if(!visited[i] && !adj[i].empty())
            ans++;

    return ans;
}

#ifndef EVAL
int main() {
	int N; cin >> N;
	int M; cin >> M;
	vector<int> H(N);
	for (int i = 0; i < N; ++i)
		cin >> H[i];
	vector<int> A(M), B(M), L(M);
	for (int i = 0; i < M; ++i)
		cin >> A[i] >> B[i] >> L[i];
	cout << illumina(N, M, H, A, B, L) << "\n";
}
#endif
