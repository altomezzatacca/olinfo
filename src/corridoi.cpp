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

enum { Move, Query };

vector<ll> dijkstra(int n, int s, const vector<vector<pll>> &adj){
	vector<ll> dist(n, linf);
	vector<bool> visited(n);
	priority_queue<pll, vector<pll>, greater<>> pq;
	dist[s] = 0; pq.push({0, s});
	
	while(!pq.empty()){
		auto [d, node] = pq.top(); pq.pop();
		if(visited[node]) continue; visited[node] = true;
		for(auto [x, w]: adj[node])
			if(dist[x] > d + w) 
				pq.push({dist[x] = d + w, x});
	}
	return dist;
}

vector<long long> shorten(int N, int M, int Q, vector<long long> K, vector<int> A, vector<int> B, vector<int> C) {
    vector<long long> ans(Q, linf);
	vector<vector<pll>> adj(N);
	for(int i = 0; i < M; i++){
		adj[A[i]].pb({B[i], C[i]});
		adj[B[i]].pb({A[i], C[i]});
	}

	vector<ll> d0 = dijkstra(N, 0, adj);
	vector<ll> d1 = dijkstra(N, 1, adj);
	vector<ll> d2 = dijkstra(N, 2, adj);

	vector<pii> events;
	for(int i = 0; i < Q; i++)
		events.pb({Query, i});
	for(int i = 0; i < N; i++)
		events.pb({Move, i});
	sort(events.begin(), events.end(), [&](pii u, pii v){
		auto [type_u, ix_u] = u;
		auto [type_v, ix_v] = v;
		return (type_u == Query ? K[ix_u] : d1[ix_u]) < (type_v == Query ? K[ix_v] : d1[ix_v]);
	});

	multiset<ll> m1, m2;
	m1.insert(linf); m2.insert(linf);
	for(int i = 0; i < N; i++)
		m2.insert(d0[i] + d2[i] + 2 * d1[i]);

	for(auto [type, ix]: events){
		if(type == Query){
			ll q1 = *m1.begin();
			ll q2 = *m2.begin();
			ans[ix] = max((ll)0, min(q1 - K[ix], q2 - 2 * K[ix]));
		} else {
			ll temp = d0[ix] + d2[ix] + 2 * d1[ix];
			m2.erase(m2.find(temp));
			m1.insert(temp - d1[ix]);
		}
	}

    return ans;
}
