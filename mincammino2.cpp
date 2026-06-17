#include <bits/stdc++.h>
using namespace std;
constexpr static long long INF = 1e15;

void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int> P, vector<long long>& D) {
    vector<vector<pair<int, long long>>> adj(N);
    for(int i = 0; i < M; i++)
        adj[X[i]].emplace_back(Y[i], P[i]);
    fill(D.begin(), D.end(), INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.emplace(0, 0); D[0] = 0;
    while(!pq.empty()){
        auto [dist, node] = pq.top(); pq.pop();
        if (dist > D[node]) continue;
        for(auto [u, w]: adj[node])
            if(dist + w < D[u])
                pq.emplace(D[u] = dist + w, u);
    }
    for(int i = 0; i < N; i++)
        if(D[i] == INF) D[i] = -1;
}