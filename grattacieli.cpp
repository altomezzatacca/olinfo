#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
constexpr static int inf = 2e9;
constexpr static ll linf = 1e18;
constexpr static int mod1 = 1e9 + 7;
constexpr static int mod2 = 998244353;

long long costruisci(int N, int M, vector<long long>& H, vector<int>& A, vector<int>& B, vector<int>& C) {
    vector<ll> dist(N);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	for(int i = 0; i < N; i++)
		pq.push({dist[i] = H[i], i});
	vector<vector<pii>> adj(M);
	for(int i = 0; i < M; i++)
		adj[A[i]].pb({B[i], C[i]});
	vector<bool> visited(N);
	while(!pq.empty()){
		auto [d, a] = pq.top(); pq.pop();
		if(visited[a]) continue; visited[a] = true;
		for(auto [b, c]: adj[a])
			if(dist[b] > dist[a] + c)
				pq.push({dist[b] = dist[a] + c, b});
	}
	ll ans = 0;
	for(auto u: dist) ans += u;
	return ans;
}