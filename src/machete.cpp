#include "bits/stdc++.h"
using namespace std;
vector<int> parent, h, s;
vector<vector<int>> adj;
vector<int> toposort;
vector<bool> visited;
set<int> ok;

void dfs(int node){
    if(visited[node]) return;
    visited[node] = 1;
    for(auto u: adj[node])
        if(!visited[u]){
            h[u] = h[node] + 1;
            dfs(u);
        }
    toposort.emplace_back(node);
}

int machete(int N, int K, vector<int> P) {
    int ans = 0;
    parent = P;
    visited.resize(N);
    h.resize(N); fill(begin(h), end(h), 1); // distanza dalla radice + 1
    s.resize(N); fill(begin(s), end(s), 1); // distanza della foglia più profonda nel sottoalbero
    adj.resize(N);
    for(int i = 0; i < N; i++){
        if(parent[i] == -1) continue;
        adj[parent[i]].emplace_back(i);
    }
    dfs(0);
    for(int i = 0; i < N; i++)
        s[i] = h[i];
    for(auto u: toposort){
        if(u == 0) continue;
        for(auto v: adj[u]) s[u] = max(s[u], s[v]); // ahaha sus
        if(s[u] - h[u] + 1 == K - 1 && parent[u] != 0){ // il sottoalbero ha raggiunto altezza K - 1 -> attacco alla radice
            ans++;
            s[u] = -1;
        }
    }
    return ans;
}

#ifndef EVAL
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    for(auto &i : P) cin >> i;
    cout << machete(N, K, P) << endl;
}
#endif