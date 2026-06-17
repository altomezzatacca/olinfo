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

bool test(string T);

string analizza(int N) {
	int l = 0, r = N + 1;
	while(r - l > 1){
		int m = (l + r) >> 1;
		if (test(string(m, '0'))) l = m;
		else r = m;
	}

	if (l == 0) return string(N, '1');
	string S(l, '0');
	int last_0 = l;

	while(S.size() < N){
		if (test(S + '1')){
			S += '1';
			last_0 = 0;
		}
		else {
			S += '0';
			last_0++;
		}
		if(last_0 > l) break;
	}
	for(; last_0--;)
		S.pop_back();
	while(test(S + '0'))
		S += '0';
	
	if(S.size() == N) return S;
	S = '1' + S;
	while(S.size() < N){
		if(test('0' + S)) S = '0' + S;
		else S = '1' + S;
	}
	return S;
}