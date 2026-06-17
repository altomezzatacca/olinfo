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

int alzati(int N, int M, int X[], int Y[]) {

	auto dst = [&](int a, int b){
		if(a == b) return 0;

		if(a == M && b == M + 1) return inf;
		if(a == M + 1 && b == M) return inf;

		if(a == M) return min(Y[b], N - X[b] - 1);
		if(b == M) return min(Y[a], N - X[a] - 1);

		if(a == M + 1) return min(X[b], N - Y[b] - 1);
		if(b == M + 1) return min(X[a], N - Y[a] - 1);

		if(X[a] == X[b]) return abs(Y[a] - Y[b]) / 2;
		if(Y[a] == Y[b]) return abs(X[a] - X[b]) / 2;

		return (abs(X[a] - X[b]) + abs(Y[a] - Y[b]) - 1) / 2;
	};

	vector<int> dist(M + 2, inf);
	vector<bool> visited(M + 2);
	dist[M] = 0;
	while(true){
		pii m = {inf, -1};
		for(int i = 0; i < M + 2; i++)
			if(!visited[i])
				m = min(m, {dist[i], i});
		if(m.ss == -1) break; visited[m.ss] = true;
		for(int i = 0; i < M + 2; i++)
			dist[i] = min(dist[i], max(m.ff, dst(m.ss, i)));
	}
	return dist[M + 1] - 1;
}