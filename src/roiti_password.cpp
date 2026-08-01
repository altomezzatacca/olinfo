#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
constexpr static int mod = 1e9+7;

int main(){
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int N; cin >> N;
	ll K; cin >> K;
	ll rad = sqrt(K);
	ll ans = 0;
	vector <ll> A;
	vector <ll> B(rad + 2, 0);
	
	for(int i = 0; i < N; i++){
		ll x; cin >> x;
		if(x > rad) A.push_back(x);
		else B[x]++;
	}
	
	for(auto u: A){
		if(K%u == 0) ans += B[K/u];
		ans %= mod;
	}
	
	if(1LL * rad * rad == K) ans += 1LL*B[rad]*(B[rad]-1)/2;
	ans %= mod;
	
	cout << ans;
	
	return 0;
}