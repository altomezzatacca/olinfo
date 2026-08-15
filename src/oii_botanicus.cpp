#include "bits/stdc++.h"
using namespace std;
// quando checko l'altezza x, devo tagliare tutti e soli i nodi con:
// h > x
// max_h (nel sottoalbero) < x

int pota(int N, vector<int> P) {
    int &n = N;
    vector<int> H(n), max_H(n, -1);
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++)
        adj[P[i]].emplace_back(i);
    function <void(int)> dfs = [&] (int node) -> void {
        max_H[node] = H[node];
        for(auto u: adj[node]){
            H[u] = H[node] + 1;
            dfs(u);
            max_H[node] = max(max_H[node], max_H[u]);
        }
    };
    dfs(0);
    vector<int> V(n); // sweep line
    for (int i = 0; i < n; i++) {
        V[H[i]]++; // da qua in poi ho un nodo valido in più
        V[max_H[i] + 1]--; // dal +1 in poi ho un nodo valido in meno
    }
    int ans = 0, cur = 0; // nodi che posso tenere
    for (int h = 0; h < n; h++) {
        cur += V[h];
        ans = max(ans, cur); // massimizzo il numero di nodi che posso tenere
    }
    return n - ans;
}
