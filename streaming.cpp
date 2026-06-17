#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

long long bfs(int N, long long K, vector<int> P, vector<int> F) {

	vector<pll> V(N);
	for(int i = 0; i < N; i++)
		V[i] = {P[i], F[i]};

	sort(V.rbegin(), V.rend());

	ll spesa = 0, ans = 0;
	priority_queue<ll> pq;

	for(auto [p, f]: V){
		spesa += f;
		pq.push(f);
		
		if(spesa > K) {
			spesa -= pq.top();
			pq.pop();
		}
		while(!pq.empty() && pq.top() > p){
			spesa -= pq.top();
			pq.pop();
		}
		ans = max(ans, (ll)pq.size() * p - spesa);
	}

	return ans;
}