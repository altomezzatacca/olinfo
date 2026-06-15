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

int pianifica(int N, int L, vector<vector<int>> F) {
    vector<vector<pii>> adj(N);
	
	for(auto line: F){
		int x = adj.size();
		for(auto f: line)
			adj.pb({});
		for(int i = 0; i < line.size(); i++){
			adj[line[i]].pb({x + i, 1});
			adj[x + i].pb({line[i], 0});
		}
		for(int i = x; i < x + line.size() - 1; i++)
			adj[i].pb({i + 1, 0});
	}

	priority_queue<pii, vector<pii>, greater<>> pq;
	vector<bool> visited(adj.size());
	vector<int> dist(adj.size(), -1);
	pq.push({dist[0] = 0, 0});

	while(!pq.empty()){
		int node = pq.top().ss; pq.pop();
		if(visited[node]) continue; visited[node] = true;
		for(auto [u, w]: adj[node])
			if(dist[u] == -1 || dist[u] > dist[node] + w)
				pq.push({dist[u] = dist[node] + w, u});
	}

	return (dist[N - 1] == -1 ? -1 : dist[N - 1] - 1);
}