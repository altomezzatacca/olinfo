#include "bits/stdc++.h"
using namespace std;
using ll = long long;
constexpr static ll inf = 1e17;

void brucia(int N, vector<int> &M, vector<int> &B, vector<long long> &T) {
    int &n = N;
    vector<array<int, 3>> sweep;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < n; i++)
        sweep.push_back({M[i], 0, i}), // accensione
        sweep.push_back({B[i], 1, i}); // fine
    auto comp1 = [&] (array<int, 3> a, array<int, 3> b) -> bool {
        return make_tuple(a[0], a[1], a[2]) < make_tuple(b[0], b[1], b[2]);
    };
    auto comp2 = [&] (array<int, 3> a, array<int, 3> b) -> bool {
        return make_tuple(-a[0], a[1], a[2]) < make_tuple(-b[0], b[1], b[2]);
    };
    sort(begin(sweep), end(sweep), comp1);
    set<pair<int, int>> active;
    for (auto [pos, type, i]: sweep) {
        if (type == 0) {
            if (!active.empty()) {
                auto [tmp, ix] = *active.rbegin();
                adj[ix].emplace_back(i, abs(M[i] - M[ix]));
            }
            if (B[i] > M[i])
                active.insert({pos, i});
        } else {
            active.erase({M[i], i});
        }
    }
    active.clear();
    sort(begin(sweep), end(sweep), comp2);
    for (auto [pos, type, i]: sweep) {
        if (type == 0) {
            if (!active.empty()) {
                auto [tmp, ix] = *active.begin();
                adj[ix].emplace_back(i, abs(M[i] - M[ix]));
            }
            if (B[i] < M[i])
                active.insert({pos, i});
        } else {
            active.erase({M[i], i});
        }
    }
    active.clear();
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    for (auto &u: T) u = inf;
    pq.emplace(T[0] = 0, 0);
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > T[u]) continue;
        for (auto [v, w]: adj[u])
            if (T[v] > T[u] + w)
                pq.emplace(T[v] = T[u] + w, v);
    }
    for (auto &u: T)
        if (u == inf)
            u = -1;
}
