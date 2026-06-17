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

int main() {
//  ifstream cin("input.txt");

	int N, L; cin >> N >> L;
	vector<pii> V(N);
	for(auto &[pag, en]: V){
		cin >> pag >> en;
		if (en == -1) en = L;
	}
	sort(V.rbegin(), V.rend());
	set<int> S;

	for(int i = 0; i < L; i++)
		S.insert(i);
	
	ll ans = 0;
	for(auto [pag, en]: V){
		if(S.empty()) break;
		auto it = S.upper_bound(en);
		if(it == S.begin()) continue;
		it--;
		S.erase(it);
		ans += pag;
	}

    cout << ans << endl;
    return 0;
}
