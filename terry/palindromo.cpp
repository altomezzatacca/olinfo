#include <bits/stdc++.h>
using namespace std;

void solve(int t) {
    int N, M, X, Y;
    cin >> N >> M;
    cin >> X >> Y;
    if(X == Y){
        cout << "Case #" << t << ": " << 0 << "\n";
        return;
    }
    vector<int> A(M), B(M);
    vector<char> L(M);
    vector<vector<pair<int, char>>> adj(N);
    for (int i = 0; i < M; adj[A[i]].emplace_back(B[i], L[i]), adj[B[i]].emplace_back(A[i], L[i]), i++) 
        cin >> A[i] >> B[i] >> L[i];
    int risposta = 1e9;
    queue<pair<pair<int, int>, int>> q;
    vector<bool> visited(N * N);
    q.push({{X, Y}, 0});
    while(!q.empty()){
        auto [p, d] = q.front(); q.pop();
        auto [u, v] = p;
        for(int i = 0; i < (int)adj[u].size(); i++)
            if(adj[u][i].first == v)
                risposta = min(risposta, d + 1);
        if(u == v) risposta = min(risposta, d);
        if(visited[u * N + v]) continue;
        visited[u * N + v] = 1;
        for(auto [uu, l1]: adj[u])
            for(auto [vv, l2]: adj[v])
                if(l1 == l2)
                    q.push({{uu, vv}, d + 2});
    }
    cout << "Case #" << t << ": " << (risposta != 1e9 ? risposta : -1) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
        solve(t);
    return 0;
}