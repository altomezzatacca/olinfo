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

struct arco{
	int dest, a, b;
};

int raggiungi(int N, int M, int A[], int B[], int inizio[], int fine[]) {
	vector<int> t(N, inf);
	vector<vector<arco>> adj(N);
	for(int i = 0; i < M; i++){
		adj[A[i]].pb({B[i], inizio[i], fine[i]});
		adj[B[i]].pb({A[i], inizio[i], fine[i]});
	}
	priority_queue<pii, vector<pii>, greater<>> pq;
	pq.push({t[0] = 0, 0});
	while(!pq.empty()){
		auto [tx, node] = pq.top(); pq.pop();
		if(tx > t[node]) continue;
		for(auto [dest, st, en]: adj[node]){
			if(tx >= en) continue;
			if(t[dest] > max(tx, st) + 1) pq.push({t[dest] = max(tx, st) + 1, dest});
		}
	}
	return (t[N - 1] == inf ? -1 : t[N - 1]);
}