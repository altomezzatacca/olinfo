#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    vector<int> visited(n); // 0 -> unvisited, 1 -> black, 2 -> red
    vector<int> parent(n);
    queue<int> q;
    q.push(0);
    parent[0] = -1;
    visited[0] = 1;
    int l, r;
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        for (auto v: adj[u]) {
            int c = visited[u] % 2 + 1;
            if (visited[v] == 0) {
                parent[v] = u;
                visited[v] = c;
                q.push(v);
            } else if (visited[v] == c) {
                continue;
            } else if (visited[v] != c) {
                l = u;
                r = v;
                while (!q.empty()) q.pop();
            }
        }
    }
    vector<int> path;
    while (l != -1) {
        path.emplace_back(l);
        l = parent[l];
    }
    reverse(begin(path), end(path));
    while (r != -1) {
        path.emplace_back(r);
        r = parent[r];
    }
    cout << (int)path.size() - 1 << "\n";
    for(auto u: path) cout << u << " ";
    cout << "\n";
}
