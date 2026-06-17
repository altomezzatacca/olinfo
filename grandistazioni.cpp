#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlll;
constexpr static int inf = 2e9;
constexpr static ll linf = 1e18;
constexpr static int mod1 = 1e9 + 7;
constexpr static int mod2 = 998244353;

struct DSU {
    vector<int> V;
    DSU(int size) : V(size, -1) { }

    int find(int node) {
        if (V[node] == -1) return node;
        return V[node] = find(V[node]);
    }

    void join(int u, int v) {
        V[u] = v;
    }
};

long long viaggia(int N, int M, vector<int> A, vector<int> B, vector<int> T, vector<int> V, vector<int> W) {
	vector<vector<pii>> adj(N);
	for(int i = 0; i < M; i++)
		adj[B[i]].pb({A[i], T[i]});
	vector<ll> nxt(N, -1), dst(N, linf);
	priority_queue<tlll, vector<tlll>, greater<tlll>> pq;
	pq.push({dst[N - 1] = 0, -1, N - 1});
	while(!pq.empty()){
		auto [d, p, node] = pq.top(); pq.pop();
		if(nxt[node] != -1) continue;
		nxt[node] = p;
		for(auto [x, w]: adj[node])
			if(dst[x] > d + w)
				pq.push({dst[x] = d + w, node, x});
	}
	ll ans = 0, node = 0;
	DSU dsu(N);
	while(node != N - 1){
		int j = dsu.find(node);
		ans += dst[node] - dst[j];
		node = j;
		if(j != N - 1 && V[j] != -1){
			ans += W[j];
			node = V[j];
		}
		if(j != N - 1)
			dsu.join(j, nxt[j]);
	}

	return ans;
}