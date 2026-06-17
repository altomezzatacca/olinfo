#include <bits/stdc++.h>
using namespace std;
constexpr static long long INF = 1e15;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N, M;
    cin >> N >> M;
    vector<int> x(M), y(M), we(M);
    for (int i = 0; i < M; ++i)
        cin >> x[i] >> y[i] >> we[i];
    for(int i = 0; i < M; i++){
        x[i]--;
        y[i]--;
    }
    long long L = 0, K = 0;
    vector<vector<pair<int, long long>>> adj(N);
    for(int i = 0; i < M; i++){
        adj[x[i]].emplace_back(y[i], we[i]);
        adj[y[i]].emplace_back(x[i], we[i]);
    }
    vector<long long> dist (N, INF);
    dist[N - 1] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.emplace(0, N - 1);
    while(!pq.empty()){
        auto [w, u] = pq.top(); pq.pop();
        if(w > dist[u]) continue;
        for(auto [v, ww]: adj[u])
            if(w + ww < dist[v])
                pq.emplace(dist[v] = w + ww, v);
    }
    vector<vector<pair<int, long long>>> adj1(N); //entranti
    for(int i = 0; i < M; i++){
        int X = x[i], Y = y[i], W = we[i];
        if(dist[X] > dist[Y])
            adj1[Y].emplace_back(X, W);
        else if (dist[X] < dist[Y])
            adj1[X].emplace_back(Y, W);
    }
    vector<pair<long long, int>> order;
    for(int i = 0; i < N; i++)
        order.emplace_back(dist[i], i);
    sort(order.begin(), order.end());
    vector<long long> dp(N);
    vector<int> parent(N, -1);
    parent[N - 1] = -1;
    for(auto [x, u]: order)
        for(auto [v, w]: adj1[u])
            if(dp[v] < dp[u] + w){
                dp[v] = dp[u] + w;
                parent[v] = u;
            }
    int best = N - 1;
    for(int i = 0; i < N; i++)
        if(dp[best] < dp[i]) best = i;
    vector<int> ans;
    L = dp[best];
    while (best != -1){
        ans.emplace_back(best);
        best = parent[best];
    }
    K = ans.size();
    cout << L << " " << K << "\n";
    for(auto u: ans) cout << u + 1 << " ";

    return 0;
}