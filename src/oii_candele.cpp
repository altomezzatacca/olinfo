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

struct Event{
	int ix, type, i;
};

enum { Start, End };

void brucia(int N, vector<int> &M, vector<int> &B, vector<long long> &T) {
	vector<Event> events;
	vector<vector<pii>> adj(N);
	for(int i = 0; i < N; i++){
		events.pb({M[i], Start, i});
		events.pb({B[i], End, i});
	}
	
	sort(events.begin(), events.end(), [](Event a, Event b){
		return make_tuple(a.ix, a.type, a.i) < make_tuple(b.ix, b.type, b.i);
	});
	set<pii> active;
	for(auto [ix, type, i]: events){
		if(type == Start){
			if(!active.empty()){
				auto [x, idx] = *active.rbegin();
				adj[idx].pb({i, abs(ix - x)});
			}
			if(B[i] > M[i])
				active.insert({ix, i});
		} else{
			active.erase({M[i], i});
		}
	}
	
	sort(events.begin(), events.end(), [](Event a, Event b){
		return make_tuple(-a.ix, a.type, a.i) < make_tuple(-b.ix, b.type, b.i);
	});
	for(auto [ix, type, i]: events){
		if(type == Start){
			if(!active.empty()){
				auto [x, idx] = *active.begin();
				adj[idx].pb({i, abs(ix - x)});
			}
			if(B[i] < M[i])
				active.insert({ix, i});
		} else{
			active.erase({M[i], i});
		}
	}

	vector<bool> visited(N);
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	for(int i = 0; i < N; i++) T[i] = linf;
	pq.push({T[0] = 0, 0});
	
	while(!pq.empty()){
		auto [t, node] = pq.top(); pq.pop();
		if(visited[node]) continue; visited[node] = true;
		for(auto [x, w]: adj[node])
			if(T[x] > t + w)
				pq.push({T[x] = t + w, x});
	}
	for(auto &x: T) if(x == linf) x = -1;
}