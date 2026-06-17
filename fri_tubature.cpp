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

int pianifica(int N, int M, int da[], int a[], int C[], int G[]) {
	vector<int> parent(N, -1);
	vector<vector<int>> adj(N);
	vector<bool> b(N);
	for(int i = 0; i < N - 1; i++){
		parent[a[i]] = da[i];
		adj[da[i]].pb(a[i]);
	}
	for(int i = 0; i < M; i++)
		b[C[i]] = true;
	int root = 0;
	while(parent[root] != -1)
		root = parent[root];
	function<int(int)> dfs = [&](int node) -> int{
		if(b[node]) return G[node];
		int temp = 0;
		for(auto x: adj[node])
			temp += dfs(x);
		return min(G[node], temp);
	};
	return dfs(root);
}