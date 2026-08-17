#include "bits/stdc++.h"
using namespace std;
using ll = long long;
constexpr static ll inf = 1e16;

long long fuggi(int N, int M, vector <int> A, vector <int> B, vector <int> T, vector <int> R){
	int &n = N, &m = M;
    vector<vector<array<ll, 3>>> flip(n); // adj[a] = {b, t, r}
    for (int i = 0; i < m; i++) {
        ll a = A[i], b = B[i], t = T[i];
        bool r = R[i];
        flip[b].push_back({a, t, r});
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    vector<ll> dist(n, inf);
    vector<ll> blue(n, inf), red(n, inf);
    dist[n - 1] = 0;
    pq.emplace(0, n - 1);
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (dist[u] < d) continue;
        for (auto [v, t, r]: flip[u]) {
            if (r)
                red[v] = min(red[v], t + dist[u]);
            else
                blue[v] = min(blue[v], t + dist[u]);
            ll c = max(blue[v] - 1, min(blue[v], red[v])); // il poliziotto massimizza e sceglie se spegnere o meno
            if (dist[v] > c)
                pq.emplace(dist[v] = c, v);
        }
    }
    return dist[0];
}
