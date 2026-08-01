#include <bits/stdc++.h>
using namespace std;

void solve(int t){
    int N, M, K; cin >> N >> M >> K;
    vector<vector<int>> adj(N);
    vector<long long> pet(N, -1);
    queue<pair<int, int>> q;
    for(int i = 0; i < K; i++){
        int k; cin >> k;
        pet[k] = i;
        q.emplace(i, k);
    }
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    while(!q.empty()){
        auto [p, u] = q.front(); q.pop();
        for(auto v: adj[u]){
            if(pet[v] != -1) continue;
            q.emplace(pet[v] = pet[u], v);
        }
    }
    long long ans = 0;
    for(int i = 0; i < N; i++)
        ans += pet[i] * (long long)(i + 1LL);
    cout << "Case #" << t << ": ";
    cout << ans << endl;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T; cin >> T;
    for(int t = 1; t <= T; t++)
        solve(t);
}