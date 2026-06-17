#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
constexpr static int inf = 1e9;
constexpr static ll linf = 1e15;
constexpr static int mod = 1e9 + 7;

int main() {
    ifstream cin("input.txt");
    // ofstream cout("output.txt");
    int N; cin >> N;
    vector<int> K(N);
    for (int i = 0; i < N; ++i)
        cin >> K[i];
    vector<int> P(N, -1);
    for (int i = 1; i < N; ++i)
        cin >> P[i];
    vector<ll> W(N);
    for (int i = 1; i < N; ++i)
        cin >> W[i];

    vector<vector<int>> adj(N);
    vector<int> visited(N);
    vector<int> topos;
    for(int i = 1; i < N; i++) //popolo l'adj senza mettere il padre per ogni nodo
        adj[P[i]].pb(i);
    function<void(int)> dfs;
    dfs = [&](int node) -> void{
        visited[node] = 1;
        for(auto u: adj[node])
            if(!visited[u])
                dfs(u);
        topos.emplace_back(node);
    };
    dfs(0);
    for(int i = 0; i < N; i++)
        if(!visited[i]) dfs(i);

    vector<ll> dp_A(N), dp_B(N); // valore del sottoalbero con o senza padre
    for(auto node: topos){
        ll temp = 0;
        for(auto u: adj[node]) temp += dp_A[u]; //nessun nodo connesso
        priority_queue<ll> pq;
        for(auto u: adj[node]) pq.push(dp_B[u] - dp_A[u]);
        int rem = K[node] - 1;
        while(rem > 0){
            if(pq.empty()) break;
            if(pq.top() <= 0) break;
            rem--;
            temp += pq.top();
            pq.pop();
        }
        dp_A[node] = dp_B[node] = temp;
        if(K[node] && !pq.empty() && pq.top() > 0) dp_A[node] += pq.top();
        if(K[node]) dp_B[node] += W[node];
    }

    cout << dp_A[0] << endl;
    return 0;
}