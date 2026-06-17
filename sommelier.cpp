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

ll solve(){
	int n; cin >> n;
	vector<int> V(n); for(auto &u: V) cin >> u;
	vector<int> dp(n, 1);
	for(int i = 2; i < n; i++)
		for(int j = 0; j < i - 1; j++)
			if(V[i] >= V[j])
				dp[i] = max(dp[i], dp[j] + 1);
   	return *max_element(dp.begin(), dp.end());
}
    
int main(){
    
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
   	ios::sync_with_stdio(false);
    cin.tie(nullptr);
   	cout.tie(nullptr);
   	
   	int t = 1;
   		
	while(t--) cout << solve();

	return 0;
}