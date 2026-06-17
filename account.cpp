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

int chiedi(int K);
void rispondi(string S);

void indovina(int N) {
	string S(N, 'a');
	int ix = N * (N + 1) / 2;
	for(int i = N - 1; i > 0; i--){
		int x = chiedi(ix);
		S[N - x] = 'a' + i;
		ix -= x;
	}
	rispondi(S);
	return;
}