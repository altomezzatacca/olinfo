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
    DSU(int size) : V(size) {
		iota(V.begin(), V.end(), 0); // V[i] = i
	}

    int find(int node) {
        if (V[node] != node) V[node] = find(V[node]);
        return V[node];
    }

    void join(int u, int v) {
		u = find(u);
		v = find(v);
        V[u] = v;
    }
};

ll mod_pow(ll b, ll e){
	if (e == 0) return 1ll;
    if (e & 1) return (b * mod_pow(b, e - 1)) % mod1;
    ll res = mod_pow(b, e / 2ll);
    return (res * res) % mod1;
}

int main(){
	freopen("input.txt", "r", stdin);
	int R, C, N;
	cin >> R >> C >> N;
	vector<tiii> G(N); //riga, colonna, indice
	for(int i = 0; i < N; i++){
		int r, c; cin >> r >> c;
		G[i] = {r, c, i};
	}
	DSU dsu(N);
	sort(G.begin(), G.end(), [](tiii a, tiii b){
		return get<0>(a) < get<0>(b);});
	for(int i = 0; i < N - 1; i++){
		auto [r1, c1, i1] = G[i];
		auto [r2, c2, i2] = G[i + 1];
		if(r1 == r2 && dsu.find(i1) != dsu.find(i2)) dsu.join(i1, i2);
	}
	sort(G.begin(), G.end(), [](tiii a, tiii b){
		return get<1>(a) < get<1>(b);});
	for(int i = 0; i < N - 1; i++){
		auto [r1, c1, i1] = G[i];
		auto [r2, c2, i2] = G[i + 1];
		if(c1 == c2 && dsu.find(i1) != dsu.find(i2)) dsu.join(i1, i2);
	}
	sort(G.begin(), G.end(), [](tiii a, tiii b){
		return (get<0>(a) + get<1>(a)) < (get<0>(b) + get<1>(b));});
	for(int i = 0; i < N - 1; i++){
		auto [r1, c1, i1] = G[i];
		auto [r2, c2, i2] = G[i + 1];
		if(r1 + c1 == r2 + c2 && dsu.find(i1) != dsu.find(i2)) dsu.join(i1, i2);
	}
	sort(G.begin(), G.end(), [](tiii a, tiii b){
		return (get<0>(a) - get<1>(a)) < (get<0>(b) - get<1>(b));});
	for(int i = 0; i < N - 1; i++){
		auto [r1, c1, i1] = G[i];
		auto [r2, c2, i2] = G[i + 1];
		if(r1 - c1 == r2 - c2 && dsu.find(i1) != dsu.find(i2)) dsu.join(i1, i2);
	}
	int x = 0;
	for(int i = 0; i < N; i++)
		if(dsu.find(i) == i) x++;
	cout << mod_pow(2, x);
	return 0;
}